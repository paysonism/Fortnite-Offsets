// Current Patch: v39.11

inline uint64_t decryptUWorld(uint64_t encrypted) {
    return std::rotl(encrypted, 56) - 603662288ULL;
}

uintptr_t encryptedUWorld = kernel->read_t<uintptr_t>(BaseAddress + offsets::UWorld);
uintptr_t decryptedUWorld = decryptUWorld(encryptedUWorld);

cache::UWorld = decryptedUWorld;
