// Current Patch: v39.11

uint32_t GetObjectCount()
{
    const uintptr_t GObjectsCountEncryptedRVA = 0x17560ED4;
    const uintptr_t xorKey = 0xF555A5AF;
 
 
    const uint32_t encryptedCount = Read<uint32_t>(Memory.ModuleBase + GObjectsCountEncryptedRVA);
    
    
    const uint32_t xored = encryptedCount ^ xorKey;
    return xored;
}
 
 
uint64_t GetUObjectFromID(uint32_t index)
{
    if (!Memory.ModuleBase) return 0;
 
    const uintptr_t GObjectsEncryptedRVA = 0x17560EC0;
    const uintptr_t xorKeys = 0x12576490;
 
    const uint64_t encrypted_gobjects = Read<uint64_t>(Memory.ModuleBase + GObjectsEncryptedRVA);
    const uintptr_t gObjectsChunkTable = __ROL8__(GObjectsEncryptedRVA, 48) - xorKeys;
 
    const int32_t chunk_index = index >> 16;
    const uintptr_t chunk_address = Read<uintptr_t>(gObjectsChunkTable + (chunk_index * 8LL));
 
    const int32_t index_in_chunk = index & 0xFFFF;
    const uintptr_t item_address = chunk_address + (index_in_chunk * 24);
 
    const uint64_t item_raw_value = Read<uint64_t>(item_address);
    const uint32_t encrypted_lower_part = Read<uint32_t>(item_address + 8);
 
    const uintptr_t xorKey = 0x45AA24DFLL;
    const uint32_t lower_decrypted = encrypted_lower_part ^ xorKey;
 
    const uint64_t upper_part = item_raw_value & 0x3FFF00000000LL;
 
    const uint64_t reconstructed_value = (uint64_t)lower_decrypted | upper_part;
 
    return reconstructed_value * 8;
}