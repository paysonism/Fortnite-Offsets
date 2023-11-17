struct payson1337
{
	Vector3 location;
	Vector3 rotation;
	float fov;
};


payson1337 get_camera()
{
	payson1337 camera;

	auto location_pointer = read<uintptr_t>(Uworld + 0x110);
	auto rotation_pointer = read<uintptr_t>(Uworld + 0x120);

	struct FNRot
	{
		double a; //0x0000
		char pad_0008[24]; //0x0008
		double b; //0x0020
		char pad_0028[424]; //0x0028
		double c; //0x01D0
	}fnRot;

	fnRot.a = read<double>(rotation_pointer);
	fnRot.b = read<double>(rotation_pointer + 0x20);
	fnRot.c = read<double>(rotation_pointer + 0x1d0);

	camera.location = read<Vector3>(location_pointer);
	camera.rotation.x = asin(fnRot.c) * (180.0 / M_PI);
	camera.rotation.y = ((atan2(fnRot.a * -1, fnRot.b) * (180.0 / M_PI)) * -1) * -1;
	camera.fov = read<float>((uintptr_t)PlayerController + 0x394) * 90.f;

	return camera;
}
