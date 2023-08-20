#pragma once

namespace RE
{
	class NiQuaternion
	{
	public:
		float w;  // 00
		float x;  // 04
		float y;  // 08
		float z;  // 0C

		void ToRotation(NiMatrix3* a_rotation) const {
			using func_t = decltype(&NiQuaternion::ToRotation);
			REL::Relocation<func_t> func{ REL::ID(1379385) };
			return func(this, a_rotation);
		}

		//x = pitch, y = roll, z = yaw
		void FromEulerAnglesXYZ(float a_X, float a_Y, float a_Z) {
			using func_t = decltype(&NiQuaternion::FromEulerAnglesXYZ);
			REL::Relocation<func_t> func{ REL::ID(896501) };
			return func(this, a_X, a_Y, a_Z);
		}
	};
	static_assert(sizeof(NiQuaternion) == 0x10);
}
