// Current Patch: v39.11

uint32_t GetObjectCount()
{
    constexpr uintptr_t ObjectCountEncryptedRva = 0x17560ED4;
    constexpr uintptr_t XorKey = 0xF555A5AF;

    const uint32_t EncryptedCount = Read<uint32_t>(Memory.ModuleBase + ObjectCountEncryptedRva);
    const uint32_t DecryptedCount = EncryptedCount ^ XorKey;

    return DecryptedCount;
}

uint64_t GetObjectFromId(uint32_t Index)
{
    if (!Memory.ModuleBase)
        return 0;

    constexpr uintptr_t ObjectsEncryptedRva = 0x17560EC0;
    constexpr uintptr_t ObjectsXorKey = 0x12576490;
    constexpr uintptr_t ItemXorKey = 0x45AA24DFLL;

    const uint64_t EncryptedObjects = Read<uint64_t>(Memory.ModuleBase + ObjectsEncryptedRva);
    const uintptr_t ChunkTable = __ROL8__(EncryptedObjects, 48) - ObjectsXorKey;

    const int32_t ChunkIndex = Index >> 16;
    const uintptr_t ChunkAddress = Read<uintptr_t>(ChunkTable + (ChunkIndex * 8LL));

    const int32_t IndexInChunk = Index & 0xFFFF;
    const uintptr_t ItemAddress = ChunkAddress + (IndexInChunk * 24);

    const uint64_t ItemRawValue = Read<uint64_t>(ItemAddress);
    const uint32_t EncryptedLowerPart = Read<uint32_t>(ItemAddress + 8);

    const uint32_t DecryptedLowerPart = EncryptedLowerPart ^ ItemXorKey;
    const uint64_t UpperPart = ItemRawValue & 0x3FFF00000000LL;
    const uint64_t ReconstructedValue = static_cast<uint64_t>(DecryptedLowerPart) | UpperPart;

    return ReconstructedValue * 8;
}