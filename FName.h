
// make sure your uworld is the same as the repo
class FName
{
public:
    int ComparisonIndex;

    std::string ToString()
    {
        const int NAME_SIZE = 2048;

        auto NamePoolChunk = DotMem::Read<uint64_t>(va_text + (0x124AE500 + 8 * (ComparisonIndex >> 16) + 16)) + 2 * ((unsigned short)ComparisonIndex);
        auto Pool = DotMem::Read<uint16_t>(NamePoolChunk);

        if (Pool < 64)
        {
            auto Index = DotMem::Read<int>(NamePoolChunk + 2);
            NamePoolChunk = DotMem::Read<uint64_t>(va_text + (0x124AE500 + 8 * (Index >> 16) + 16)) + 2 * ((unsigned short)Index);
            Pool = DotMem::Read<uint16_t>(NamePoolChunk);
        }

        auto NameLength = min(Pool >> 6, NAME_SIZE);
        char NameBuffer[NAME_SIZE + 1] = {0};
        Driver::ReadPhysical(PVOID(NamePoolChunk + 2), NameBuffer, NameLength);

        DecryptFName(NameBuffer, NameLength);
        return std::string(NameBuffer);
    }

private:
    static void DecryptFName(char *buffer, int length)
    {
        int v4;     // edx
        char *v5;   // rcx
        __int64 v6; // r8
        char v7;    // al

        v4 = 0x11;
        if (length)
        {
            v5 = buffer;
            v6 = length;
            do
            {
                v7 = v4 + ~*v5;
                v4 += 0x1F0B;
                *v5++ = v7;
                --v6;
            } while (v6);
        }
    }
};
