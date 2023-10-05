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

		void Slerp(float a_time, const NiQuaternion& a_begin, const NiQuaternion& a_end)
		{
			using func_t = decltype(&NiQuaternion::Slerp);
			REL::Relocation<func_t> func{ REL::ID(1338018) };
			return func(this, a_time, a_begin, a_end);
		}

		NiQuaternion& UnitInverse(const NiQuaternion& q)
		{
			using func_t = decltype(&NiQuaternion::UnitInverse);
			REL::Relocation<func_t> func{ REL::ID(1310622) };
			return func(this, q);
		}

		NiQuaternion& operator*=(const NiQuaternion& rhs)
		{
			using func_t = decltype(&NiQuaternion::operator*=);
			REL::Relocation<func_t> func{ REL::ID(804852) };
			return func(this, rhs);
		}
	};
	static_assert(sizeof(NiQuaternion) == 0x10);
}
