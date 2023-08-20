#pragma once

#include "RE/NetImmerse/NiPoint4.h"

namespace RE
{
	class alignas(0x10) NiMatrix3
	{
	public:
		void MakeIdentity() noexcept
		{
			entry[0].v = { 1.0F, 0.0F, 0.0F, 0.0F };
			entry[1].v = { 0.0F, 1.0F, 0.0F, 0.0F };
			entry[2].v = { 0.0F, 0.0F, 1.0F, 0.0F };
		}

		bool ToEulerAnglesXYZ(float* angleX, float* angleY, float* angleZ)
		{
			using func_t = decltype(&NiMatrix3::ToEulerAnglesXYZ);
			REL::Relocation<func_t> func{ REL::ID(34114) };
			return func(this, angleX, angleY, angleZ);
		}

		bool FromEulerAnglesXYZ(float angleX, float angleY, float angleZ)
		{
			using func_t = decltype(&NiMatrix3::FromEulerAnglesXYZ);
			REL::Relocation<func_t> func{ REL::ID(124665) };
			return func(this, angleX, angleY, angleZ);
		}

		bool FromEulerAnglesZXY(float angleZ, float angleX, float angleY)
		{
			using func_t = decltype(&NiMatrix3::FromEulerAnglesZXY);
			REL::Relocation<func_t> func{ REL::ID(326460) };
			return func(this, angleX, angleY, angleZ);
		}

		bool FromEulerAnglesYXZ(float angleY, float angleX, float angleZ)
		{
			using func_t = decltype(&NiMatrix3::FromEulerAnglesYXZ);
			REL::Relocation<func_t> func{ REL::ID(55761) };
			return func(this, angleY, angleX, angleZ);
		}

		// members
		NiPoint4 entry[3];  // 00
	};
	static_assert(sizeof(NiMatrix3) == 0x30);
}
