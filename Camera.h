Camera get_view_point() 
{
    Camera view_point{};
    uintptr_t location_pointer = read<uintptr_t>(cache::uworld + 0x130); 
    uintptr_t rotation_pointer = read<uintptr_t>(cache::uworld + 0x140); 
    FNRot fnrot{};
    fnrot.a = read<double>(rotation_pointer);
    fnrot.b = read<double>(rotation_pointer + 0x20);
    fnrot.c = read<double>(rotation_pointer + 0x1D0);
    view_point.location = read<Vector3>(location_pointer);
    view_point.rotation.x = asin(fnrot.c) * (180.0 / M_PI);
    view_point.rotation.y = ((atan2(fnrot.a * -1, fnrot.b) * (180.0 / M_PI)) * -1) * -1;
    auto fov_radians = read<float>(cache::player_controller + 0x3AC) * 2; // USE 3AC IF U USE PLAYER_CONTROLLER U NIGGER
    view_point.fov * 180.0f / std::numbers::pi;
    return view_point;
}

Camera get_view_point()
{
	Camera view_point{};
	uintptr_t location_pointer = read<uintptr_t>(cache::uworld + 0x130); //
	uintptr_t rotation_pointer = read<uintptr_t>(cache::uworld + 0x140); //
	FNRot fnrot{};
	fnrot.a = read<double>(rotation_pointer);
	fnrot.b = read<double>(rotation_pointer + 0x20);
	fnrot.c = read<double>(rotation_pointer + 0x1D0);
	view_point.location = read<Vector3>(location_pointer);
	view_point.rotation.x = asin(fnrot.c) * (180.0 / M_PI);
	view_point.rotation.y = ((atan2(fnrot.a * -1, fnrot.b) * (180.0 / M_PI)) * -1) * -1;
	view_point.fov = read<float>(cache::local_player + 0x4AC); //USE 0x4AC WHEN LOCAL_PLAYER U FUCKING BLACK NIGGA
	return view_point;
}
