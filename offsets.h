#pragma once
#include <cstdint>
#include <unordered_map>
#include <fstream>

// Current Patch: v38.11

namespace offsets {
    uintptr_t UWorld = 0x175448B8; // updated: 0x173bdd18 -> 0x175448B8 (48 8B 0D ? ? ? ? E8 ? ? ? ? 48 39 C3)
    uintptr_t GNames = 0x167B6600;

    uintptr_t LocalPlayers = 0x38;
    uintptr_t PlayerController = 0x30;
    uintptr_t PlayerCameraManager = 0x360;
    uintptr_t AcknowledgedPawn = 0x358;
    uintptr_t PlayerState = 0x2D0;
    uintptr_t TeamIndex = 0x11A9;
    uintptr_t bIsDying = 0x728;
    uintptr_t bIsDBNO = 0x841;
    uintptr_t bIsABot = 0x2BA;

    uintptr_t Platform = 0x440;
    uintptr_t TargetedFortPawn = 0x1820; // updated: 0x1900 -> 0x1820 (from offsets_data.hpp)
    uintptr_t KillScore = 0x11A8; // NOT updated
    uintptr_t PlayerName = 0xA00; // (CachedPreviousWorldPlayerId)
    uintptr_t RankedProgress = 0xD8;
    uintptr_t PlayerAim = 0x2BC0;

    uintptr_t OwningGameInstance = 0x248;
    uintptr_t GameState = 0x1D0;
    uintptr_t PlayerArray = 0x2C8;
    uintptr_t WorldSettings = 0x2B8;
    uintptr_t worldgravityz = 0x330;
    uintptr_t WorldToMeters = 0x320;
    uintptr_t WorldTick = 0x198; // Seconds
    
    uintptr_t RootComponent = 0x1B0;
    uintptr_t PawnPrivate = 0x328;
    uintptr_t AActor = 0x38; // updated: 0x168 -> 0x38
    uintptr_t PersistentLevel = 0x38; // updated: 0x40 -> 0x38
    uintptr_t Levels = 0x1E8;
    uintptr_t SuperField = 0x40;
    uintptr_t StaticFindObject = 0x83F8E;

    uintptr_t Mesh = 0x330;
    uintptr_t BoneArray = 0x5E8;
    uintptr_t BoneCache = 0x5F8;
    uintptr_t BonesTide = 0x60;
    uintptr_t ComponentToWorld = 0x1E0;
    uintptr_t RelativeLocation = 0x140;
    uintptr_t RelativeScale3D = 0x170;
    uintptr_t ComponentVelocity = 0x188;
    uintptr_t AdditionalAimOffset = 0x2BA8; // updated: 0x2D20 -> 0x2BA8
    uintptr_t LastRenderTime = 0x32c;
    
    uintptr_t CameraLocation = 0x178; // updated: 0x180 -> 0x178
    uintptr_t CameraRotation = 0x188; // updated: 0x190 -> 0x188 (CameraLocation + 0x10)
    uintptr_t CameraFOV = 0x3B4;

    uintptr_t CurrentVehicle = 0x2C18; // (CurrentVehicle)

    uintptr_t CurrentWeapon = 0x990; // (CurrentWeapon)
    uintptr_t WeaponData = 0x598; // updated: 0x5A0 -> 0x598
    uintptr_t AmmoCount = 0x144C; // updated: 0x14d4 -> 0x144c
    uintptr_t ReloadAnimation = 0x19E8;
    uintptr_t ItemName = 0x40;

    uintptr_t ProjectileSpeed = 0x22A4; // updated: 0x2488 -> 0x22a4
    uintptr_t ProjectileGravity = 0x22A8; // updated: 0x21d8 -> 0x22a8
    uintptr_t MaxTargetingAimAdjustPerSecond = 0x2338;
    uintptr_t ServerWorldTimeSecondsDelta = 0x2E8;

    uintptr_t PrimaryPickupItemEntry = 0x3A8;
    uintptr_t ItemDefinition = 0x10;
    uintptr_t ItemType = 0xA8;
    uintptr_t ItemRarity = 0xAA;
    uintptr_t Tier = 0xA2;
    uintptr_t Rarity = 0xAA;
    uintptr_t bAlreadySearched = 0xD52;
    
    uintptr_t HabaneroComponent = 0x940;
    uintptr_t OverlappingBuildings = 0x1D48;
};

// https://github.com/paysonism/Fortnite-Offsets
