// make sure your uworld is the same as the repo
class FName {
public:
    int ComparisonIndex;

    std::string ToString() {
        const int NAME_SIZE = 2048;

        auto NamePoolChunk = DotMem::Read<uint64_t>(va_text + (0x124E04C0 + 8 * (ComparisonIndex >> 16) + 16)) + 2 * ((unsigned short)ComparisonIndex);
        auto Pool = DotMem::Read<uint16_t>(NamePoolChunk);

        if (Pool < 64) {
            auto Index = DotMem::Read<int>(NamePoolChunk + 2);
            NamePoolChunk = DotMem::Read<uint64_t>(va_text + (0x124E04C0 + 8 * (Index >> 16) + 16)) + 2 * ((unsigned short)Index);
            Pool = DotMem::Read<uint16_t>(NamePoolChunk);
        }

        auto NameLength = min(Pool >> 6, NAME_SIZE);
        char NameBuffer[NAME_SIZE + 1] = { 0 };
        Driver::ReadPhysical(PVOID(NamePoolChunk + 2), NameBuffer, NameLength);

        DecryptFName(NameBuffer, NameLength);
        return std::string(NameBuffer);
    }

private:
    static void DecryptFName(char* buffer, int length) {
        unsigned int v4; // eax
        int v5; // edx
        unsigned int v6; // er8
        char* v7; // rcx
        __int64 v8; // rax

        v4 = DotMem::Read<unsigned int>(va_text + 0x123DAF88);
        v5 = (v4 << 8) | (v4 >> 8);
        v6 = v4 >> 9;
        if (length) {
            v7 = buffer;
            v8 = length;
            do {
                v5 += v6;
                *v7++ ^= v5;
                --v8;
            } while (v8);
        }
    }
};
