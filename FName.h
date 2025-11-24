// Current Patch: v38.11

class FName
{
public:
    int32_t ComparisonIndex;
    uint8_t pad[0x8]{};
 
    std::string ToString() const
    {
        return ToString(ComparisonIndex);
    }
 
    static std::string ToString(int32_t comparisonIndex)
    {
        if (comparisonIndex == 0)
            return "None";
 
        int32_t decryptedIndex = DecryptIndex(comparisonIndex);
        if (decryptedIndex <= 0)
            return "None";
 
    ResolveAddress:
        uint32_t chunkIndex = decryptedIndex >> 16;
        uint16_t nameEntryIndex = static_cast<uint16_t>(decryptedIndex);
 
        uintptr_t gnames_addr = kernel->BaseAddress + 0x172BCD80;
        uint64_t chunkPtr = kernel->read_t<uint64_t>(gnames_addr + 8 * (chunkIndex + 0xDF2));
        if (!chunkPtr)
            return "None";
 
        uint64_t entryPtr = chunkPtr + 2 * nameEntryIndex;
        uint16_t header = kernel->read_t<uint16_t>(entryPtr);
 
        if ((header & 0x3FF) == 650)
        {
            int32_t redirectIndex = kernel->read_t<int32_t>(entryPtr + 6);
            decryptedIndex = DecryptIndex(redirectIndex);
            goto ResolveAddress;
        }
 
        int32_t length = (header & 0x3FF) ^ 0x28A;
        if (length <= 0 || length > 1024)
            return "None";
 
        std::vector<char> nameBuffer(length);
        kernel->read_array(entryPtr + 2, nameBuffer.data(), length);
        DecryptName(nameBuffer.data(), length);
 
        return std::string(nameBuffer.data(), length);
    }
 
private:
    static int32_t DecryptIndex(int32_t index)
    {
        if (index == 0)
            return 0;
 
        uint32_t temp = static_cast<uint32_t>(index - 1) ^ 0x7ADEE523;
        uint32_t v3 = _rotl(temp, 20) + 1;
 
        uint32_t v4 = 0xADD8C492; // -1379380718
        if (v3 != 0)
            v4 = v3;
 
        return static_cast<int32_t>(v4);
    }
 
    static void DecryptFName(char* buffer, int32_t length)
    {
        if (length <= 0 || length > 1024)
            return;
 
        std::vector<uint8_t> temp(buffer, buffer + length);
 
        int32_t key = (8517 * length + 596447118) ^ (8 * length);
 
        for (int32_t i = 0; i < length; ++i)
        {
            uint8_t encrypted = static_cast<uint8_t>(temp[i]);
            uint8_t xored = static_cast<uint8_t>(key ^ encrypted);
            buffer[i] = static_cast<char>(_rotr8(xored, 1)); // Rotate Right 1
 
            key = (8517 * key + 596447118) ^ (8 * key);
        }
    }
};