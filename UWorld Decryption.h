// Current Patch: v39.20

inline uint64_t decryptUWorld(uint64_t world)
{
    return ~__ROL8__(world ^ 0x7B40E797ULL, 50);
}

uintptr_t encryptedUWorld = kernel->read_t<uintptr_t>(BaseAddress + offsets::UWorld);
uintptr_t decryptedUWorld = decryptUWorld(encryptedUWorld);

cache::UWorld = decryptedUWorld;