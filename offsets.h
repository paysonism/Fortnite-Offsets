namespace Addresses
{
	uintptr_t GWorld = 0x1221B738; // (UWorld) // fresh dump
        uintptr_t PersistentLevel = 0x30
        uintptr_t OwningWorld = 0xc0
  uintptr_t HabaneroComponent = 0x9E8;// fresh dump
	uintptr_t GObjects = 0x121F3380;  // fresh dump
	uintptr_t GNames = 0x123FAFC0;// fresh dump
	uintptr_t FName = 0x124DE7C0 + 8;
	uintptr_t StaticFindObject = 0x1DE185C;
   	uintptr_t GetBoneMatrix = 0x1E4E8E6;
 	uintptr_t LineOfSightTo = 0x627FB84;
        uintptr_t ProjectileSpeed = 0x1F30;
        uintptr_t ProjectileGravity = 0x1F34;
        uintptr_t PlayerName = 0xAA8;
	uintptr_t Viewpoint = 0x10F90A10;
	uintptr_t DrawTransition = 0x71;
	uintptr_t ProcessEvent = 0x4D;
	uintptr_t Fire = 0x285D0DC;
	uintptr_t Malloc = 0xC4663D;
        uintptr_t  platform = 0x3F0;
	uintptr_t Free = 0xC4668D;
}

namespace Offsets
{
	uintptr_t LocalPawn = 0x338;
	uintptr_t PlayerController = 0x30;
	uintptr_t LocalPlayers = 0x38;
	uintptr_t PlayerState = 0x2B0;
	uintptr_t GameState = 0x160;
	uintptr_t GameInstance = 0x1D8;
	uintptr_t PlayerArray = 0x2A8;
	uintptr_t TeamIndex = 0x1211;
	uintptr_t RootC = 0x198;
	uintptr_t CameraManager = 0x348;
	uintptr_t CachedActor = 0x308;
	uintptr_t RootComponent = 0x198;
	uintptr_t ActorCount = 0xA8;
	uintptr_t BoneArray = 0x570; 
	uintptr_t BoneCache = 0x5B8;// fresh dump
	uintptr_t C2W = 0x1c0;
	uintptr_t Actor = 0xA0; // discord.gg/saturniv
	uintptr_t ActorMesh = 0x310; // discord.gg/saturniv
	uintptr_t CurrentActor(AActor) = 0xA8;// discord.gg/saturniv
	uintptr_t PersistentLevel = 0x30;// discord.gg/saturniv
	uintptr_t RelativeLocation = 0x120;// discord.gg/saturniv
	uintptr_t DisplayName = 0x90;// discord.gg/saturniv
	uintptr_t ComponetToWorld = 0x1c0;// discord.gg/saturniv
	uintptr_t PawnPrivate = 0x308;// discord.gg/saturniv
        uintptr_t LastRenderTimeOnScreen = 0x2E0; // discord.gg/saturniv
        uintptr_t LastSubmitTime = 0x2E8; // discord.gg/saturniv
        uintptr_t Velocity = 0x168;// discord.gg/saturniv
        uintptr_t DefaultFOV = 0x2a4;// discord.gg/saturniv
        uintptr_t CurrentWeapons = 0x9d8;// discord.gg/saturniv
        uintptr_t bIsReloadingWeapon = 0x399;// discord.gg/saturniv
        uintptr_t bIsEquippingWeapon = 0x350; // payson was here
	uintptr_t bIsChargingWeapon = 0x369;// discord.gg/saturniv
	uintptr_t WeaponData = 0x520;// discord.gg/saturniv
        uintptr_t AmmoCount = 0xef4;// discord.gg/saturniv
        uintptr_t bIsTargeting = 0x581;// discord.gg/saturniv
        uintptr_t GunName = 0x98;// discord.gg/saturniv
        uintptr_t Tier = 0x9A;// discord.gg/saturniv
        uintptr_t bIsCrouched = 0x45C;// discord.gg/saturniv
	uintptr_t bIsDying = 0x758;// discord.gg/saturniv
	uintptr_t bIsHiddenForDeath = 0x758;// discord.gg/saturniv
	uintptr_t bIsKnockedback = 0x758;// discord.gg/saturniv
	uintptr_t bIsStaggered = 0x759; // discord.gg/saturniv
        uintptr_t bIsInvulnerable = 0x75A;// discord.gg/saturniv
	uintptr_t bSpotted = 0x75A;// discord.gg/saturniv
	uintptr_t bIsSliding = 0x75B;// discord.gg/saturniv
	uintptr_t bWeaponHolstered = 0x939;// discord.gg/saturniv
	uintptr_t bIsDBNO = 0x93A;
	uintptr_t LastRevivedFromDBNOTime = 0x4C30;
	uintptr_t bIsJumping = 0xA60;
        uintptr_t bIsABot = 0x29A;
	uintptr_t bIsReloadingWeapon = 0x388;
	uintptr_t GlobalAnimRateScale = 0xA18;
	uintptr_t CustomTimeDilation = 0x68;
}


