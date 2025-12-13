constexpr uintptr_t CachedBoneSpaceTransforms = 0x9A8; // TArray<FTransform>

inline int GetBoneCount(uintptr_t mesh)
{
    if (!mesh)
        return 0;

    // CachedBoneSpaceTransforms.Num();
    return kernel->read_t<int>(mesh + offsets::CachedBoneSpaceTransforms + 0x8);
}

void IterateBones(uintptr_t mesh)
{
    if (!mesh)
        return;

    ImDrawList* draw = ImGui::GetForegroundDrawList();

    int boneCount = GetBoneCount(mesh);
    if (boneCount <= 0)
        return;

    for (int i = 0; i < boneCount; ++i)
    {
        Vector3 boneWorld = GetBoneLocationCached(mesh, i);
        if (boneWorld.IsZero())
            continue;

        ImVec2 screen;
        if (!WorldToScreen(boneWorld, screen)) // replace with your W2S
            continue;

        char buf[8];
        _itoa_s(i, buf, 10);

        // outline
        draw->AddText(
            ImVec2(screen.x + 1, screen.y + 1),
            IM_COL32(0, 0, 0, 255),
            buf
        );

        // text
        draw->AddText(
            ImGui::GetFont(),
            10.0f,
            screen,
            IM_COL32(255, 255, 255, 220),
            buf
        );
    }
}