// Current Patch: v38.11

bool IsEnemyVisible(uintptr_t Mesh) {
	auto Seconds = kernel->read_t<double>(cache::Gworld + offsets::CameraRotation + 0x10);
	auto LastRenderTime = kernel->read_t<float>(Mesh + 0x32C); // note for later: add this to offsets struct for easier updating
	return Seconds - LastRenderTime <= 0.06f;
}