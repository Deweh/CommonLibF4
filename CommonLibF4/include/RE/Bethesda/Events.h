#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSPointerHandle.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/UserEvents.h"
#include "RE/NetImmerse/NiSmartPointer.h"
#include "RE/Scaleform/GFx/GFx_Player.h"

namespace RE
{
	class BGSMessage;
	class TESObjectCELL;
	class TESObjectREFR;

	struct InventoryUserUIInterfaceEntry;

	struct BSThreadEvent
	{
	public:
		enum class Event
		{
			kOnStartup,
			kOnShutdown
		};

		static void InitSDM()
		{
			using func_t = decltype(&BSThreadEvent::InitSDM);
			REL::Relocation<func_t> func{ REL::ID(1425097) };
			return func();
		}
	};
	static_assert(std::is_empty_v<BSThreadEvent>);

	enum class QuickContainerMode : std::int32_t
	{
		kLoot,
		kTeammate,
		kPowerArmor,
		kTurret,
		kWorkshop,
		kCrafting,
		kStealing,
		kStealingPowerArmor
	};

	struct ApplyColorUpdateEvent
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<ApplyColorUpdateEvent>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			REL::Relocation<EventSource_t**> singleton{ REL::ID(421543) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}
	};
	static_assert(std::is_empty_v<ApplyColorUpdateEvent>);

	class CanDisplayNextHUDMessage :
		public BSTValueEvent<bool>
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<CanDisplayNextHUDMessage>;

	public:
		CanDisplayNextHUDMessage(bool a_value)
		{
			optionalValue = a_value;
		}

		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			REL::Relocation<EventSource_t**> singleton{ REL::ID(344866) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}
	};

	struct CellAttachDetachEvent
	{
	public:
		enum class EVENT_TYPE
		{
			kPreAttach,
			kPostAttach,
			kPreDetach,
			kPostDetach
		};

		// members
		TESObjectCELL* cell;                              // 00
		stl::enumeration<EVENT_TYPE, std::int32_t> type;  // 08
	};
	static_assert(sizeof(CellAttachDetachEvent) == 0x10);

	class CurrentRadiationSourceCount :
		public BSTValueEvent<std::uint32_t>
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<CurrentRadiationSourceCount>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			REL::Relocation<EventSource_t**> singleton{ REL::ID(696410) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}
	};
	static_assert(sizeof(CurrentRadiationSourceCount) == 0x08);

	class CurrentRadsDisplayMagnitude :
		public BSTValueEvent<float>
	{
	public:
	};
	static_assert(sizeof(CurrentRadsDisplayMagnitude) == 0x08);

	class CurrentRadsPercentOfLethal :
		public BSTValueEvent<float>
	{
	public:
	};
	static_assert(sizeof(CurrentRadsPercentOfLethal) == 0x08);

	struct DoBeforeNewOrLoadCompletedEvent
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<DoBeforeNewOrLoadCompletedEvent>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			REL::Relocation<EventSource_t**> singleton{ REL::ID(787908) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}
	};
	static_assert(sizeof(DoBeforeNewOrLoadCompletedEvent) == 0x01);

	struct InventoryItemDisplayData
	{
	public:
		InventoryItemDisplayData(
			const ObjectRefHandle a_inventoryRef,
			const InventoryUserUIInterfaceEntry& a_entry)
		{
			ctor(a_inventoryRef, a_entry);
		}

		void PopulateFlashObject(Scaleform::GFx::Value& a_flashObject)
		{
			a_flashObject.SetMember("text"sv, itemName.c_str());
			a_flashObject.SetMember("count"sv, itemCount);
			a_flashObject.SetMember("equipState"sv, equipState);
			a_flashObject.SetMember("filterFlag"sv, filterFlag);
			a_flashObject.SetMember("isLegendary"sv, isLegendary);
			a_flashObject.SetMember("favorite"sv, isFavorite);
			a_flashObject.SetMember("taggedForSearch"sv, isTaggedForSearch);
			a_flashObject.SetMember("isBetterThanEquippedItem"sv, isBetterThanEquippedItem);
		}

		// members
		BSFixedStringCS itemName;                // 00
		std::uint32_t itemCount{ 0 };            // 08
		std::uint32_t equipState{ 0 };           // 0C
		std::uint32_t filterFlag{ 0 };           // 10
		bool isLegendary{ false };               // 14
		bool isFavorite{ false };                // 15
		bool isTaggedForSearch{ false };         // 16
		bool isBetterThanEquippedItem{ false };  // 17

	private:
		InventoryItemDisplayData* ctor(
			const ObjectRefHandle a_inventoryRef,
			const InventoryUserUIInterfaceEntry& a_entry)
		{
			using func_t = decltype(&InventoryItemDisplayData::ctor);
			REL::Relocation<func_t> func{ REL::ID(679373) };
			return func(this, a_inventoryRef, a_entry);
		}
	};
	static_assert(sizeof(InventoryItemDisplayData) == 0x18);

	class LocksPicked
	{
	public:
		struct Event
		{
		public:
		};

		[[nodiscard]] static BSTEventSource<LocksPicked::Event>* GetEventSource()
		{
			using func_t = decltype(&LocksPicked::GetEventSource);
			REL::Relocation<func_t> func{ REL::ID(594991) };
			return func();
		}
	};
	static_assert(std::is_empty_v<LocksPicked>);
	static_assert(std::is_empty_v<LocksPicked::Event>);

	class MenuModeChangeEvent
	{
	public:
		// members
		BSFixedString menuName;  // 00
		bool enteringMenuMode;   // 08
	};
	static_assert(sizeof(MenuModeChangeEvent) == 0x10);

	class MenuModeCounterChangedEvent
	{
	public:
		// members
		BSFixedString menuName;  // 00
		bool incrementing;       // 08
	};
	static_assert(sizeof(MenuModeCounterChangedEvent) == 0x10);

	class MenuOpenCloseEvent
	{
	public:
		// members
		BSFixedString menuName;  // 00
		bool opening;            // 08
	};
	static_assert(sizeof(MenuOpenCloseEvent) == 0x10);

	class PerkPointIncreaseEvent
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<PerkPointIncreaseEvent>;

	public:
		PerkPointIncreaseEvent(std::uint8_t a_perkCount) :
			perkCount(a_perkCount)
		{}

		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			REL::Relocation<EventSource_t**> singleton{ REL::ID(685859) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}

		// members
		std::uint8_t perkCount{ 0 };  // 00
	};
	static_assert(sizeof(PerkPointIncreaseEvent) == 0x1);

	class PipboyLightEvent :
		public BSTValueEvent<bool>
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<PipboyLightEvent>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			REL::Relocation<EventSource_t**> singleton{ REL::ID(1140080) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}
	};
	static_assert(sizeof(PipboyLightEvent) == 0x02);

	struct PlayerAmmoCounts
	{
	public:
		// members
		std::uint32_t clipAmmo;     // 00
		std::uint32_t reserveAmmo;  // 04
	};
	static_assert(sizeof(PlayerAmmoCounts) == 0x08);

	class PlayerAmmoCountEvent :
		public BSTValueEvent<PlayerAmmoCounts>
	{
	public:
	};
	static_assert(sizeof(PlayerAmmoCountEvent) == 0x0C);

	class PlayerWeaponReloadEvent :
		public BSTValueEvent<bool>
	{
	public:
	};
	static_assert(sizeof(PlayerWeaponReloadEvent) == 0x02);

	struct QuickContainerStateData
	{
	public:
		// members
		BSTSmallArray<InventoryItemDisplayData, 5> itemData;      // 00
		ObjectRefHandle containerRef;                             // 88
		ObjectRefHandle inventoryRef;                             // 8C
		BSFixedStringCS aButtonText;                              // 90
		BSFixedString containerName;                              // 98
		BSFixedStringCS perkButtonText;                           // A0
		std::int32_t selectedClipIndex;                           // A8
		stl::enumeration<QuickContainerMode, std::int32_t> mode;  // AC
		bool perkButtonEnabled;                                   // B0
		bool isNewContainer;                                      // B1
		bool addedDroppedItems;                                   // B2
		bool isLocked;                                            // B3
		bool buttonAEnabled;                                      // B4
		bool buttonXEnabled;                                      // B5
		bool refreshContainerSize;                                // B6
		bool containerActivated;                                  // B7
	};
	static_assert(sizeof(QuickContainerStateData) == 0xB8);

	class QuickContainerStateEvent :
		public BSTValueEvent<QuickContainerStateData>  // 00
	{
	public:
	};
	static_assert(sizeof(QuickContainerStateEvent) == 0xC0);

	struct TESContainerChangedEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESContainerChangedEvent>* GetEventSource()
		{
			using func_t = decltype(&TESContainerChangedEvent::GetEventSource);
			REL::Relocation<func_t> func{ REL::ID(242538) };
			return func();
		}

		// members
		std::uint32_t oldContainerFormID;  // 00
		std::uint32_t newContainerFormID;  // 04
		std::uint32_t baseObjectFormID;    // 08
		std::int32_t itemCount;            // 0C
		std::uint32_t referenceFormID;     // 10
		std::uint16_t uniqueID;            // 14
	};
	static_assert(sizeof(TESContainerChangedEvent) == 0x18);

	struct TESDeathEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> actorDying;   // 00
		NiPointer<TESObjectREFR> actorKiller;  // 08
		bool dead;                             // 10
	};
	static_assert(sizeof(TESDeathEvent) == 0x18);

	struct TESFurnitureEvent
	{
	public:
		enum class FurnitureEventType : std::int32_t
		{
			kEnter,
			kExit
		};

		[[nodiscard]] static BSTEventSource<TESFurnitureEvent>* GetEventSource()
		{
			using func_t = decltype(&TESFurnitureEvent::GetEventSource);
			REL::Relocation<func_t> func{ REL::ID(678665) };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> actor;                           // 00
		NiPointer<TESObjectREFR> targetFurniture;                 // 08
		stl::enumeration<FurnitureEventType, std::int32_t> type;  // 10
	};
	static_assert(sizeof(TESFurnitureEvent) == 0x18);

	struct TESMagicEffectApplyEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> target;  // 00
		NiPointer<TESObjectREFR> caster;  // 08
		std::uint32_t magicEffectFormID;  // 10
	};
	static_assert(sizeof(TESMagicEffectApplyEvent) == 0x18);

	class TutorialEvent
	{
	public:
		// members
		BSFixedString eventName;     // 00
		const BGSMessage* assocMsg;  // 08
	};
	static_assert(sizeof(TutorialEvent) == 0x10);

	class UserEventEnabledEvent
	{
	public:
		// members
		stl::enumeration<UserEvents::USER_EVENT_FLAG, std::int32_t> newUserEventFlag;  // 0
		stl::enumeration<UserEvents::USER_EVENT_FLAG, std::int32_t> oldUserEventFlag;  // 4
		stl::enumeration<UserEvents::SENDER_ID, std::int32_t> senderID;                // 8
	};
	static_assert(sizeof(UserEventEnabledEvent) == 0xC);

	namespace CellAttachDetachEventSource
	{
		struct CellAttachDetachEventSourceSingleton :
			public BSTSingletonImplicit<CellAttachDetachEventSourceSingleton>
		{
		public:
			[[nodiscard]] static CellAttachDetachEventSourceSingleton& GetSingleton()
			{
				using func_t = decltype(&CellAttachDetachEventSourceSingleton::GetSingleton);
				REL::Relocation<func_t> func{ REL::ID(862142) };
				return func();
			}

			// members
			BSTEventSource<CellAttachDetachEvent> source;  // 00
		};
		static_assert(sizeof(CellAttachDetachEventSourceSingleton) == 0x58);
	}
}
