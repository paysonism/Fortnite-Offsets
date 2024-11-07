// U DONT NEED ANYMORE VA_TEXT JUST USE VIRTUALADDY + UWORLD OR UR BASEID MET + UWORLD BUT IF U STILL USE IT HERE IS THE NEW UPDATED 1

__int64 va_text = 0;
    for (auto i = 0; i < FLT_MAX; i++) {
        va_text = virtualaddy + i * 0x1000;
        auto uworld = read<uintptr_t>(va_text + 0x12D17A08);
        auto level = read<uintptr_t>(uworld + 0x38);
        if (uworld && level && read<uintptr_t>(level + 0xc8) == uworld) {
            break;
        }
    }
