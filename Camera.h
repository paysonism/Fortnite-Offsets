namespace camera
{
	FVector location, rotation;
	float fov;
}

	static auto UpdateCamera() -> void
	{
		auto location_pointer = read<uintptr_t>(pointer->uworld + 0x110);
		auto rotation_pointer = read<uintptr_t>(pointer->uworld + 0x120);

		struct FNRotation
		{
			double a; //0x0000
			char pad_0008[24]; //0x0008
			double b; //0x0020
			char pad_0028[424]; //0x0028
			double c; //0x01D0
    }tpmrotation;

		tpmrotation.a = read<double>(rotation_pointer);
		tpmrotation.b = read<double>(rotation_pointer + 0x20);
		tpmrotation.c = read<double>(rotation_pointer + 0x1d0);

    camera::rotation.x = asin(tpmrotation.c) * (180.0 / M_PI);
		camera::rotation.y = ((atan2(tpmrotation.a * -1, tpmrotation.b) * (180.0 / M_PI)) * -1) * -1;
		camera::rotation.z = 0;
		camera::location = read<FVector>(location_pointer);
		camera::fov = read<float>(pointer->player_controller + 0x394) * 90.f;
  }
