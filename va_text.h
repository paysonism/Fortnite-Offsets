		__int64 va_text = 0;
	for (auto i = 0; i < FLT_MAX; i++) {
		va_text = virtualaddy + i * 0x1000;
		auto uworld = read<uintptr_t>(va_text + offsets::uworld);
		auto level = read<uintptr_t>(uworld + offsets::PersistentLevel);
		if (uworld && level && read<uintptr_t>(level + offsets::OwningWorld) == uworld) {
			break;
		}
	}
