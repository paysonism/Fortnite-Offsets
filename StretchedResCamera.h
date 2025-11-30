    void update_camera( uintptr_t view_state ) {
        auto projection = g_memory->read<fmatrix>( view_state + 0x940 );

        m_camera.rotation.pitch = asin( projection.z_plane.w ) * 180.0f / std::numbers::pi;
        m_camera.rotation.yaw = atan2( projection.y_plane.w , projection.x_plane.w ) * 180.0f / std::numbers::pi;
        m_camera.rotation.roll = 0.0f;

        m_camera.location.x = projection.m[ 3 ][ 0 ];
        m_camera.location.y = projection.m[ 3 ][ 1 ];
        m_camera.location.z = projection.m[ 3 ][ 2 ];

        auto fov_radians = 2.0f * atanf( 1.0f / static_cast< float >( g_memory->read<double>( view_state + 0x740 ) ) );
        m_camera.fov = fov_radians * 180.0f / std::numbers::pi;
    }

inline D3DMATRIX create_rotation_matrix( const frotator& rotation )
{
    auto rad_x = rotation.pitch * float( std::numbers::pi ) / 180.f;
    auto rad_y = rotation.yaw * float( std::numbers::pi ) / 180.f;
    auto rad_z = rotation.roll * float( std::numbers::pi ) / 180.f;

    auto sp = sinf( rad_x ) , cp = cosf( rad_x );
    auto sy = sinf( rad_y ) , cy = cosf( rad_y );
    auto sr = sinf( rad_z ) , cr = cosf( rad_z );

    D3DMATRIX matrix{};
    matrix.m[ 0 ][ 0 ] = cp * cy;
    matrix.m[ 0 ][ 1 ] = cp * sy;
    matrix.m[ 0 ][ 2 ] = sp;
    matrix.m[ 0 ][ 3 ] = 0.f;

    matrix.m[ 1 ][ 0 ] = sr * sp * cy - cr * sy;
    matrix.m[ 1 ][ 1 ] = sr * sp * sy + cr * cy;
    matrix.m[ 1 ][ 2 ] = -sr * cp;
    matrix.m[ 1 ][ 3 ] = 0.f;

    matrix.m[ 2 ][ 0 ] = -( cr * sp * cy + sr * sy );
    matrix.m[ 2 ][ 1 ] = cy * sr - cr * sp * sy;
    matrix.m[ 2 ][ 2 ] = cr * cp;
    matrix.m[ 2 ][ 3 ] = 0.f;

    matrix.m[ 3 ][ 0 ] = matrix.m[ 3 ][ 1 ] = matrix.m[ 3 ][ 2 ] = 0.0f;
    matrix.m[ 3 ][ 3 ] = 1.0f;

    return matrix;
}

    void viewpoint_thread( ) {
        while ( true ) {
            if ( world ) {
                if ( !view_state ) view_state = world->owning_game_instance( )->get_local_player( )->get_viewstate( );
                update_camera( view_state );
                {
                    auto aspect_ratio = static_cast< float >( screen_width ) / screen_height;
                    world_to_screen::inv_fov = tanf( this->m_camera.fov * static_cast< float >( std::numbers::pi ) / 360.0f ) / aspect_ratio;
                    world_to_screen::rotation_matrix = create_rotation_matrix( this->m_camera.rotation );
                }
                std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
            }
        }
    }