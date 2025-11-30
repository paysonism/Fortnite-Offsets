// Current Patch: v39.00

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
            DecryptFName(nameBuffer.data(), length);
 
        return std::string(nameBuffer.data(), length);
    }
 
private:
    int32_t DecryptIndex(int32_t index) {
        if (index == 0) return 0;
 
        uint32_t value = (index - 1) ^ 0xA9BCB8A7;
        if (value == 0xFFFFFFFF) return 0x56434319;
        return value + 1;
    }
 
    void DecryptFName(char* buffer, int32_t length) {
        if (length <= 0) return;
 
        std::vector<uint8_t> temp(buffer, buffer + length);
 
        uint32_t len = static_cast<uint32_t>(length);
        uint32_t v4 = len;
 
        uint8_t xor_key = static_cast<uint8_t>((89 * v4 + 32) & 0xFF);
 
        uint16_t magic = static_cast<uint16_t>(19545 * v4 + 21478);
 
        for (uint32_t v5 = 0; v5 < len; ++v5) {
            uint32_t source_index = (magic + v5) % v4;
            buffer[v5] = xor_key ^ temp[source_index];
        }
    }
};