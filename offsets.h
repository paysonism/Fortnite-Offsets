pragma once
#include <cstdint>
#include <unordered_map>
#include <fstream>

// Current Patch: v39.20

namespace offsets {

    // ===== Globals =====
    uintptr_t UWorld = 0x17B96228; // updated: 0x175C9368 -> 0x17B96228
    uintptr_t UWorldXorKey = 0x7B40E797ULL; // updated: 0x603662288ULL -> 0x7B40E797ULL
    uintptr_t GNames = 0x17A50D00; // updated: 0x17541600 -> 0x17A50D00
    uintptr_t GEngine = 0x175CAC68;
    uintptr_t GObjects = 0x17B2DC58; // updated: 0x17560EC0 -> 0x17B2DC58
    uintptr_t GObjectsCount = 0x17560ED4;
    uintptr_t StaticFindObject = 0x5E4332;

    uintptr_t ProcessEvent = 0x949CA;
    uintptr_t ProcessEventIndex = 0x98;

    // ===== Player / Controller =====
    uintptr_t LocalPlayers = 0x38;
    uintptr_t PlayerController = 0x30;
    uintptr_t PlayerCameraManager = 0x368;
    uintptr_t AcknowledgedPawn = 0x358;
    uintptr_t PlayerState = 0x2D0;
    uintptr_t TeamIndex = 0x11B1; // updated: 0x11A9 -> 0x11B1
    uintptr_t bIsDying = 0x728;
    uintptr_t bIsDBNO = 0x841;
    uintptr_t bIsABot = 0x2BA;

    uintptr_t Platform = 0x440;
    uintptr_t TargetedFortPawn = 0x1830; // updated: 0x1840 -> 0x1830
    uintptr_t KillScore = 0x11C8; // updated: 0x11C0 -> 0x11C8
    uintptr_t RebootCount = 0x1894; // updated: 0x188C -> 0x1894
    uintptr_t PlayerName = 0xA08; // updated: 0xA00 -> 0xA08
    uintptr_t PlayerNamePrivate = 0x348; // added
    uintptr_t RankedProgress = 0xD8;
    uintptr_t PlayerAimOffset = 0x2BD0; // updated: 0x2BF8 -> 0x2BD0

    // ===== World =====
    uintptr_t OwningGameInstance = 0x240; // updated: 0x250 -> 0x240
    uintptr_t GameState = 0x1C8; // updated: 0x1D8 -> 0x1C8
    uintptr_t PlayerArray = 0x2C8;
    uintptr_t WorldSettings = 0x2B8;
    uintptr_t WorldGravityZ = 0x330;
    uintptr_t WorldToMeters = 0x320;
    uintptr_t WorldTick = 0x198;

    uintptr_t PersistentLevel = 0x40;
    uintptr_t Levels = 0x1E0; // updated: 0x1F0 -> 0x1E0

    // ===== Actor / Pawn =====
    uintptr_t AActor = 0x208; // updated: 0x38 -> 0x208
    uintptr_t RootComponent = 0x1B0;
    uintptr_t PawnPrivate = 0x328;
    uintptr_t MoveIgnoreActors = 0x348;
    uintptr_t SuperField = 0x40;

    // ===== Mesh / Components =====
    uintptr_t Mesh = 0x330;
    uintptr_t BoneArray = 0x5F0;
    uintptr_t BoneCache = 0x5F8;
    uintptr_t MeshDeformerInstances = 0x5C0;

    uintptr_t ComponentToWorld = 0x1E0;
    uintptr_t RelativeLocation = 0x140;
    uintptr_t RelativeRotation = 0x158;
    uintptr_t RelativeScale3D = 0x170;
    uintptr_t ComponentVelocity = 0x188;
    uintptr_t AdditionalAimOffset = 0x2BA0; // updated: 0x2BC8 -> 0x2BA0
    uintptr_t LastRenderTime = 0x328; // updated: 0x324 -> 0x328
    uintptr_t LocationUnderReticle = 0x2A50; // updated: 0x2A78 -> 0x2A50

    // ===== Camera =====
    uintptr_t CameraLocation = 0x178;
    uintptr_t CameraRotation = 0x188;
    uintptr_t CameraFOV = 0x3B4;

    // ===== Vehicles =====
    uintptr_t CurrentVehicle = 0x2C58; // updated: 0x2C48 -> 0x2C58

    // ===== Weapons =====
    uintptr_t CurrentWeapon = 0x990;
    uintptr_t WeaponData = 0x688; // updated: 0x698 -> 0x688
    uintptr_t WeaponOffsetCorrection = 0x2C00; // updated: 0x2C28 -> 0x2C00
    uintptr_t AmmoCount = 0x11CC; // updated: 0x154C -> 0x11CC
    uintptr_t ReloadAnimation = 0x1608; // updated: 0x1948 -> 0x1608
    uintptr_t LWProjectile_ActivateRemovedTimestamp = 0x2968; // updated: 0x29C8 -> 0x2968

    uintptr_t ProjectileSpeed = 0x29DC; // updated: 0x2720 -> 0x29DC
    uintptr_t ProjectileGravity = 0x29E0; // updated: 0x2724 -> 0x29E0
    uintptr_t MaxTargetingAimAdjustPerSecond = 0x23D0; // updated: 0x23E8 -> 0x23D0
    uintptr_t ServerWorldTimeSecondsDelta = 0x2E8;

    // ===== Items / Loot =====
    uintptr_t PrimaryPickupItemEntry = 0x3A8;
    uintptr_t ItemName = 0x40;
    uintptr_t ItemType = 0xA8;
    uintptr_t ItemTier = 0xA2;
    uintptr_t ItemRarity = 0xAA;
    uintptr_t Rarity = 0xAA;
    uintptr_t bAlreadySearched = 0xD52;

    // ===== Misc =====
    uintptr_t HabaneroComponent = 0x948; // updated: 0x940 -> 0x948
};

// Offsets from https://github.com/paysonism/Fortnite-Offsets
