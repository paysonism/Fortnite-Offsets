// Current Patch: v39.10

int32_t DecryptIndex(int32_t index) {
    if (index == 0) return 0;
 
    uint32_t value = (index - 1) ^ 0x3CCEE46E; // 0x3CCEE46E
    if (value == 0xFFFFFFFF) return 0xC3311B92; // 0xC3311B92
    return value + 1;
}
 
void DecryptFName(char* buffer, int32_t length) {
    if (length <= 0) return;
 
    std::vector<uint8_t> temp(buffer, buffer + length);
 
    uint32_t len = static_cast<uint32_t>(length);
    uint32_t v4 = len;
 
    uint8_t xor_key = static_cast<uint8_t>((225 * v4 + 98) & 0xFF); // Updated: 225 * v4 + 98
 
    uint16_t magic = static_cast<uint16_t>(19425 * v4 + 17232);
 
    for (uint32_t v5 = 0; v5 < len; ++v5) {
        uint32_t source_index = (magic + v5) % v4;
        buffer[v5] = xor_key ^ temp[source_index];
    }
}
std::string ToString(int32_t index) {    
    int32_t decryptedIndex = DecryptIndex(index);
 
ResolveAddress_Fallback:
    if (decryptedIndex <= 0) return "";
 
    const uint32_t chunkIndex = decryptedIndex >> 16;
    const uint16_t nameEntryIndex = static_cast<uint16_t>(decryptedIndex);
                                                
    uintptr_t gnames_addr = Memory.ModuleBase + 0x175746C0;
    uintptr_t chunk_ptr_address = gnames_addr + ((uint64_t)chunkIndex + 0x5F2) * 8;
 
    const uint64_t chunkPtr = Read<uint64_t>(chunk_ptr_address);
    if (!chunkPtr) return "";
 
    const uint64_t namePoolChunk = chunkPtr + (2 * nameEntryIndex);
    const uint16_t header = Read<uint16_t>(namePoolChunk);
    if (header == 0) return "";
 
    if (header & 0x8000) return "";
 
    const uint16_t rawLength = (header >> 6) ; //old & 0x3FF
 
    if (rawLength == 39) { //old 3
        int32_t nextIndex = Read<int32_t>(namePoolChunk + 2);
        decryptedIndex = DecryptIndex(nextIndex);
        goto ResolveAddress_Fallback;
    }
 
    const uint16_t length = rawLength ^ 39;
    if (length <= 0 || length > 256) return "";
 
    std::vector<char> nameBuffer(length);
    if (!mem::read_bytes(namePoolChunk + 2, length, reinterpret_cast<BYTE*>(nameBuffer.data()))) return "";
 
    DecryptFName(nameBuffer.data(), length);
    return std::string(nameBuffer.data(), length);
}