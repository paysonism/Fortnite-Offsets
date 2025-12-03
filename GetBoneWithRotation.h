// Current Patch: v39.00 - 2

void InvalidateBoneCache() {
	g_currentFrame++;
	auto now = std::chrono::steady_clock::now();
	for (auto it = g_boneCache.begin(); it != g_boneCache.end();) {
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
			now - it->second.timestamp).count();
		if (elapsed > 16) { // older than 1 frame
			it = g_boneCache.erase(it);
		} else {
			++it;
		}
	}
}

inline auto GetBoneLocation(uintptr_t skeletal_mesh, int bone_index) -> Vector3 {
	uintptr_t bone_array = kernel->read_t<uintptr_t>(skeletal_mesh + offsets::BoneArray);

	if (bone_array == NULL)
		bone_array = kernel->read_t<uintptr_t>(skeletal_mesh + offsets::BoneArray + 0x10);

	FTransform bone = kernel->read_t<FTransform>(bone_array + (bone_index * 0x60));

	FTransform component_to_world;
	auto cacheIt = g_boneCache.find(skeletal_mesh);
	if (cacheIt != g_boneCache.end()) {
		component_to_world = cacheIt->second.componentToWorld;
	} else {
		component_to_world = kernel->read_t<FTransform>(skeletal_mesh + offsets::ComponentToWorld);
		BoneTransformCache cacheEntry;
		cacheEntry.mesh = skeletal_mesh;
		cacheEntry.componentToWorld = component_to_world;
		cacheEntry.timestamp = std::chrono::steady_clock::now();
		g_boneCache[skeletal_mesh] = cacheEntry;
	}

	D3DMATRIX matrix = matrix_multiplication(bone.to_matrix_with_scale(), component_to_world.to_matrix_with_scale());

	return Vector3(matrix._41, matrix._42, matrix._43);
}


inline Vector3 GetBoneLocationCached(uintptr_t mesh, int boneIndex) {
    if (!mesh) return {};

    auto& entry = g_perBoneCache[mesh];
    if (entry.mesh != mesh || entry.generation != g_perBoneCacheGeneration) {
        entry.mesh = mesh;
        entry.generation = g_perBoneCacheGeneration;
        entry.bones.clear();
    }

    if (auto it = entry.bones.find(boneIndex); it != entry.bones.end())
        return it->second;

    Vector3 v = GetBoneLocation(mesh, boneIndex);
    entry.bones.emplace(boneIndex, v);
    return v;
}