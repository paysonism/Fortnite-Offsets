// Current Patch: v38.11

struct CameraDescription {
	Vector3 Location;
	Vector3 Rotation;
	float FieldOfView;
};

Camera GetViewAngles() {
	CameraDescription Camera;
	auto LocationPointer = kernel->read_t<uintptr_t>(cache::UWorld + offsets::CameraLocation);
	auto RotationPointer = kernel->read_t<uintptr_t>(cache::UWorld + offsets::CameraRotation);

	struct Rotation {
		double A;
		char Pad0008[24];
		double B;
		char Pad0028[424];
		double C;
	};
	Rotation Rotation;
	Rotation = kernel->read_t<Rotation>(RotationPointer);

	Camera.Location = kernel->read_t<Vector3>(LocationPointer);
	Camera.Rotation.x = asin(Rotation.C) * (180.0 / std::numbers::pi);
	Camera.Rotation.y = ((atan2(Rotation.A * -1, Rotation.B) * (180.0 / std::numbers::pi)) * -1) * -1;
	Camera.FieldOfView = kernel->read_t<float>(cache::PlayerController + offsets::CameraFOV) * 90.f;

	return { Camera.Location, Camera.Rotation, Camera.FieldOfView };
}

Camera GetViewPoint() 
{
    CameraPositionS ViewPoint{};
    uintptr_t LocationPointer = read<uintptr_t>(cache::UWorld + offsets::CameraLocation);
    uintptr_t RotationPointer = read<uintptr_t>(cache::UWorld + offsets::CameraRotation); // CameraLocation + 0x10
    FNRot FnRot{};
    FnRot.A = read<double>(RotationPointer);
    FnRot.B = read<double>(RotationPointer + 0x20);
    FnRot.C = read<double>(RotationPointer + offsets::GameState);
    ViewPoint.Location = read<Vector3>(LocationPointer);
    ViewPoint.Rotation.x = asin(FnRot.C) * (180.0 / M_PI);
    ViewPoint.Rotation.y = ((atan2(FnRot.A * -1, FnRot.B) * (180.0 / M_PI)) * -1) * -1;
    ViewPoint.Fov = read<float>(cache::PlayerController + offsets::CameraFOV) * 90.0f;
    return ViewPoint;
}