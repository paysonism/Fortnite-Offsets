// Current Patch: v39.11

inline uint64_t decryptUWorld(uint64_t encrypted) {
    uint64_t xored = encrypted ^ 0xBF4617A5ULL;
    uint64_t rotated = (xored << 51) | (xored >> 13); // rotl64 by 51
    return ~rotated;
}

uintptr_t encryptedUWorld = kernel->read_t<uintptr_t>(BaseAddress + offsets::UWorld);
uintptr_t decryptedUWorld = decryptUWorld(encryptedUWorld);

cache::UWorld = decryptedUWorld;
