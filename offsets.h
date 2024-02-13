#pragma once
#include <cstdint>

namespace Addresses
{
	uintptr_t GWorld = 0x11770D88;
	uintptr_t GObjects = 0x11749AC0;
	uintptr_t GNames = 0x11944BC0;
	uintptr_t StaticFindObject = 0x12DD5C0;
	uintptr_t GetBoneMatrix = 0x142900C;
	uintptr_t LineOfSightTo = 0x627FB84;
}

namespace Offsets
{
	// main
	uintptr_t LocalPawn = 0x338;
	uintptr_t PlayerController = 0x30;
	uintptr_t LocalPlayers = 0x38;
	uintptr_t PlayerState = 0x2b0;
	uintptr_t GameState = 0x158;
	uintptr_t GameInstance = 0x1d0;
	uintptr_t PlayerArray = 0x2A8;
	uintptr_t RootC = 0x198;
	uintptr_t CachedActor = 0x308;
	uintptr_t ActorCount = 0xA8;
	uintptr_t TIndex = 0x10f1;
	uintptr_t BoneArray = 0x598;
	uintptr_t C2W = 0x1c0;
	uintptr_t Actor = 0xA0;
	uintptr_t ActorMesh = 0x318;
	uintptr_t CurrentActor(AActor) = 0xA8;
	uintptr_t PersistentLevel = 0x30;
	uintptr_t RelativeLocation = 0x120;
	uintptr_t DisplayName = 0x90;
	uintptr_t ComponetToWorld = 0x230;
	uintptr_t PawnPrivate = 0x308;

        uintptr_t Last_Render_Time = 0x2E8;
        uintptr_t Last_Render_Time_On_Screen = 0x2F0;
        uintptr_t Velocity = 0x168;
        uintptr_t DefaultFOV = 0x170;

        // Fort Weapon
        uintptr_t CurrentWeapons = 0xa20;
        uintptr_t bIsReloadingWeapon = 0x368; 
        uintptr_t bIsEquippingWeapon = 0x350;
	uintptr_t bIsChargingWeapon = 0x369;
	uintptr_t WeaponData = 0x4d0;
        uintptr_t AmmoCount = 0xe1c; 
        uintptr_t bIsTargeting = 0x581;
        uintptr_t GunName = 0x98;
        uintptr_t Tier = 0x11b;

        // Engine Character
        uintptr_t bIsCrouched = 0x45c;

        // Fort Pawn
	uintptr_t bIsDying = 0x758;
	uintptr_t bIsHiddenForDeath = 0x758;
	uintptr_t bIsKnockedback = 0x758;
	uintptr_t bIsStaggered = 0x759;
        uintptr_t bIsInvulnerable = 0x75a;
	uintptr_t bSpotted = 0x75a;
	uintptr_t bIsSliding = 0x75b;
	uintptr_t bWeaponHolstered = 0x939;
	uintptr_t bIsDBNO = 0x93a;
	uintptr_t LastRevivedFromDBNOTime = 0x994;
	uintptr_t bIsJumping = 0xa18;

        // PlayerState
        uintptr_t bIsABot = 0x29a;

}
