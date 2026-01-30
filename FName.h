// Current Patch: v39.30

int32_t DecryptIndex(int32_t Index)
{
    if (Index == 0)
        return 0;
    
    constexpr uint32_t IndexXorKey = 0x408CE8FF;
    
    uint32_t Value = (Index - 1) ^ IndexXorKey;
    Value = (Value << 18) | (Value >> 14);
    
    int32_t Result = 0x5C0B8A4D;
    if (Value)
        Result = Value;
    
    return Result + 1;
}

std::string GetNameFromFName(int32_t Index)
{
    constexpr uint64_t GNamesRva = 0x1777E080;
    constexpr uint32_t ChunkOffset = 2;
    constexpr uint32_t RedirectMarker = 112u;
    constexpr uint32_t LengthXorKey = 0x70;
    constexpr uint32_t MaxNameLength = 1024;
    
    int32_t DecryptedIndex = DecryptIndex(Index);
    int32_t Retries = 0;
    
    while (true)
    {
        if (DecryptedIndex <= 0 || Retries > 5)
            return "";
        
        const uint32_t ChunkIndex = static_cast<uint32_t>(DecryptedIndex) >> 16;
        const uint16_t NameEntryIndex = static_cast<uint16_t>(DecryptedIndex);
        
        const uint64_t GNamesAddress = Memory.ModuleBase + GNamesRva;
        const uint64_t ChunkPointerAddress = GNamesAddress + 8ull * (ChunkIndex + ChunkOffset);
        const uint64_t ChunkPointer = Read<uint64_t>(ChunkPointerAddress);
        
        if (!ChunkPointer)
            return "";
        
        const uint64_t EntryAddress = ChunkPointer + 2ull * NameEntryIndex;
        const uint16_t Header = Read<uint16_t>(EntryAddress);
        
        if (static_cast<int16_t>(Header) < 0)
            return "";
        
        const uint16_t RawLength = Header & 0x3FF;
        
        if (RawLength == RedirectMarker)
        {
            const int32_t NewIndexEncoded = Read<int32_t>(EntryAddress + 6);
            DecryptedIndex = DecryptIndex(NewIndexEncoded);
            Retries++;
            continue;
        }
        
        const uint16_t Length = RawLength ^ LengthXorKey;
        
        if (Length <= 0 || Length > MaxNameLength)
            return "";
        
        std::vector<uint8_t> Buffer(Length);
        Driver::ReadPhysicalMemory(EntryAddress + 2, Buffer.data(), Length);
        
        // Decrypt buffer
        std::string Result(Length, '\0');
        uint8_t Key = (uint8_t)(-31 * Length - 120);
        uint16_t BaseOffset = (uint16_t)(24319 - 6431 * Length);
        
        for (uint16_t i = 0; i < Length; i++)
        {
            uint32_t ReadIdx = (BaseOffset + i) % Length;
            uint8_t Xored = Buffer[ReadIdx] ^ Key;
            Result[i] = (Xored << 5) | (Xored >> 3);
        }
        
        return Result;
    }
}