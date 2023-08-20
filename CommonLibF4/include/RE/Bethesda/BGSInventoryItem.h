#pragma once

#include "RE/Bethesda/BSExtraData.h"
#include "RE/Bethesda/BSTSmartPointer.h"

namespace RE
{
	namespace BGSMod
	{
		namespace Attachment
		{
			class Mod;
		}
	}

	class TESBoundObject;

	class BGSInventoryItem
	{
	public:
		class __declspec(novtable) Stack :
			public BSIntrusiveRefCounted  // 08
		{
		public:
			static constexpr auto RTTI{ RTTI::BGSInventoryItem__Stack };
			static constexpr auto VTABLE{ VTABLE::BGSInventoryItem__Stack };

			enum class Flag
			{
				kSlotIndex1 = 1 << 0,
				kSlotIndex2 = 1 << 1,
				kSlotIndex3 = 1 << 2,
				kEquipStateLocked = 1 << 3,
				kInvShouldEquip = 1 << 4,
				kTemporary = 1 << 5,
				kSlotMask = kSlotIndex1 | kSlotIndex2 | kSlotIndex3
			};

			virtual ~Stack();  // 00

			[[nodiscard]] std::uint32_t GetCount() const noexcept { return count; }
			[[nodiscard]] bool IsEquipped() const noexcept { return flags.any(Flag::kSlotMask); }

			// members
			BSTSmartPointer<Stack> nextStack;             // 10
			BSTSmartPointer<ExtraDataList> extra;         // 18
			std::uint32_t count;                          // 20
			stl::enumeration<Flag, std::uint16_t> flags;  // 24
		};
		static_assert(sizeof(Stack) == 0x28);

		class __declspec(novtable) StackDataCompareFunctor
		{
		public:
			static constexpr auto RTTI{ RTTI::BGSInventoryItem__StackDataCompareFunctor };
			static constexpr auto VTABLE{ VTABLE::BGSInventoryItem__StackDataCompareFunctor };

			// add
			virtual bool CompareData(const BGSInventoryItem::Stack& a_stack) = 0;  // 00
			virtual bool UseDefaultStackIfNoMatch() const { return false; }        // 01
		};
		static_assert(sizeof(StackDataCompareFunctor) == 0x8);

		class alignas(0x08) CheckStackIDFunctor :
			public StackDataCompareFunctor  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::BGSInventoryItem__CheckStackIDFunctor };
			static constexpr auto VTABLE{ VTABLE::BGSInventoryItem__CheckStackIDFunctor };

			CheckStackIDFunctor(std::uint32_t a_targetIndex) noexcept :
				targetIndex(a_targetIndex)
			{}

			// override (StackDataCompareFunctor)
			bool CompareData(const BGSInventoryItem::Stack&) override { return targetIndex-- == 0; }  // 00

			// members
			std::uint32_t targetIndex;  // 08
		};
		static_assert(sizeof(CheckStackIDFunctor) == 0x10);

		class __declspec(novtable) alignas(0x08) StackDataWriteFunctor
		{
		public:
			static constexpr auto RTTI{ RTTI::BGSInventoryItem__StackDataWriteFunctor };
			static constexpr auto VTABLE{ VTABLE::BGSInventoryItem__StackDataWriteFunctor };

			// add
			virtual void WriteDataImpl(TESBoundObject& a_baseObj, BGSInventoryItem::Stack& a_stack) = 0;  // 01

			// members
			bool shouldSplitStacks{ true };              // 08
			bool transferEquippedToSplitStack{ false };  // 09
		};
		static_assert(sizeof(StackDataWriteFunctor) == 0x10);

		class __declspec(novtable) ModifyModDataFunctor :
			public StackDataWriteFunctor  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::BGSInventoryItem__ModifyModDataFunctor };
			static constexpr auto VTABLE{ VTABLE::BGSInventoryItem__ModifyModDataFunctor };

			ModifyModDataFunctor(BGSMod::Attachment::Mod* a_mod, std::int8_t a_slotIndex, bool a_attach, bool* a_success) :
				mod(a_mod),
				success(a_success),
				slotIndex(a_slotIndex),
				attach(a_attach)
			{
				stl::emplace_vtable(this);
				if (success) {
					*success = true;
				}
			}

			// override (StackDataWriteFunctor)
			void WriteDataImpl(TESBoundObject&, BGSInventoryItem::Stack&) override;  // 01

			// members
			BGSMod::Attachment::Mod* mod;         // 10
			TESBoundObject* foundObj{ nullptr };  // 18
			bool* success;                        // 20
			const std::int8_t slotIndex;          // 28
			const bool attach;                    // 29
			bool equipLocked{ false };            // 2A
		};
		static_assert(sizeof(ModifyModDataFunctor) == 0x30);

		bool FindAndWriteStackData(StackDataCompareFunctor& a_compareFunc, StackDataWriteFunctor& a_writeFunc, bool a_manualMerge, ObjectRefHandle a_owner)
		{
			using func_t = decltype(&BGSInventoryItem::FindAndWriteStackData);
			REL::Relocation<func_t> func{ REL::ID(770140) };
			return func(this, a_compareFunc, a_writeFunc, a_manualMerge, a_owner);
		}

		[[nodiscard]] std::uint32_t GetCount() const noexcept;
		[[nodiscard]] Stack* GetStackByID(std::uint32_t a_stackID) const
		{
			auto iter = stackData.get();
			while (a_stackID--) {
				iter = iter->nextStack.get();
			}

			return iter;
		}

		[[nodiscard]] const char* GetDisplayFullName(std::uint32_t a_stackID)
		{
			using func_t = decltype(&BGSInventoryItem::GetDisplayFullName);
			REL::Relocation<func_t> func{ REL::ID(277641) };
			return func(this, a_stackID);
		}

		[[nodiscard]] TBO_InstanceData* GetInstanceData(std::uint32_t a_stackID)
		{
			using func_t = decltype(&BGSInventoryItem::GetInstanceData);
			REL::Relocation<func_t> func{ REL::ID(491493) };
			return func(this, a_stackID);
		}

		[[nodiscard]] std::int32_t GetInventoryValue(std::uint32_t a_stackID, bool a_scale) const
		{
			using func_t = decltype(&BGSInventoryItem::GetInventoryValue);
			REL::Relocation<func_t> func{ REL::ID(430292) };
			return func(this, a_stackID, a_scale);
		}

		// members
		TESBoundObject* object;            // 00
		BSTSmartPointer<Stack> stackData;  // 08
	};
	static_assert(sizeof(BGSInventoryItem) == 0x10);

	class __declspec(novtable) ApplyChangesFunctor :
		public BGSInventoryItem::StackDataWriteFunctor  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::__ApplyChangesFunctor };
		static constexpr auto VTABLE{ VTABLE::__ApplyChangesFunctor };

		// override
		virtual void WriteDataImpl(TESBoundObject& a_baseObj, BGSInventoryItem::Stack& a_stack) override  // 01
		{
			using func_t = decltype(&ApplyChangesFunctor::WriteDataImpl);
			REL::Relocation<func_t> func{ REL::ID(1291190) };
			return func(this, a_baseObj, a_stack);
		}

		// members
		BGSObjectInstanceExtra* extra;       // 10
		TESBoundObject* object;              // 18
		const BGSMod::Attachment::Mod* mod;  // 20
		std::uint8_t rank;                   // 28
		bool remove;                         // 29
		bool excludeTemporary;               // 2A
		std::int8_t favoriteIndex;           // 2B
	};
	static_assert(sizeof(ApplyChangesFunctor) == 0x30);
}
