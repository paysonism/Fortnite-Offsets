Sigs:

GWorld/UWorld: 48 89 05 ? ? ? ? 0F 28 D7 // known working
FreeFN: 48 89 D1 48 FF 25 ? ? ? ? C3 // unkown
BoneMatrix: E8 ? ? ? ? 0F 10 40 68 // unkown
ProjectWorldToScreen: 40 53 55 56 57 41 56 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 33 DB 49 // unkown
GObjects: 48 8B 05 ? ? ? ? 48 8B 0C C8 48 8B 04 D1 // unkown
GetNameByIndex: 48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 33 ED 48 8B FA 48 89 2A 48 89 6A 08 8B // unkown
LineOfSightTo: 48 8B C4 48 89 58 20 55 56 57 41 54 41 56 48 8D 68 // unkown
StaticFindObject: 48 89 5C 24 ?? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 70 FC FF FF 48 81 EC ?? ?? ?? ?? 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 85 ?? ?? ?? ?? 48 83 FA FF // known working

VTables:

DrawTransition: 0x70 [112] // unkown
ViewportClient: 0x71 [113] // unkown
PostRender: 0x6F [111] // unkown
ProcessEvent: 0x4C [76] // unkown
GetPlayerViewPoint: 0x7F0 // unkown
SetControlRotation: 0x760 // unkown
GetCameraLocation: 0x808 // unkown
GetCameraRotation: 0x800 // unkown
GetFOVAngle: 0x7C0 // unkown
LineOfSightTo: 0x770 // unkown
AddPitchInput: 0xCF0 // unkown
ClientSetCameraMode: 0xA08 // unkown
AddYawInput: 0xCF8 // unkown

// discord.gg/saturniv
