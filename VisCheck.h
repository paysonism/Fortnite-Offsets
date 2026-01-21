// Current Patch: Working!

bool IsEnemyVisible(uintptr_t Mesh) {
	auto Seconds = kernel->read_t<double>(cache::UWorld + offsets::CameraRotation + 0x10);
	auto LastRenderTime = kernel->read_t<float>(Mesh + offsets::LastRenderTime);
	return Seconds - LastRenderTime <= 0.06f;
}
