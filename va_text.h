		__int64 va_text = 0;
	for (auto i = 0; i < FLT_MAX; i++) {
		va_text = virtualaddy + i * 0x1000;
		auto uworld = read<uintptr_t>(va_text + GWORLD);
		auto level = read<uintptr_t>(uworld + PersistentLevel);
		if (uworld && level && read<uintptr_t>(level + OwningWorld) == uworld) {
			break;
		}
	}
