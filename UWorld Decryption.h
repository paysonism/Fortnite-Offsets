// Current Patch: v39.10

inline uint64_t DecryptUWorld(uint64_t encrypted) {
    uint64_t decrypted = encrypted ^ 0xFFFFFFFFDC445031ULL;
    return decrypted;
}

uintptr_t encryptedUWorld = kernel->read_t<uintptr_t>(BaseAddress + offsets::UWorld);
uintptr_t decryptedUWorld = decryptUWorld(encryptedUWorld);

cache::UWorld = decryptedUWorld;
