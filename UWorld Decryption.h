// Current Patch: v39.30

inline uint64_t DecryptWorld(uint64_t world)
{
    return (world ^ 0xFFFFFFFFD599D092ULL);
}

uintptr_t encryptedUWorld = kernel->read_t<uintptr_t>(BaseAddress + offsets::UWorld);
uintptr_t decryptedUWorld = decryptUWorld(encryptedUWorld);

cache::UWorld = decryptedUWorld;