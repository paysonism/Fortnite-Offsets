// Current Patch: v39.20

struct FPlane : public FVector {
  double W;
};

struct FMatrix {
  union {
    struct {
      FPlane XPlane;
      FPlane YPlane;
      FPlane ZPlane;
      FPlane WPlane;
    };
    double m[4][4];
  };

  FMatrix() : m{{0}} {}
  ~FMatrix() {}
};

template <class T> struct TArray {
  friend struct FString;

public:
  inline TArray() {
    Data = 0;
    Count = 0;
    Max = 0;
  };

  inline T Get(int i) {
    if (!kernel)
      return T{};
    return kernel->Read<T>(Data + (i * sizeof(T)));
  };

  uintptr_t Data;
  int32_t Count;
  int32_t Max;
};

struct CamPosition {
  FVector location{};
  FVector rotation{};
  float fov{};
};
inline CamPosition camPos{};

struct FNRot {
  double a;
  double b;
  double c;
};

class SDK {
public:
  CamPosition GetCamera() {
    CamPosition view_point{};
    uintptr_t location_pointer =
        kernel->Read<uintptr_t>(cache.uWorld + offsets::CameraLocation);
    uintptr_t rotation_pointer =
        kernel->Read<uintptr_t>(cache.uWorld + offsets::CameraRotation);

    FNRot fnrot{};
    fnrot.a = kernel->Read<double>(rotation_pointer);
    fnrot.b = kernel->Read<double>(rotation_pointer + 0x20);
    fnrot.c = kernel->Read<double>(rotation_pointer + 0x1D0);

    view_point.location = kernel->Read<FVector>(location_pointer);

    view_point.rotation.x = asin(fnrot.c) * (180.0 / M_PI);
    view_point.rotation.y =
        (((atan2(fnrot.a * -1, fnrot.b) * (180.0 / M_PI)) * -1) * -1);
    view_point.rotation.z = 0.0;

    view_point.fov = kernel->Read<float>(cache.playerController + offsets::CameraFOV) * 90.f;

    return view_point;
  }

  bool IsScreenPointOnScreen(const FVector2D &point, float margin = 0.0f) {
    if (point.x < -margin || point.y < -margin ||
        point.x > window.screenWidth + margin ||
        point.y > window.screenHeight + margin) {
      return false;
    }
    return true;
  }
};
