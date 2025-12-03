// Current Patch: v39.00 - 2

constexpr uint64_t GNamesOffset = 0x17168D00;
constexpr uint64_t GNamesChunkOffset = 0x5F2; // 1522

int32_t DecryptIndex(int32_t index) {
    if (index == 0) return 0;
    uint32_t value = (index - 1) ^ 0x7CEC2953;
    if (value == 0xFFFFFFFF) return 0;
    return value + 1;
}
 
void DecryptFName(char* buffer, int32_t length) {
    if (length <= 0) return;
    std::vector<uint8_t> temp(buffer, buffer + length);
    uint32_t len = (uint32_t)length;

    uint8_t xor_key = (uint8_t)((49 * len + 94) & 0xFF);

    uint16_t magic = (uint16_t)(24764 - 5583 * len);

    for (uint32_t i = 0; i < len; ++i) {
        buffer[i] = xor_key ^ temp[(magic + i) % len];
    }
}
 
std::string ToString(int32_t index) {
    int32_t idx = DecryptIndex(index);
    int retries = 0;
Resolve:
    if (idx <= 0 || retries > 5) return "";

    uintptr_t chunkPtr = read<uint64_t>(BaseAddress + GNamesOffset + ((uint64_t)(idx >> 16) + GNamesChunkOffset) * 8);
    if (!chunkPtr) return "";

    uintptr_t entry = chunkPtr + (2 * (uint16_t)idx);
    uint16_t header = read<uint16_t>(entry);

    if (header & 0x8000) return ""; // Wide String Skip

    uint16_t rawLen = (header >> 5) & 0x3FF;

    if (rawLen == 3) {
        idx = DecryptIndex(read<int32_t>(entry + 2));
        retries++;
        goto Resolve;
    }

    uint16_t len = rawLen ^ 3;

    if (len == 0 || len > 255) return "";

    char buf[256];
    if (!ReadMemoryFromDump(entry + 2, len, (BYTE*)buf)) return "";

    DecryptFName(buf, len);
    return std::string(buf, len);
}