// SOME SDK OFFSETS FRSH DUMP from FN_Engine_classes.hpp

		FActorTickFunction PrimaryActorTick; // 0x28(0x30)
		bool bNetTemporary : 1; // 0x58:0(0x1)
		unsigned char UnknownBit00 : 1; // 0x58:1(0x1) UNKNOWN PROPERTY
		bool bOnlyRelevantToOwner : 1; // 0x58:2(0x1)
		bool bAlwaysRelevant : 1; // 0x58:3(0x1)
		bool bReplicateMovement : 1; // 0x58:4(0x1)
		bool bCallPreReplication : 1; // 0x58:5(0x1)
		bool bCallPreReplicationForReplay : 1; // 0x58:6(0x1)
		bool bHidden : 1; // 0x58:7(0x1)
		bool bTearOff : 1; // 0x59:0(0x1)
		bool bForceNetAddressable : 1; // 0x59:1(0x1)
		bool bExchangedRoles : 1; // 0x59:2(0x1)
		bool bNetLoadOnClient : 1; // 0x59:3(0x1)
		bool bNetUseOwnerRelevancy : 1; // 0x59:4(0x1)
		bool bRelevantForNetworkReplays : 1; // 0x59:5(0x1)
		bool bRelevantForLevelBounds : 1; // 0x59:6(0x1)
		bool bReplayRewindable : 1; // 0x59:7(0x1)
		bool bAllowTickBeforeBeginPlay : 1; // 0x5A:0(0x1)
		bool bAutoDestroyWhenFinished : 1; // 0x5A:1(0x1)
		bool bCanBeDamaged : 1; // 0x5A:2(0x1)
		bool bBlockInput : 1; // 0x5A:3(0x1)
		bool bCollideWhenPlacing : 1; // 0x5A:4(0x1)
		bool bFindCameraComponentWhenViewTarget : 1; // 0x5A:5(0x1)
		bool bGenerateOverlapEventsDuringLevelStreaming : 1; // 0x5A:6(0x1)
		bool bIgnoresOriginShifting : 1; // 0x5A:7(0x1)
		bool bEnableAutoLODGeneration : 1; // 0x5B:0(0x1)
		bool bIsEditorOnlyActor : 1; // 0x5B:1(0x1)
		unsigned char UnknownBit01 : 1; // 0x5B:2(0x1) UNKNOWN PROPERTY
		bool bReplicates : 1; // 0x5B:3(0x1)
		bool bCanBeInCluster : 1; // 0x5B:4(0x1)
		bool bAllowReceiveTickEventOnDedicatedServer : 1; // 0x5B:5(0x1)
		unsigned char UnknownBit02 : 1; // 0x5B:6(0x1) UNKNOWN PROPERTY
		bool bReplicateUsingRegisteredSubObjectList : 1; // 0x5B:7(0x1)
		unsigned char UnknownBit03 : 1; // 0x5C:0(0x1) UNKNOWN PROPERTY
		unsigned char UnknownBit04 : 1; // 0x5C:1(0x1) UNKNOWN PROPERTY
		unsigned char UnknownBit05 : 1; // 0x5C:2(0x1) UNKNOWN PROPERTY
		unsigned char UnknownBit06 : 1; // 0x5C:3(0x1) UNKNOWN PROPERTY
		unsigned char UnknownBit07 : 1; // 0x5C:4(0x1) UNKNOWN PROPERTY
		unsigned char UnknownBit08 : 1; // 0x5C:5(0x1) UNKNOWN PROPERTY
		unsigned char UnknownBit09 : 1; // 0x5C:6(0x1) UNKNOWN PROPERTY
		bool bActorEnableCollision : 1; // 0x5C:7(0x1)
		bool bActorIsBeingDestroyed : 1; // 0x5D:0(0x1)
		unsigned char UnknownBit10 : 1; // 0x5D:1(0x1) UNKNOWN PROPERTY
		unsigned char UnknownBit11 : 1; // 0x5D:2(0x1) UNKNOWN PROPERTY
		unsigned char UnknownBit12 : 1; // 0x5D:3(0x1) UNKNOWN PROPERTY
		unsigned char UnknownBit13 : 1; // 0x5D:4(0x1) UNKNOWN PROPERTY
		bool bAsyncPhysicsTickEnabled : 1; // 0x5D:5(0x1)
		EActorUpdateOverlapsMethod UpdateOverlapsMethodDuringLevelStreaming; // 0x5E(0x1)
		EActorUpdateOverlapsMethod DefaultUpdateOverlapsMethodDuringLevelStreaming; // 0x5F(0x1)
		TEnumAsByte<ENetRole> RemoteRole; // 0x60(0x1)
		unsigned char UnknownData14_6[0x3]; // 0x61(0x3) UNKNOWN PROPERTY
		float InitialLifeSpan; // 0x64(0x4)
		float CustomTimeDilation; // 0x68(0x4)
		int32_t RayTracingGroupId; // 0x6C(0x4)
		FRepAttachment AttachmentReplication; // 0x70(0x60)
		FRepMovement ReplicatedMovement; // 0xD0(0x70)
		AActor* Owner; // 0x140(0x8)
		FName NetDriverName; // 0x148(0x4)
		TEnumAsByte<ENetRole> Role; // 0x14C(0x1)
		TEnumAsByte<ENetDormancy> NetDormancy; // 0x14D(0x1)
		ESpawnActorCollisionHandlingMethod SpawnCollisionHandlingMethod; // 0x14E(0x1)
		TEnumAsByte<EAutoReceiveInput> AutoReceiveInput; // 0x14F(0x1)
		int32_t InputPriority; // 0x150(0x4)
		unsigned char UnknownData15_6[0x4]; // 0x154(0x4) UNKNOWN PROPERTY
		UInputComponent* InputComponent; // 0x158(0x8)
		int32_t NetTag; // 0x160(0x4)
		float NetCullDistanceSquared; // 0x164(0x4)
		float NetUpdateFrequency; // 0x168(0x4)
		float MinNetUpdateFrequency; // 0x16C(0x4)
		float NetPriority; // 0x170(0x4)
		EPhysicsReplicationMode PhysicsReplicationMode; // 0x174(0x1)
		unsigned char UnknownData16_6[0xB]; // 0x175(0xB) UNKNOWN PROPERTY
		APawn* Instigator; // 0x180(0x8)
		TArray<AActor*> Children; // 0x188(0x10)
		USceneComponent* RootComponent; // 0x198(0x8)
		unsigned char UnknownData17_6[0x8]; // 0x1A0(0x8) UNKNOWN PROPERTY
		TArray<FName> Layers; // 0x1A8(0x10)
		TWeakObjectPtr<UChildActorComponent*> ParentComponent; // 0x1B8(0x8)
		unsigned char UnknownData18_6[0x10]; // 0x1C0(0x10) UNKNOWN PROPERTY
		TArray<FName> Tags; // 0x1D0(0x10)
		FMulticastSparseDelegate OnTakeAnyDamage; // 0x1E0(0x1)
		FMulticastSparseDelegate OnTakePointDamage; // 0x1E1(0x1)
		FMulticastSparseDelegate OnTakeRadialDamage; // 0x1E2(0x1)
		FMulticastSparseDelegate OnActorBeginOverlap; // 0x1E3(0x1)
		FMulticastSparseDelegate OnActorEndOverlap; // 0x1E4(0x1)
		FMulticastSparseDelegate OnBeginCursorOver; // 0x1E5(0x1)
		FMulticastSparseDelegate OnEndCursorOver; // 0x1E6(0x1)
		FMulticastSparseDelegate OnClicked; // 0x1E7(0x1)
		FMulticastSparseDelegate OnReleased; // 0x1E8(0x1)
		FMulticastSparseDelegate OnInputTouchBegin; // 0x1E9(0x1)
		FMulticastSparseDelegate OnInputTouchEnd; // 0x1EA(0x1)
		FMulticastSparseDelegate OnInputTouchEnter; // 0x1EB(0x1)
		FMulticastSparseDelegate OnInputTouchLeave; // 0x1EC(0x1)
		FMulticastSparseDelegate OnActorHit; // 0x1ED(0x1)
		FMulticastSparseDelegate OnDestroyed; // 0x1EE(0x1)
		FMulticastSparseDelegate OnEndPlay; // 0x1EF(0x1)
		unsigned char UnknownData19_6[0x80]; // 0x1F0(0x80) UNKNOWN PROPERTY
		TArray<UActorComponent*> InstanceComponents; // 0x270(0x10)
		TArray<UActorComponent*> BlueprintCreatedComponents; // 0x280(0x10)


namepsace VTables
{
	int ProcessEvent = 0x4F;
}
