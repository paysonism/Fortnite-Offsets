// Current Patch: v38.10

struct FPlane : Vector3 {
	double W;

	FPlane() : W(0) {}
	FPlane(double W) : W(W) {}
};

class FMatrix {
public:
	double M[4][4];
	FPlane XPlane, YPlane, ZPlane, WPlane;

	FMatrix() : XPlane(), YPlane(), ZPlane(), WPlane() {}
	FMatrix(FPlane XPlane, FPlane YPlane, FPlane ZPlane, FPlane WPlane)
		: XPlane(XPlane), YPlane(YPlane), ZPlane(ZPlane), WPlane(WPlane) {
	}

	D3DMATRIX ToD3DMATRIX() const {
		D3DMATRIX Result;
		Result._11 = XPlane.x; Result._12 = XPlane.y; Result._13 = XPlane.z; Result._14 = XPlane.W;
		Result._21 = YPlane.x; Result._22 = YPlane.y; Result._23 = YPlane.z; Result._24 = YPlane.W;
		Result._31 = ZPlane.x; Result._32 = ZPlane.y; Result._33 = ZPlane.z; Result._34 = ZPlane.W;
		Result._41 = WPlane.x; Result._42 = WPlane.y; Result._43 = WPlane.z; Result._44 = WPlane.W;
		return Result;
	}
};

struct FQuat {
	double X;
	double Y;
	double Z;
	double W;
};

struct FTransform final {
public:
	FQuat Rotation;
	Vector3 Translation;
	uint8_t Pad1C[0x8];
	Vector3 Scale3D;
	uint8_t Pad2C[0x8];

public:
	PFORCEINLINE FMatrix ToMatrixWithScale() const {
		const Vector3 Scale(
			(Scale3D.x == 0.0) ? 1.0 : Scale3D.x,
			(Scale3D.y == 0.0) ? 1.0 : Scale3D.y,
			(Scale3D.z == 0.0) ? 1.0 : Scale3D.z);

		const double X2 = Rotation.X + Rotation.X;
		const double Y2 = Rotation.Y + Rotation.Y;
		const double Z2 = Rotation.Z + Rotation.Z;
		const double XX2 = Rotation.X * X2;
		const double YY2 = Rotation.Y * Y2;
		const double ZZ2 = Rotation.Z * Z2;
		const double YZ2 = Rotation.Y * Z2;
		const double WX2 = Rotation.W * X2;
		const double XY2 = Rotation.X * Y2;
		const double WZ2 = Rotation.W * Z2;
		const double XZ2 = Rotation.X * Z2;
		const double WY2 = Rotation.W * Y2;

		FMatrix Matrix = FMatrix();

		Matrix.WPlane.x = Translation.x;
		Matrix.WPlane.y = Translation.y;
		Matrix.WPlane.z = Translation.z;

		Matrix.XPlane.x = (1.0 - (YY2 + ZZ2)) * Scale.x;
		Matrix.YPlane.y = (1.0 - (XX2 + ZZ2)) * Scale.y;
		Matrix.ZPlane.z = (1.0 - (XX2 + YY2)) * Scale.z;

		Matrix.ZPlane.y = (YZ2 - WX2) * Scale.z;
		Matrix.YPlane.z = (YZ2 + WX2) * Scale.y;

		Matrix.YPlane.x = (XY2 - WZ2) * Scale.y;
		Matrix.XPlane.y = (XY2 + WZ2) * Scale.x;

		Matrix.ZPlane.x = (XZ2 + WY2) * Scale.z;
		Matrix.XPlane.z = (XZ2 - WY2) * Scale.x;

		Matrix.XPlane.W = 0.0f;
		Matrix.YPlane.W = 0.0f;
		Matrix.ZPlane.W = 0.0f;
		Matrix.WPlane.W = 1.0f;

		return Matrix;
	}
};

struct Camera {
	Vector3 Location;
	Vector3 Rotation;
	float FieldOfView;
};

template<class Type>
class TArray {
public:
	TArray() : Data(nullptr), Count(std::int32_t()), Maxx(std::int32_t()) {}
	TArray(Type* Data, std::int32_t Count, std::int32_t Maxx) : Data(Data), Count(Count), Maxx(Maxx) {}

	const bool IsValid() const noexcept {
		return !(this->Data == nullptr);
	}

	const std::int32_t Size() const noexcept {
		return this->Count;
	}

	Type& operator[](std::int32_t Index) noexcept {
		return this->Data[Index];
	}

