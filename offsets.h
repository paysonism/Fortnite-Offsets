#pragma once
#include <cstdint>
#include <unordered_map>
#include <fstream>

// Current Patch: v39.30 - Build 2

namespace offsets {

    // ===== Globals =====
    uintptr_t UWorld = 0x178685D8; // updated: 0x178C37A8 -> 0x178685D8
    uintptr_t UWorldXorKey = 0xFFFFFFFF30B9BBF9; // updated: 0xFFFFFFFFD599D092ULL -> 0xFFFFFFFF30B9BBF9
    uintptr_t UWorldXorRotationCount = 0; // (simple exponent : no ror8 this update)
    uintptr_t GNames = 0x1777E080; // updated: 0x17A50D00 -> 0x1777E080
    uintptr_t GEngine = 0x17869ED8; // updated: 0x178C50A8 -> 0x17869ED8
    uintptr_t GObjects = 0x1785AFB0; // updated: 0x17B2DC58 -> 0x1785AFB0
    uintptr_t GObjectsCount = 0x1785AFB8; // updated: 0x17560ED4 -> 0x1785AFB8
    uintptr_t GObjectsXorKey = 0xFFFFFFFFCCF54342ULL;
    uintptr_t GObjectsCountXorKey = 0x75DB1A01;
    uintptr_t StaticFindObject = 0x73AC13; // updated: 0x71B76C -> 0x73AC13
    uintptr_t StaticLoadObject = 0x960153;

    uintptr_t ProcessEvent = 0x86FAA; // updated: 0x63B7E -> 0x86FAA
    uintptr_t ProcessEventIndex = 71;
    uintptr_t DrawTransition = 0x513D88;
    uintptr_t BoneMatrix = 0x55B004;

    // ===== Player / Controller =====
    uintptr_t LocalPlayers = 0x38;
    uintptr_t PlayerController = 0x30;
    uintptr_t PlayerCameraManager = 0x360; // updated: 0x368 -> 0x360
    uintptr_t AcknowledgedPawn = 0x358;
    uintptr_t PlayerState = 0x2D0;
    uintptr_t NetConnection = 0x528;
    uintptr_t TeamIndex = 0x11B1;
    uintptr_t bIsDying = 0x728;
    uintptr_t bIsDBNO = 0x841;
    uintptr_t bIsABot = 0x2BA;

    uintptr_t Platform = 0x440;
    uintptr_t TargetedFortPawn = 0x1830;
    uintptr_t KillScore = 0x11C8;
    uintptr_t RebootCount = 0x1894;
    uintptr_t PlayerName = 0xA08;
    uintptr_t PlayerNamePrivate = 0x348;
    uintptr_t RankedProgress = 0xD8;
    uintptr_t PlayerAimOffset = 0x2BD0;

    // ===== World =====
    uintptr_t OwningGameInstance = 0x248; // updated: 0x240 -> 0x248
    uintptr_t GameState = 0x1D0; // updated: 0x1C8 -> 0x1D0
    uintptr_t PlayerArray = 0x2C8;
    uintptr_t WorldSettings = 0x2B8;
    uintptr_t WorldGravityZ = 0x330;
    uintptr_t WorldToMeters = 0x320;

    uintptr_t PersistentLevel = 0x40;
    uintptr_t Levels = 0x1E0;

    // ===== Actor / Pawn =====
    uintptr_t AActor = 0x208;
    uintptr_t RootComponent = 0x1B0;
    uintptr_t PawnPrivate = 0x328;
    uintptr_t MoveIgnoreActors = 0x348;
    uintptr_t SuperField = 0x40;

    // ===== Mesh / Components =====
    uintptr_t Mesh = 0x330;
    uintptr_t BoneArray = 0x5F0;
    uintptr_t BoneCache = 0x600; // updated: 0x5F8 -> 0x600
    uintptr_t MeshDeformerInstances = 0x5C0;

    uintptr_t ComponentToWorld = 0x1E0;
    uintptr_t RelativeLocation = 0x140;
    uintptr_t RelativeRotation = 0x158;
    uintptr_t RelativeScale3D = 0x170;
    uintptr_t ComponentVelocity = 0x188;
    uintptr_t AdditionalAimOffset = 0x2BA0;
    uintptr_t LastRenderTime = 0x328;
    uintptr_t LocationUnderReticle = 0x2A50;

    // ===== Camera =====
    uintptr_t CameraLocation = 0x180; // updated: 0x178 -> 0x180
    uintptr_t CameraRotation = 0x190; // updated: 0x188 -> 0x190
    uintptr_t CameraFOV = 0x3B4;

    // ===== Vehicles =====
    uintptr_t CurrentVehicle = 0x2C58;

    // ===== Weapons =====
    uintptr_t CurrentWeapon = 0x990;
    uintptr_t WeaponData = 0x600; // updated: 0x688 -> 0x600
    uintptr_t WeaponOffsetCorrection = 0x2C00;
    uintptr_t AmmoCount = 0x147C; // updated: 0x11CC -> 0x147C
    uintptr_t bIsReloadingWeapon = 0x3D1;
    uintptr_t ReloadAnimation = 0x1608;
    uintptr_t LWProjectile_ActivateRemovedTimestamp = 0x2968;

    uintptr_t ProjectileSpeed = 0x29DC;
    uintptr_t ProjectileGravity = 0x29E0;
    uintptr_t MaxTargetingAimAdjustPerSecond = 0x23D0;
    uintptr_t ServerWorldTimeSecondsDelta = 0x2E8;

    // ===== Items / Loot =====
    uintptr_t PrimaryPickupItemEntry = 0x3A8;
    uintptr_t ItemName = 0xB0;
    uintptr_t ItemType = 0xA8;
    uintptr_t PrimaryAssetOverride = 0xA9;
    uintptr_t ItemRarity = 0xAA;
    uintptr_t bAlreadySearched = 0xD52;

    // ===== Misc =====
    uintptr_t HabaneroComponent = 0x948;
};

// Offsets from https://github.com/paysonism/Fortnite-Offsets
// Need more offsets? Browse the full SDK at https://fnsdk.getneptune.tech today!