		__int64 va_text = 0;
    for (auto i = 0; i < FLT_MAX; i++) {
        va_text = virtualaddy + i * 0x1000;
        auto uworld = read<uintptr_t>(va_text + 0x12300E58);
        auto level = read<uintptr_t>(uworld + 0x30);
        if (uworld && level && read<uintptr_t>(level + 0xc0) == uworld) {
            break;
        }
    }
