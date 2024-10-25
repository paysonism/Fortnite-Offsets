// make sure your uworld is the same as the repo
class FName
{
public:
    int ComparisonIndex;

    std::string ToString()
    {
        const int NAME_SIZE = 2048;

        auto NamePoolChunk = DotMem::Read<uint64_t>(va_text + (0x123FAFC0 + 8 * (ComparisonIndex >> 16) + 16)) + 2 * ((unsigned short)ComparisonIndex);
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
        int v0;          // ebx
        char *v1;        // rdi
        int v2;          // ecx
        int v3;          // edx
        int v4;          // eax
        unsigned int v5; // edx
        char result;     // al

        v2 = 0;
        v3 = 28;
        if (length)
        {
            v0 = length;
            v1 = buffer;
            do
            {
                v4 = v2++;
                v5 = (v4 | 0xB000) + v3;
                result = v5 ^ ~*v1;
                v3 = v5 >> 2;
                *v1++ = result;
            } while (v2 < v0);
        }
    }
};
