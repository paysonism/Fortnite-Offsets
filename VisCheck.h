// Current Patch: v38.10

bool IsEnemyVisible(uintptr_t Mesh) {
	auto Seconds = kernel->read_t<double>(cache::Gworld + offsets::CameraRotation + 0x10);
	auto LastRenderTime = kernel->read_t<float>(Mesh + 0x32C);
	return Seconds - LastRenderTime <= 0.06f;
}