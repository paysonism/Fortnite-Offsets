#pragma once
#include <cstdint>
#include <unordered_map>
#include <fstream>

// Current Patch: v39.00

namespace offsets {
    uintptr_t UWorld = 0x17279220; // updated: 0x175448B8 -> 0x17279220
    uintptr_t GNames = 0x1711DC80; // updated: 0x167B6600 -> 0x1711DC80
    uintptr_t GObjects = 0x171FB7E4;
    uintptr_t GObjectsCount = 0x171FB7E4;

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
    uintptr_t TargetedFortPawn = 0x1820;
    uintptr_t KillScore = 0x11A8; // NOT updated
    uintptr_t PlayerName = 0xA00; // (CachedPreviousWorldPlayerId)
    uintptr_t RankedProgress = 0xD8;
    uintptr_t PlayerAimOffset = 0x2BE8; // updated: 0x2BC0 -> 0x2BE8

    uintptr_t OwningGameInstance = 0x248;
    uintptr_t GameState = 0x1D0;
    uintptr_t PlayerArray = 0x2C8;
    uintptr_t WorldSettings = 0x2B8;
    uintptr_t WorldGravityZ = 0x330;
    uintptr_t WorldToMeters = 0x320;
    uintptr_t WorldTick = 0x198; // Seconds
    
    uintptr_t RootComponent = 0x1B0;
    uintptr_t PawnPrivate = 0x328;
    uintptr_t AActor = 0x38;
    uintptr_t PersistentLevel = 0x38;
    uintptr_t Levels = 0x1E8;
    uintptr_t SuperField = 0x40;
    uintptr_t StaticFindObject = 0x83F8E;

    uintptr_t Mesh = 0x330;
    uintptr_t BoneArray = 0x5F8; // updated: 0x5E8 -> 0x5F8
    uintptr_t BoneCache = 0x5F8;
    uintptr_t BonesTide = 0x60;
    uintptr_t ComponentToWorld = 0x1E0;
    uintptr_t RelativeLocation = 0x140;
    uintptr_t RelativeScale3D = 0x170;
    uintptr_t ComponentVelocity = 0x188;
    uintptr_t AdditionalAimOffset = 0x2BB8; // updated: 0x2BA8 -> 0x2BB8
    uintptr_t LastRenderTime = 0x32C;
    uintptr_t LocationUnderReticle = 0x2A68;
    
    uintptr_t CameraLocation = 0x178;
    uintptr_t CameraRotation = 0x188; // (CameraLocation + 0x10)
    uintptr_t CameraFOV = 0x3B4;

    uintptr_t CurrentVehicle = 0x2C18; // (CurrentVehicle)

    uintptr_t CurrentWeapon = 0x990; // (CurrentWeapon)
    uintptr_t WeaponData = 0x5D8; // updated: 0x598 -> 0x5D8
    uintptr_t AmmoCount = 0x144C;
    uintptr_t ReloadAnimation = 0x19E8;
    uintptr_t ItemName = 0x40;

    uintptr_t ProjectileSpeed = 0x22A4;
    uintptr_t ProjectileGravity = 0x22A8;
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

// Offsets From: https://github.com/paysonism/Fortnite-Offsets