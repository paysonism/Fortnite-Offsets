namespace Addresses
{
	uintptr_t GWorld = 0x12BC1FD0; // (UWorld) // fresh dump
	uintptr_t GObjects = 0x1277CEB0;
	uintptr_t GNames = 0x12969D80;
	uintptr_t FName = 0x12894800;
	uintptr_t StaticFindObject = 0x16CC96C; // fresh dump
        uintptr_t GetBoneMatrix = 0x19A205C; // fresh dump
	uintptr_t LineOfSightTo = 0x627FB84;
	uintptr_t Viewpoint = 0x10F90A10;
	uintptr_t DrawTransition = 0x71;
	uintptr_t ProcessEvent = 0x4D;
	uintptr_t Fire = 0x285D0DC;
	uintptr_t Malloc = 0xC378BD;
	uintptr_t Free = 0xC3790D;
}

namespace Offsets
{
	uintptr_t LocalPawn = 0x338;
	uintptr_t PlayerController = 0x30;
	uintptr_t LocalPlayers = 0x38;
	uintptr_t PlayerState = 0x2b0;
	uintptr_t GameState = 0x160;
	uintptr_t GameInstance = 0x1D8;
	uintptr_t PlayerArray = 0x2A8;
	uintptr_t TeamIndex = 0x1211;
	uintptr_t RootC = 0x198;
	uintptr_t CameraManager = 0x348;
	uintptr_t CachedActor = 0x308;
	uintptr_t RootComponent = 0x198;
	uintptr_t ActorCount = 0xA8;
	uintptr_t TIndex = 0x1211;
	uintptr_t BoneArray = 0x5B0;
	uintptr_t C2W = 0x1c0;
	uintptr_t Actor = 0xA0; // discord.gg/saturniv
	uintptr_t ActorMesh = 0x318;
	uintptr_t CurrentActor(AActor) = 0xA8;
	uintptr_t PersistentLevel = 0x30;
	uintptr_t RelativeLocation = 0x120;
	uintptr_t DisplayName = 0x90;
	uintptr_t ComponetToWorld = 0x1c0;
	uintptr_t PawnPrivate = 0x308;
        uintptr_t Last_Render_Time = 0x2E8;
        uintptr_t Last_Render_Time_On_Screen = 0x2F0;
        uintptr_t Velocity = 0x168;
        uintptr_t DefaultFOV = 0x170;
        uintptr_t CurrentWeapons = 0xA68;
        uintptr_t bIsReloadingWeapon = 0x388;
        uintptr_t bIsEquippingWeapon = 0x350; // payson was here
	uintptr_t bIsChargingWeapon = 0x369;
	uintptr_t WeaponData = 0x500;
        uintptr_t AmmoCount = 0xEBC;
        uintptr_t bIsTargeting = 0x581;
        uintptr_t GunName = 0x98;
        uintptr_t Tier = 0xEB;
        uintptr_t bIsCrouched = 0x45C;
	uintptr_t bIsDying = 0x758;
	uintptr_t bIsHiddenForDeath = 0x758;
	uintptr_t bIsKnockedback = 0x758;
	uintptr_t bIsStaggered = 0x759; // discord.gg/saturniv
        uintptr_t bIsInvulnerable = 0x75A;
	uintptr_t bSpotted = 0x75A;
	uintptr_t bIsSliding = 0x75B;
	uintptr_t bWeaponHolstered = 0x939;
	uintptr_t bIsDBNO = 0x93A;
	uintptr_t LastRevivedFromDBNOTime = 0x4C30;
	uintptr_t bIsJumping = 0xA18;
        uintptr_t bIsABot = 0x29A;
	uintptr_t bIsReloadingWeapon = 0x388;
	uintptr_t GlobalAnimRateScale = 0xA18;
}

namepsace VTables 
{
	int DrawTitleSafeArea = 0x388 / 0x8; // fresh dump
	int ProcessEvent = 0x268 / 0x8; // fresh dump
	int GetMaterial = 0x2D0 / 0x8; // fresh dump
	int GetPlayerViewPoint = 0x7F8 / 0x8; // fresh dump
	int GetCameraViewPoint = 0x2C8 / 0x8; // fresh dump
	int GetViewPoint = 0x2C8 / 0x8; // fresh dump
	int IsAllowedToRender = 0x118 / 0x8; // fresh dump
	int FireSingle = 0x888 / 0x8; // fresh dump
	int TryToFire = 0x548 / 0x8; // fresh dump
	int GetDamageStartLocation = 0x7C8 / 0x8; // fresh dump
	int GetFiringRate = 0x9E0 / 0x8; // fresh dump
}
