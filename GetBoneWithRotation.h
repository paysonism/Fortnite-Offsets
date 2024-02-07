uintptr_t GetBoneArrayAddress(uintptr_t mesh) {
    uintptr_t bone_array = d::read<uintptr_t>(mesh + 0x608);
    if (bone_array == NULL) // payson1337
        bone_array = d::read<uintptr_t>( mesh + 0x608 + 0x10);
    return bone_array;
}

Vector3 GetBoneWithRotation(uintptr_t mesh, int bone_id) {
    uintptr_t bone_array = GetBoneArrayAddress((u)this);
    FTransform bone = d::read <FTransform>(bone_array + (bone_id * 0x60));
    FTransform component_to_world = d::read<FTransform>((u)this + 0x230);
    D3DMATRIX matrix = MatrixMultiplication(bone.ToMatrixWithScale(), component_to_world.ToMatrixWithScale());
    return Vector3(matrix._41, matrix._42, matrix._43);
}
