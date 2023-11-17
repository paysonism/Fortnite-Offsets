Vector3 GetBoneWithRotation(uintptr_t mesh, int bone_id)
{
	uintptr_t bone_array = read<uintptr_t>(mesh + 0x600);
	if (bone_array == NULL) bone_array = read<uintptr_t>(mesh + 0x600 + 0x10);
	FTransform bone = read<FTransform>(bone_array + (bone_id * 0x60)); // payson1337
	FTransform component_to_world = read<FTransform>(mesh + 0x240);
	D3DMATRIX matrix = MatrixMultiplication(bone.ToMatrixWithScale(), component_to_world.ToMatrixWithScale());
	return Vector3(matrix._41, matrix._42, matrix._43);
}
