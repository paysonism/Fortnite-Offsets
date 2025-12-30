int32_t DecryptIndex(int32_t Index)
{
    if (Index == 0)
        return 0;

    constexpr uint32_t IndexXorKey = 0xF54D6F37;
    constexpr int32_t ZeroResultValue = 0xAB290C9;

    uint32_t Value = (Index - 1) ^ IndexXorKey;

    if (Value == 0)
        return ZeroResultValue;

    return Value + 1;
}

std::string GetNameFromFName(int32_t Index)
{
    constexpr uint64_t GNamesRva = 0x17483F80;
    constexpr uint32_t ChunkOffset = 0xDF2;
    constexpr uint32_t RedirectMarker = 143u;
    constexpr uint32_t LengthXorKey = 0x8Fu;
    constexpr uint32_t MaxNameLength = 1024;

    int32_t DecryptedIndex = DecryptIndex(Index);

    while (true)
    {
        if (DecryptedIndex <= 0)
            return "";

        const uint32_t ChunkIndex = static_cast<uint32_t>(DecryptedIndex) >> 16;
        const uint16_t NameEntryIndex = static_cast<uint16_t>(DecryptedIndex);

        const uint64_t GNamesAddress = Memory.ModuleBase + GNamesRva;
        const uint64_t ChunkPointer = Read<uint64_t>(GNamesAddress + 8ull * (ChunkIndex + ChunkOffset));

        if (!ChunkPointer)
            return "";

        const uint64_t EntryAddress = ChunkPointer + 2ull * NameEntryIndex;
        const uint16_t Header = Read<uint16_t>(EntryAddress);
        const uint32_t RawLength = (Header >> 1) & 0x3FFu;

        if (RawLength == RedirectMarker)
        {
            const int32_t NewIndexEncoded = Read<int32_t>(EntryAddress + 2);
            DecryptedIndex = DecryptIndex(NewIndexEncoded);
            continue;
        }

        const uint32_t Length = RawLength ^ LengthXorKey;

        if (Length == 0 || Length > MaxNameLength)
            return "";

        const bool IsWideMode = (Header & 1) != 0;

        std::vector<uint16_t> WideBuffer(Length + 1);
        uint8_t* const OutputBytes = reinterpret_cast<uint8_t*>(WideBuffer.data());

        if (IsWideMode)
        {
            const uint32_t TotalBytes = 2u * Length;

            std::vector<uint8_t> EncryptedData(TotalBytes);
            Driver::ReadPhysicalMemory(EntryAddress + 2, EncryptedData.data(), TotalBytes);

            int32_t Seed = Length;
            const uint32_t Count = (TotalBytes == 0 ? 1u : TotalBytes);

            for (uint32_t i = 0; i < Count; ++i)
            {
                const uint8_t EncryptedByte = EncryptedData[i];
                OutputBytes[i] = static_cast<uint8_t>(120 * Seed + ~EncryptedByte - 127);
                Seed = -8840 * Seed - 28583984;
            }

            WideBuffer[Length] = 0;
        }
        else
        {
            std::vector<uint8_t> EncryptedData(Length);
            Driver::ReadPhysicalMemory(EntryAddress + 2, EncryptedData.data(), Length);

            std::vector<uint8_t> TempBuffer(Length + 1);

            int32_t Seed = Length;

            for (uint32_t i = 0; i < Length; ++i)
            {
                const uint8_t EncryptedByte = EncryptedData[i];
                TempBuffer[i] = static_cast<uint8_t>(120 * Seed + ~EncryptedByte - 127);
                Seed = -8840 * Seed - 28583984;
            }

            TempBuffer[Length] = 0;

            for (uint32_t i = 0; i <= Length; ++i)
            {
                WideBuffer[i] = TempBuffer[i];
            }
        }

        std::string Result;
        Result.reserve(Length);

        for (uint32_t i = 0; i < Length; ++i)
        {
            char Character = static_cast<char>(WideBuffer[i] & 0xFF);
            if (Character == '\0')
                break;
            Result.push_back(Character);
        }

        return Result;
    }
}