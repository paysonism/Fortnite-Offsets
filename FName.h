// Current Patch: v38.10

class FName
{
public:
    int ComparisonIndex;

    std::string ToString()
    {
        const int NAME_SIZE = 2048;

        auto NamePoolChunk = kernel->read_t<uint64_t>(VaText + (0x123FAFC0 + 8 * (ComparisonIndex >> 16) + 16)) + 2 * ((unsigned short)ComparisonIndex);
        auto Pool = kernel->read_t<uint16_t>(NamePoolChunk);

        if (Pool < 64)
        {
            auto Index = kernel->read_t<int>(NamePoolChunk + 2);
            NamePoolChunk = kernel->read_t<uint64_t>(VaText + (0x124AE500 + 8 * (Index >> 16) + 16)) + 2 * ((unsigned short)Index);
            Pool = kernel->read_t<uint16_t>(NamePoolChunk);
        }

        auto NameLength = min(Pool >> 6, NAME_SIZE);
        char NameBuffer[NAME_SIZE + 1] = {0};
        kernel->read_physical(PVOID(NamePoolChunk + 2), NameBuffer, NameLength);

        DecryptFName(NameBuffer, NameLength);
        return std::string(NameBuffer);
    }

private:
    static void DecryptFName(char *Buffer, int Length)
    {
        int V0;
        char *V1;
        int V2;
        int V3;
        int V4;
        unsigned int V5;
        char Result;

        V2 = 0;
        V3 = 28;
        if (Length)
        {
            V0 = Length;
            V1 = Buffer;
            do
            {
                V4 = V2++;
                V5 = (V4 | 0xB000) + V3;
                Result = V5 ^ ~*V1;
                V3 = V5 >> 2;
                *V1++ = Result;
            } while (V2 < V0);
        }
    }
};