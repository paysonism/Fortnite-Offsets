#pragma once
#include <cstdint>
#include <unordered_map>
#include <fstream>

// Current Patch: v39.11

namespace offsets {

    // ===== Globals =====
    uintptr_t UWorld = 0x175C9368; // updated: 0x176869E8 -> 0x175C9368
    uintptr_t UWorldXorKey = 603662288ULL; // updated: 0xBF4617A5ULL -> 0x603662288ULL
    uintptr_t GNames = 0x17531600; // updated: 0x175746C0 -> 0x17531600
    uintptr_t GEngine = 0x175CAC68;
    uintptr_t GObjects = 0x17560EC0; // updated: 0x176515C8 -> 0x17560EC0
    uintptr_t GObjectsXorKey = 0x12576490; // updated: 0xBC0BA8E -> 0x12576490
    uintptr_t GObjectsArrayXorKey = 0xF555A5AF; // updated: 0xFFFFFFFF91478091ULL -> 0xF555A5AF
    uintptr_t GObjectsCount = 0x17560ED4; // updated: 0x176515C0 -> 0x17560ED4
    uintptr_t StaticFindObject = 0x5E4332; // updated: 0x64618E -> 0x5E4332

    uintptr_t ProcessEvent = 0x949CA; // updated: 0x83A74 -> 0x949CA
    uintptr_t ProcessEventIndex = 0x98; // updated: 0x78 -> 0x98

    // ===== Player / Controller =====
    uintptr_t LocalPlayers = 0x38;
    uintptr_t PlayerController = 0x30;
    uintptr_t PlayerCameraManager = 0x368;
    uintptr_t AcknowledgedPawn = 0x358;
    uintptr_t PlayerState = 0x2D0;
    uintptr_t TeamIndex = 0x11A9;
    uintptr_t bIsDying = 0x728;
    uintptr_t bIsDBNO = 0x841;
    uintptr_t bIsABot = 0x2BA;

    uintptr_t Platform = 0x440;
    uintptr_t TargetedFortPawn = 0x1840; // updated: 0x1820 -> 0x1840
    uintptr_t KillScore = 0x11C0; // updated: 0x11E0 -> 0x11C0
    uintptr_t RebootCount = 0x188C;
    uintptr_t PlayerName = 0xA00;
    uintptr_t CachedPreviousWorldPlayerId = 0x9F8;
    uintptr_t RankedProgress = 0xD8;
    uintptr_t PlayerAimOffset = 0x2BF8;

    // ===== World =====
    uintptr_t OwningGameInstance = 0x250; // updated: 0x240 -> 0x250
    uintptr_t GameState = 0x1D8; // updated: 0x1C8 -> 0x1D8
    uintptr_t PlayerArray = 0x2C8;
    uintptr_t WorldSettings = 0x2B8;
    uintptr_t WorldGravityZ = 0x330;
    uintptr_t WorldToMeters = 0x320;
    uintptr_t WorldTick = 0x198;

    uintptr_t PersistentLevel = 0x40; // updated: 0x38 -> 0x40
    uintptr_t Levels = 0x1F0; // updated: 0x1E0 -> 0x1F0

    // ===== Actor / Pawn =====
    uintptr_t AActor = 0x38;
    uintptr_t RootComponent = 0x1B0;
    uintptr_t PawnPrivate = 0x328;
    uintptr_t MoveIgnoreActors = 0x348;
    uintptr_t SuperField = 0x40;

    // ===== Mesh / Components =====
    uintptr_t Mesh = 0x330;
    uintptr_t BoneArray = 0x5F0;
    uintptr_t BoneCache = 0x5F8; // updated: 0x600 -> 0x5F8
    uintptr_t MeshDeformerInstances = 0x5C0;
    uintptr_t BonesTide = 0x60;

    uintptr_t ComponentToWorld = 0x1E0;
    uintptr_t RelativeLocation = 0x140;
    uintptr_t RelativeRotation = 0x158;
    uintptr_t RelativeScale3D = 0x170;
    uintptr_t ComponentVelocity = 0x188;
    uintptr_t AdditionalAimOffset = 0x2BC8;
    uintptr_t LastRenderTime = 0x198;
    uintptr_t LocationUnderReticle = 0x2A78;

    // ===== Camera =====
    uintptr_t CameraLocation = 0x178; // updated: 0x180 -> 0x178
    uintptr_t CameraRotation = 0x188; // updated: 0x190 -> 0x188
    uintptr_t CameraFOV = 0x3B4;

    // ===== Vehicles =====
    uintptr_t CurrentVehicle = 0x2C48;

    // ===== Weapons =====
    uintptr_t CurrentWeapon = 0x990;
    uintptr_t WeaponData = 0x5D8; // updated: 0x5C0 -> 0x5D8
    uintptr_t WeaponOffsetCorrection = 0x2C28;
    uintptr_t AmmoCount = 0x150C; // updated: 0x1464 -> 0x150C
    uintptr_t ReloadAnimation = 0x1948; // updated: 0x1928 -> 0x1948
    uintptr_t LWProjectile_ActivateRemovedTimestamp = 0x29C8; // updated: 0x29F8 -> 0x29C8

    uintptr_t ProjectileSpeed = 0x24F4; // updated: 0x26E4 -> 0x24F4
    uintptr_t ProjectileGravity = 0x24F8; // updated: 0x26E8 -> 0x24F8
    uintptr_t MaxTargetingAimAdjustPerSecond = 0x23E8; // updated: 0x2338 -> 0x23E8
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
    uintptr_t HabaneroComponent = 0x940;
};

// Offsets from https://github.com/paysonism/Fortnite-Offsets