	const Type& operator[](std::int32_t Index) const noexcept {
		return this->Data[Index];
	}

	bool IsValidIndex(std::int32_t Index) const noexcept {
		return Index < this->Size();
	}

	Type* Data;
	std::int32_t Count;
	std::int32_t Maxx;
};

inline D3DMATRIX MatrixMultiplication(D3DMATRIX PM1, D3DMATRIX PM2) {
	D3DMATRIX POut;
	POut._11 = PM1._11 * PM2._11 + PM1._12 * PM2._21 + PM1._13 * PM2._31 + PM1._14 * PM2._41;
	POut._12 = PM1._11 * PM2._12 + PM1._12 * PM2._22 + PM1._13 * PM2._32 + PM1._14 * PM2._42;
	POut._13 = PM1._11 * PM2._13 + PM1._12 * PM2._23 + PM1._13 * PM2._33 + PM1._14 * PM2._43;
	POut._14 = PM1._11 * PM2._14 + PM1._12 * PM2._24 + PM1._13 * PM2._34 + PM1._14 * PM2._44;
	POut._21 = PM1._21 * PM2._11 + PM1._22 * PM2._21 + PM1._23 * PM2._31 + PM1._24 * PM2._41;
	POut._22 = PM1._21 * PM2._12 + PM1._22 * PM2._22 + PM1._23 * PM2._32 + PM1._24 * PM2._42;
	POut._23 = PM1._21 * PM2._13 + PM1._22 * PM2._23 + PM1._23 * PM2._33 + PM1._24 * PM2._43;
	POut._24 = PM1._21 * PM2._14 + PM1._22 * PM2._24 + PM1._23 * PM2._34 + PM1._24 * PM2._44;
	POut._31 = PM1._31 * PM2._11 + PM1._32 * PM2._21 + PM1._33 * PM2._31 + PM1._34 * PM2._41;
	POut._32 = PM1._31 * PM2._12 + PM1._32 * PM2._22 + PM1._33 * PM2._32 + PM1._34 * PM2._42;
	POut._33 = PM1._31 * PM2._13 + PM1._32 * PM2._23 + PM1._33 * PM2._33 + PM1._34 * PM2._43;
	POut._34 = PM1._31 * PM2._14 + PM1._32 * PM2._24 + PM1._33 * PM2._34 + PM1._34 * PM2._44;
	POut._41 = PM1._41 * PM2._11 + PM1._42 * PM2._21 + PM1._43 * PM2._31 + PM1._44 * PM2._41;
	POut._42 = PM1._41 * PM2._12 + PM1._42 * PM2._22 + PM1._43 * PM2._32 + PM1._44 * PM2._42;
	POut._43 = PM1._41 * PM2._13 + PM1._42 * PM2._23 + PM1._43 * PM2._33 + PM1._44 * PM2._43;
	POut._44 = PM1._41 * PM2._14 + PM1._42 * PM2._24 + PM1._43 * PM2._34 + PM1._44 * PM2._44;

	return POut;
}

inline D3DMATRIX Matrix(Vector3 Rot) {
	float RadPitch = (Rot.x * float(std::numbers::pi) / 180.f);
	float RadYaw = (Rot.y * float(std::numbers::pi) / 180.f);
	float RadRoll = (Rot.z * float(std::numbers::pi) / 180.f);

	float SP = sinf(RadPitch);
	float CP = cosf(RadPitch);
	float SY = sinf(RadYaw);
	float CY = cosf(RadYaw);
	float SR = sinf(RadRoll);
	float CR = cosf(RadRoll);

	D3DMATRIX Matrix;
	Matrix.m[0][0] = CP * CY;
	Matrix.m[0][1] = CP * SY;
	Matrix.m[0][2] = SP;
	Matrix.m[0][3] = 0.f;

	Matrix.m[1][0] = SR * SP * CY - CR * SY;
	Matrix.m[1][1] = SR * SP * SY + CR * CY;
	Matrix.m[1][2] = -SR * CP;
	Matrix.m[1][3] = 0.f;

	Matrix.m[2][0] = -(CR * SP * CY + SR * SY);
	Matrix.m[2][1] = CY * SR - CR * SP * SY;
	Matrix.m[2][2] = CR * CP;
	Matrix.m[2][3] = 0.f;

	Matrix.m[3][0] = 0;
	Matrix.m[3][1] = 0;
	Matrix.m[3][2] = 0;
	Matrix.m[3][3] = 1.f;

	return Matrix;
}