// Current Patch: Working

Vector2 ProjectWorldToScreen(Vector3 WorldLocation) {
	VCamera = GetViewAngles();
	
	auto MMatrix = Matrix(VCamera.Rotation);
	auto XAxis = Vector3(MMatrix.m[0][0], MMatrix.m[0][1], MMatrix.m[0][2]);
	auto YAxis = Vector3(MMatrix.m[1][0], MMatrix.m[1][1], MMatrix.m[1][2]);
	auto ZAxis = Vector3(MMatrix.m[2][0], MMatrix.m[2][1], MMatrix.m[2][2]);

	auto VDeltaCoordinates = WorldLocation - VCamera.Location;
	auto TTransform = Vector3(VDeltaCoordinates.Dot(YAxis), VDeltaCoordinates.Dot(ZAxis), VDeltaCoordinates.Dot(XAxis));

	TTransform.z = (TTransform.z < 1.f) ? 1.f : TTransform.z;
	auto FovRadians = tan(VCamera.FieldOfView * std::numbers::pi / 360.f);

	return Vector2(Width / 2 + TTransform.x * ((Width / 2) / FovRadians) / TTransform.z, Height / 2 - TTransform.y * ((Width / 2) / FovRadians) / TTransform.z);
}