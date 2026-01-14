int32_t DecryptIndex(int32_t Index)
{
    if (Index == 0)
        return 0;
    
    constexpr uint32_t IndexXorKey = 0xA426EB57;
    constexpr int32_t ZeroResultValue = 0x5BD914A9;
    
    int32_t Value = ((Index - 1) ^ IndexXorKey) + 1;
    
    if (Value == 0)
        return ZeroResultValue;
    
    return Value;
}

std::string GetNameFromFName(int32_t Index)
{
    constexpr uint64_t GNamesRva = 0x17A50D00;
    constexpr uint32_t ChunkOffset = 0xDF2;
    constexpr uint32_t RedirectMarker = 1019u;
    constexpr uint32_t LengthXorKey = 0x3FB;
    constexpr uint32_t MaxNameLength = 1024;
    
    int32_t DecryptedIndex = DecryptIndex(Index);
    
    while (true)
    {
        if (DecryptedIndex <= 0)
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
        
        const int32_t RawLength = (Header >> 1) & 0x3FF;
        
        if (RawLength == RedirectMarker)
        {
            const int32_t NewIndexEncoded = Read<int32_t>(EntryAddress + 6);
            DecryptedIndex = DecryptIndex(NewIndexEncoded);
            
            if (DecryptedIndex == -1)
                return "";
            
            continue;
        }
        
        const int32_t Length = RawLength ^ LengthXorKey;
        
        if (Length <= 0 || Length > MaxNameLength)
            return "";
        
        std::vector<uint8_t> Buffer(Length);
        Driver::ReadPhysicalMemory(EntryAddress + 2, Buffer.data(), Length);
        
        int32_t Key = 8312 * Length + 1055325479;
        
        for (int32_t i = 0; i < Length; ++i)
        {
            Buffer[i] = Buffer[i] ^ (Key + 14);
            Key = 8312 * Key + 1055325479;
        }
        
        return std::string(Buffer.begin(), Buffer.end());
    }
}
