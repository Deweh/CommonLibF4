#pragma once

namespace RE
{
	class NiQuaternion
	{
	public:
		float w{ 0.0f };  // 00
		float x{ 0.0f };  // 04
		float y{ 0.0f };  // 08
		float z{ 0.0f };  // 0C

		void FromRotation(const NiMatrix3& a_rotation) const
		{
			using func_t = decltype(&NiQuaternion::FromRotation);
			REL::Relocation<func_t> func{ REL::ID(616807) };
			return func(this, a_rotation);
		}

		void ToRotation(NiMatrix3& a_rotation) const
		{
			using func_t = decltype(&NiQuaternion::ToRotation);
			REL::Relocation<func_t> func{ REL::ID(1379385) };
			return func(this, a_rotation);
		}

		void FromEulerAnglesXYZ(float a_X, float a_Y, float a_Z)
		{
			using func_t = decltype(&NiQuaternion::FromEulerAnglesXYZ);
			REL::Relocation<func_t> func{ REL::ID(896501) };
			return func(this, a_X, a_Y, a_Z);
		}

		void FromAngleAxis(float angle, const RE::NiPoint3& axis)
		{
			using func_t = decltype(&NiQuaternion::FromAngleAxis);
			REL::Relocation<func_t> func{ REL::ID(965178) };
			return func(this, angle, axis);
		}

		void ToAngleAxis(float& angle, RE::NiPoint3& axis) const
		{
			using func_t = decltype(&NiQuaternion::ToAngleAxis);
			REL::Relocation<func_t> func{ REL::ID(1082915) };
			return func(this, angle, axis);
		}

		void Slerp(float a_time, const NiQuaternion& a_begin, const NiQuaternion& a_end)
		{
			using func_t = decltype(&NiQuaternion::Slerp);
			REL::Relocation<func_t> func{ REL::ID(1338018) };
			return func(this, a_time, a_begin, a_end);
		}

		NiQuaternion& Intermediate(const NiQuaternion& before, const NiQuaternion& current, const NiQuaternion& after)
		{
			using func_t = decltype(&NiQuaternion::Intermediate);
			REL::Relocation<func_t> func{ REL::ID(419306) };
			return func(this, before, current, after);
		}

		NiQuaternion& UnitInverse(const NiQuaternion& q)
		{
			using func_t = decltype(&NiQuaternion::UnitInverse);
			REL::Relocation<func_t> func{ REL::ID(1310622) };
			return func(this, q);
		}

		RE::NiQuaternion Invert() const {
			return { -w, x, y, z };
		}

		RE::NiQuaternion Abs() const {
			return { w < 0.0 ? -w : w, x, y, z };
		}

		NiQuaternion operator*(const NiQuaternion& a_rhs) const
		{
			return {
				a_rhs.w * w - a_rhs.x * x - a_rhs.y * y - a_rhs.z * z,
				a_rhs.w * x + a_rhs.x * w - a_rhs.y * z + a_rhs.z * y,
				a_rhs.w * y + a_rhs.x * z + a_rhs.y * w - a_rhs.z * x,
				a_rhs.w * z - a_rhs.x * y + a_rhs.y * x + a_rhs.z * w
			};
		}

		void operator*=(const NiQuaternion& a_rhs) {
			(*this) = operator*(a_rhs);
		}

		NiQuaternion operator*(float s) const
		{
			return { w * s, x * s, y * s, z * s };
		}

		NiQuaternion operator+(const NiQuaternion& a_rhs) const
		{
			return { w + a_rhs.w, x + a_rhs.x, y + a_rhs.y, z + a_rhs.z };
		}

		RE::NiQuaternion operator-(const RE::NiQuaternion& a_rhs) const
		{
			return { w - a_rhs.w, x - a_rhs.x, y - a_rhs.y, z - a_rhs.z };
		}

		RE::NiQuaternion operator/(float s) const
		{
			return { w / s, x / s, y / s, z / s };
		}

		RE::NiQuaternion operator-() const
		{
			return { -w, -x, -y, -z };
		}
	};
	static_assert(sizeof(NiQuaternion) == 0x10);
}
