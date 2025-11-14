// Current Patch: v38.10

namespace offsets {
    uintptr_t UWorld = 0x173bdd18; // updated: 0x16a439c0 -> 0x173bdd18
    uintptr_t GNames = 0x167B6600;

    uintptr_t LocalPlayers = 0x38;
    uintptr_t PlayerController = 0x30;
    uintptr_t PlayerCameraManager = 0x360;
    uintptr_t AcknowledgedPawn = 0x358; // updated: 0x350 -> 0x358
    uintptr_t PlayerState = 0x2d0;
    uintptr_t TeamIndex = 0x11a9; // updated: 0x1191 -> 0x11a9
    uintptr_t b_is_dying = 0x728;
    uintptr_t B_IS_DBNO = 0x841;

    uintptr_t Platform = 0x440; // updated: 0x438 -> 0x440
    uintptr_t TargetedFortPawn = 0x1900;
    uintptr_t KillScore = 0x11A8; // updated: 0x11A8 -> 0x11C0 (real offset name is KillCount)
    uintptr_t PlayerName = 0xA00; // updated: 0x9F8 -> 0xA00
    uintptr_t ranked_progress = 0xD8;
    uintptr_t PlayerAim = 0x2BC0; // updated: 0x2D38 -> 0x2BC0

    uintptr_t OwningGameInstance = 0x248;
    uintptr_t GameState = 0x1D0;
    uintptr_t PlayerArray = 0x2c8;
    uintptr_t RootComponent = 0x1B0;
    uintptr_t PawnPrivate = 0x328;
    uintptr_t AActor = 0x128; // updated: 0x128 -> 0x168 (from AActors in game_defs)
    uintptr_t PersistentLevel = 0x40;

    uintptr_t Mesh = 0x330;
    uintptr_t BoneArray = 0x5E8;
    uintptr_t bonecache = 0x5F8;
    uintptr_t bonestide = 0x60;
    uintptr_t ComponentToWorld = 0x1E0;
    uintptr_t RelativeLocation = 0x140;
    uintptr_t AdditionalAimOffset = 0x2D20;
    uintptr_t CameraFOV = 0x3B4;

    uintptr_t CameraLocation = 0x180;
    uintptr_t CameraRotation = 0x190;


    uintptr_t current_vehicle = 0x2C18; // updated: 0x2C08 -> 0x2C18

    uintptr_t current_weapon = 0x990;
    uintptr_t weapon_data = 0x5A0; // updated: 0x5d0 -> 0x5A0
    uintptr_t AmmoCount = 0x14d4; // updated: 0x1174 -> 0x14d4
    uintptr_t ItemName = 0x40;

    uintptr_t projectile_speed = 0x2488; // updated: 0x24F4 -> 0x2488
    uintptr_t projectile_gravity = 0x21d8; // updated: 0x24F8 -> 0x21d8
    uintptr_t ComponentVelocity = 0x188;

    uintptr_t PrimaryPickupItemEntry = 0x3A8; // updated: 0x3A0 -> 0x3A8
    uintptr_t ItemDefinition = 0x10;
    uintptr_t ItemRarity = 0xAA;
    uintptr_t Tier = 0xA2;
    uintptr_t Rarity = 0xAA;
    uintptr_t bAlreadySearched = 0xD52; // updated: 0xDD2 -> 0xD52
    uintptr_t HabaneroComponent = 0x940; // updated: 0x938 -> 0x940
    uintptr_t Levels = 0x1E8;
};

// I'm back updating offsets. Stay tuned and star the repo for me to continue updating these every single update!
// Will be adding a bunch of stuff tomorrow. (JSON, SDK, Camera, etc.)
// Also stay tuned for some FN API stuff.
