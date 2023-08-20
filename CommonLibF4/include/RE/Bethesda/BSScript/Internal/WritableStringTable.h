#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSTObjectArena.h"

namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			enum class StringIndexSize;

			class WritableStringTable
			{
			public:
				// members
				msvc::unique_ptr<BSTObjectArena<BSFixedString>> stringTable;                         // 00
				msvc::unique_ptr<BSTScrapHashMap<BSFixedString, std::uint32_t>> stringReferenceMap;  // 08
				stl::enumeration<StringIndexSize, std::int32_t> indexSize;                           // 10
			};
			static_assert(sizeof(WritableStringTable) == 0x18);
		}
	}
}
