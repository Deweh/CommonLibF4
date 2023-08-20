#pragma once

#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTSingleton.h"

namespace RE
{
	class BGSSynchronizedAnimationInstance;

	struct AnimationDataSetupEvent;
	struct AnimationDataCleanupEvent;

	class __declspec(novtable) BGSSynchronizedAnimationManager :
		public BSTEventSink<AnimationDataSetupEvent>,            // 00
		public BSTEventSink<AnimationDataCleanupEvent>,          // 08
		public BSTSingletonSDM<BGSSynchronizedAnimationManager>  // 10
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSynchronizedAnimationManager };
		static constexpr auto VTABLE{ VTABLE::BGSSynchronizedAnimationManager };

		virtual ~BGSSynchronizedAnimationManager();  // 00

		// override
		virtual BSEventNotifyControl ProcessEvent(const AnimationDataSetupEvent&, BSTEventSource<AnimationDataSetupEvent>*) override;      // 01
		virtual BSEventNotifyControl ProcessEvent(const AnimationDataCleanupEvent&, BSTEventSource<AnimationDataCleanupEvent>*) override;  // 02

		[[nodiscard]] static BGSSynchronizedAnimationManager* GetSingleton()
		{
			REL::Relocation<BGSSynchronizedAnimationManager**> singleton{ REL::ID(1346879) };
			return *singleton;
		}

		[[nodiscard]] bool IsReferenceInSynchronizedScene(ObjectRefHandle a_ref)
		{
			using func_t = decltype(&BGSSynchronizedAnimationManager::IsReferenceInSynchronizedScene);
			REL::Relocation<func_t> func{ REL::ID(915329) };
			return func(this, a_ref);
		}

		// members
		BSTArray<BSTSmartPointer<BGSSynchronizedAnimationInstance>> currentSynchAnims;  // 18
		BSReadWriteLock synchAnimsLock;                                                 // 30
		std::int32_t atomicSyncLock;                                                    // 38
		BSSpinLock internalsLock;                                                       // 3C
	};
	static_assert(sizeof(BGSSynchronizedAnimationManager) == 0x48);
}
