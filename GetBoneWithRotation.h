ftransform GetBoneIndex(uint64_t mesh, int index)
{
	uint64_t bonearray = read<uint64_t>(mesh + 0x4a8);
	if (!bonearray) bonearray = read<uint64_t>(mesh + 0x4a8 + 0x10);
	return read<ftransform>(bonearray + (index * 0x30));
}

Vector3 GetBoneWithRotation(DWORD_PTR mesh, int id)
{
	ftransform bone = GetBoneIndex(mesh, id);
	ftransform ComponentToWorld = read<ftransform>(mesh + offsets::componet_to_world);

	D3DMATRIX Matrix;
	Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());

	return Vector3(Matrix._41, Matrix._42, Matrix._43);
}
