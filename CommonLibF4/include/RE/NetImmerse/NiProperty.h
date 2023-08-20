#pragma once

#include "RE/NetImmerse/NiObjectNET.h"

namespace RE
{
	class NiUpdateData
	{
	public:
		int unk01 = 0;
		int64_t unk02 = 0;
		int64_t unk03 = 0;
		int unk04 = 0;
	};

	class __declspec(novtable) NiProperty :
		public NiObjectNET  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NiProperty };
		static constexpr auto VTABLE{ VTABLE::NiProperty };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiProperty };

		// add
		virtual std::int32_t Type() const = 0;            // 28
		virtual void Update(NiUpdateData& a_updateData);  // 29
	};
	static_assert(sizeof(NiProperty) == 0x28);
}
