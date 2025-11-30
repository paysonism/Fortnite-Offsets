// Current Patch: v39.00

inline uintptr_t decryptUWorld(uintptr_t encryptedAddress) noexcept {
    return std::rotl(encryptedAddress, 32) ^ 0x8F1D3223E733EA8A;
}

uintptr_t encryptedUWorld = kernel->read_t<uintptr_t>(BaseAddress + offsets::UWorld);
uintptr_t decryptedUWorld = decryptUWorld(encryptedUWorld);

cache::UWorld = decryptedUWorld;