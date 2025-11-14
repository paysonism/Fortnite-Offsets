// Current Patch: v38.10

FTransform GetBoneIndex(uint64_t Mesh, int Index)
{
	uint64_t BoneArray = kernel->read_t<uint64_t>(Mesh + 0x5E8);
	if (!BoneArray) BoneArray = kernel->read_t<uint64_t>(Mesh + 0x5E8 + 0x10);
	return kernel->read_t<FTransform>(BoneArray + (Index * 0x30));
}

Vector3 GetBoneWithRotation(DWORD_PTR Mesh, int Id) {

	int32_t ActiveTransforms = kernel->read_t<int32_t>(Mesh + (offsets::BoneArray + 0x48)) * 0x10;
	auto BoneArray = kernel->read_t<TArray<FTransform>>((uintptr_t)Mesh + offsets::BoneArray + ActiveTransforms);
	auto BoneTransform = kernel->read_t<FTransform>((uintptr_t)BoneArray.Data + (Id * 0x60));
	FTransform ComponentToWorld = kernel->read_t<FTransform>((uintptr_t)Mesh + offsets::ComponentToWorld);

	D3DMATRIX Matrix = MatrixMultiplication(BoneTransform.ToMatrixWithScale().ToD3DMATRIX(), ComponentToWorld.ToMatrixWithScale().ToD3DMATRIX());
	return Vector3(Matrix._41, Matrix._42, Matrix._43);
}