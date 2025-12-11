// Current Patch: v39.10

uint32_t GetObjectsCount()
{
    const uintptr_t GObjectsCountEncryptedRVA = offsets::GObjectsCount;
    const uint32_t XorKey = 0xBC0BA8E;

    const uint32_t encryptedCount = read<uint32_t>(BaseAddress + GObjectsCountEncryptedRVA);

    return (encryptedCount ^ XorKey);
}
 
uint64_t GetObjectByIndex(uint32_t index)
{
    if (!BaseAddress) return 0;

    const uintptr_t GObjectsEncryptedRVA = offsets::GObjects;
    const uint64_t GObjectsArrayKey = 0xFFFFFFFF91478091ULL;
    const uint64_t encrypted_gobjects = read<uint64_t>(BaseAddress + GObjectsEncryptedRVA);
    const uintptr_t gObjectsChunkTable = RotateLeft64(encrypted_gobjects, 47) - GObjectsArrayKey;

    const int32_t chunk_index = index >> 16;
    const uintptr_t chunk_address = read<uintptr_t>(gObjectsChunkTable + (chunk_index * 8LL));
    if (!chunk_address) return 0;

    const int32_t index_in_chunk = index & 0xFFFF;
    const uintptr_t item_address = chunk_address + (index_in_chunk * 24);

    const uint64_t item_raw_value = read<uint64_t>(item_address);
    const uint32_t encrypted_lower_part = read<uint32_t>(item_address + 8);

    const uint32_t lower_decrypted = (encrypted_lower_part ^ 0x8AB29D8ELL);
    const uint64_t upper_part = item_raw_value & 0x3FFF00000000LL;
    const uint64_t reconstructed_value = (uint64_t)lower_decrypted | upper_part;

    return reconstructed_value * 8;
}