#pragma once

#include "RE/NetImmerse/NiMatrix3.h"
#include "RE/NetImmerse/NiPoint3.h"

namespace RE
{
	class NiTransform
	{
	public:
		void MakeIdentity() noexcept
		{
			rotate.MakeIdentity();
			translate = NiPoint3{};
			scale = 1.0F;
		}

		void InvertNonUniform(NiTransform& result) const
		{
			using func_t = decltype(&NiTransform::InvertNonUniform);
			REL::Relocation<func_t> func{ REL::ID(34114) };
			return func(this, result);
		}

		void Invert(NiTransform& result) const
		{
			using func_t = decltype(&NiTransform::Invert);
			REL::Relocation<func_t> func{ REL::ID(34114) };
			return func(this, result);
		}

		NiTransform& Multiply(NiTransform& result, const NiTransform& rhs) const
		{
			using func_t = decltype(&NiTransform::Multiply);
			REL::Relocation<func_t> func{ REL::ID(34114) };
			return func(this, result, rhs);
		}

		NiTransform WorldToLocal(const NiTransform& parentWorldTransform) const
		{
			RE::NiTransform parentInverse;
			parentWorldTransform.InvertNonUniform(parentInverse);
			RE::NiTransform result;
			parentInverse.Multiply(result, *this);
			return result;
		}

		// members
		NiMatrix3 rotate;     // 00
		NiPoint3 translate;   // 30
		float scale{ 1.0F };  // 3C
	};
	static_assert(sizeof(NiTransform) == 0x40);
}
