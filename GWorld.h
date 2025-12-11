// Current Patch: v39.10

inline uintptr_t decryptUWorld(uintptr_t encryptedAddress) noexcept {
    return decrypted = std::rotl(encrypted, 55) - 0xFFFFFFFFDC445031ULL;
}

uintptr_t encryptedUWorld = kernel->read_t<uintptr_t>(BaseAddress + offsets::UWorld);
uintptr_t decryptedUWorld = decryptUWorld(encryptedUWorld);

cache::UWorld = decryptedUWorld;