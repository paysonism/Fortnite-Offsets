// Current Patch: v39.11

inline uint64_t DecryptUWorld(uint64_t encrypted) {
    return std::rotr(~encrypted, 51) ^ offsets::UWorldXorKey;
}

uintptr_t encryptedUWorld = kernel->read_t<uintptr_t>(BaseAddress + offsets::UWorld);
uintptr_t decryptedUWorld = decryptUWorld(encryptedUWorld);

cache::UWorld = decryptedUWorld;
