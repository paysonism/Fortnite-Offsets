// Current Patch: v39.30

std::string GetPlayerName()
{
    if (!game)
        return "";
    
    auto mem = Game->GetMemInstance();
    if (!mem)
        return "";
    
    if (!player_state)
        return "BOT";
    
    const uintptr_t PlatformPtr = Kernel->Read<uintptr_t>(player_state + offsets::Platform);
    const bool IsBot = (!PlatformPtr || Kernel->Read<wchar_t>(PlatformPtr) == 0);
    
    if (IsBot)
        return "BOT";
    
    const uintptr_t FString = Kernel->Read<uintptr_t>(player_state + offsets::PlayerName);
    if (!FString)
        return "BOT";
    
    const uintptr_t FText = Kernel->Read<uintptr_t>(FString + 0x8);
    if (!FText)
        return "BOT";
    
    const int32_t Length = Kernel->Read<int32_t>(FString + 0x10);
    if (Length <= 0 || Length > 255)
        return "BOT";
    
    std::wstring WideName(Length, L'\0');
    Kernel->ReadMemory(FText, WideName.data(), Length * sizeof(wchar_t));
    
    const int64_t NameLength = static_cast<int64_t>(Length);
    if (!NameLength)
        return "BOT";
    
    char LastCharIndex = NameLength - 1;
    if (!static_cast<uint32_t>(NameLength))
        LastCharIndex = 0;
    
    int32_t CharIndex = 0;
    uint16_t* NamePtr = reinterpret_cast<uint16_t*>(WideName.data());
    int32_t Key = LastCharIndex & 3;
    
    while (true)
    {
        int32_t MaxIndex = NameLength - 1;
        if (!static_cast<uint32_t>(NameLength))
            MaxIndex = 0;
        
        if (CharIndex >= MaxIndex)
            break;
        
        *NamePtr += Key & 7;
        NamePtr++;
        Key += 3;
        CharIndex++;
    }
    
    if (auto NullPos = WideName.find(L'\0'); NullPos != std::wstring::npos)
        WideName.erase(NullPos);

    #ifdef _WIN32
    if (WideName.empty())
        return "";
    
    const int SizeNeeded = WideCharToMultiByte(CP_UTF8, 0, WideName.c_str(), 
                                               static_cast<int>(WideName.size()), 
                                               nullptr, 0, nullptr, nullptr);
    if (SizeNeeded <= 0)
    {
        std::string Result;
        Result.reserve(WideName.size());
        for (wchar_t Char : WideName)
        {
            if (Char < 128)
                Result += static_cast<char>(Char);
            else
                Result += '?';
        }
        return Result;
    }
    
    std::string Result(SizeNeeded, 0);
    WideCharToMultiByte(CP_UTF8, 0, WideName.c_str(), 
                       static_cast<int>(WideName.size()), 
                       &Result[0], SizeNeeded, nullptr, nullptr);
    return Result;
    
    #else
    if (WideName.empty())
        return "";
    
    try
    {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> Converter;
        return Converter.to_bytes(WideName);
    }
    catch (...)
    {
        std::string Result;
        Result.reserve(WideName.size());
        for (wchar_t Char : WideName)
        {
            if (Char < 128)
                Result += static_cast<char>(Char);
            else
                Result += '?';
        }
        return Result;
    }
    #endif
}