// Current Patch: v39.30

uint32_t GetObjectCount()
{
    constexpr uintptr_t ObjectCountEncryptedRva = 0x1785AFB8;
    constexpr uintptr_t XorKey = 0x75DB1A01;

    const uint32_t EncryptedCount = Read<uint32_t>(Memory.ModuleBase + ObjectCountEncryptedRva);
    const uint32_t DecryptedCount = __ROL4__(EncryptedCount ^ XorKey, 18);

    return DecryptedCount;
}

uint64_t GetObjectFromId(uint32_t Index)
{
    if (!Memory.ModuleBase)
        return 0;

    constexpr uintptr_t ObjectsEncryptedRva = 0x1785AFB0;
    constexpr uintptr_t ObjectsXorKey = 0xFFFFFFFFCCF54342ULL;
    constexpr uintptr_t ItemXorKey = 0x6BC5CA79;

    const uint64_t EncryptedObjects = Read<uint64_t>(Memory.ModuleBase + ObjectsEncryptedRva);
    const uintptr_t ChunkTable = EncryptedObjects ^ ObjectsXorKey;

    const int32_t ChunkIndex = Index >> 16;
    const uintptr_t ChunkAddress = Read<uintptr_t>(ChunkTable + (ChunkIndex * 8LL));

    if (!ChunkAddress)
        return 0;

    const int32_t IndexInChunk = Index & 0xFFFF;
    const uintptr_t ItemAddress = ChunkAddress + (IndexInChunk * 24);

    const uint64_t ItemRawValue = Read<uint64_t>(ItemAddress);
    const uint32_t EncryptedLowerPart = Read<uint32_t>(ItemAddress + 8);

    const uint32_t DecryptedLowerPart = __ROL4__(EncryptedLowerPart ^ ItemXorKey, 18);
    const uint64_t UpperPart = ItemRawValue & 0x3FFF00000000LL;
    const uint64_t ReconstructedValue = static_cast<uint64_t>(DecryptedLowerPart) | UpperPart;

    return ReconstructedValue * 8;
}