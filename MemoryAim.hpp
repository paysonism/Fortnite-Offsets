// Current Patch: Working

bool MemoryMove(Vector3 NewPos)
{
    kernel->write_t<Vector3>(cache::PlayerController + offsets::PlayerAimOffset, NewPos);
    return true;
}

void MemoryAim(uintptr_t TargetMeshs, Vector2 Target2d)
{
    Vector2 Target{};
    float Smoothness = settings::aimbot::aimbot;
    float Speed = 101.0f - Smoothness;
    if (Speed < 1.0f) Speed = 1.0f;

    float ScreenCenterX = static_cast<float>(Width) / 2;
    float ScreenCenterY = static_cast<float>(Height) / 2;

    if (Target2d.x > ScreenCenterX) {
        Target.x = -(ScreenCenterX - Target2d.x) * Speed;
        if (Target.x + ScreenCenterX > ScreenCenterX * 2)
            Target.x = 0;
    }
    else if (Target2d.x < ScreenCenterX) {
        Target.x = (Target2d.x - ScreenCenterX) * Speed;
        if (Target.x + ScreenCenterX < 0)
            Target.x = 0;
    }

    if (Target2d.y > ScreenCenterY) {
        Target.y = -(ScreenCenterY - Target2d.y) * Speed;
        if (Target.y + ScreenCenterY > ScreenCenterY * 2)
            Target.y = 0;
    }
    else if (Target2d.y < ScreenCenterY) {
        Target.y = (Target2d.y - ScreenCenterY) * Speed;
        if (Target.y + ScreenCenterY < 0)
            Target.y = 0;
    }

    float Scale = 5.0f;
    MemoryMove(Vector3(-Target.y / Scale, Target.x / Scale, 0));
}