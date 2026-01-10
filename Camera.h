// Current Patch: v39.20

auto GetViewState() -> uintptr_t
    {
        if (!ptrs::local_players)
            return 0;

        TArray<uintptr_t> ViewState = memory_interface::read<TArray<uintptr_t>>(ptrs::local_players + 0xD0);
        return ViewState.Get(1);
    }

    Camera get_camera()
    {
        if (!ptrs::uworld || !ptrs::player_controller)
            return {};

        Camera view;

        auto mProjection = memory_interface::read<FMatrix>(GetViewState() + 0x940);
        view.rotation.x = RadiansToDegrees(std::asin(mProjection.ZPlane.W));
        view.rotation.y = RadiansToDegrees(std::atan2(mProjection.YPlane.W, mProjection.XPlane.W));
        view.rotation.z = 0.0;

        view.location.x = mProjection.m[3][0];
        view.location.y = mProjection.m[3][1];
        view.location.z = mProjection.m[3][2];
        float FieldOfView = atanf(1 / memory_interface::read<double>(GetViewState() + 0x740)) * 2;
        view.fov = (FieldOfView) * (180.f / M_PI);

        return view;
    }