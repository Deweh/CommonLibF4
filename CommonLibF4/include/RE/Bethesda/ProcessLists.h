#pragma once

#include "RE/Bethesda/BSSemaphore.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTSingleton.h"

namespace RE
{
	class BSTempEffect;
	class SyncQueueObj;

	class __declspec(novtable) ProcessLists :
		public BSTEventSink<PositionPlayerEvent>,  // 000
		public BSTSingletonSDM<ProcessLists>       // 008
	{
	public:
		static constexpr auto RTTI{ RTTI::ProcessLists };
		static constexpr auto VTABLE{ VTABLE::ProcessLists };

		virtual ~ProcessLists();  // 00

		// override
		virtual BSEventNotifyControl ProcessEvent(const PositionPlayerEvent&, BSTEventSource<PositionPlayerEvent>*) override;  // 01

		[[nodiscard]] static ProcessLists* GetSingleton()
		{
			REL::Relocation<ProcessLists**> singleton{ REL::ID(1569706) };
			return *singleton;
		}

		[[nodiscard]] bool AreHostileActorsNear(BSScrapArray<ActorHandle>* a_hostileActorArray)
		{
			using func_t = decltype(&ProcessLists::AreHostileActorsNear);
			REL::Relocation<func_t> func{ REL::ID(1053584) };
			return func(this, a_hostileActorArray);
		}

		[[nodiscard]] bool IsActorTargetingREFinPackage(const TESObjectREFR* a_actor, PTYPE a_type, bool a_onlyHigh)
		{
			using func_t = decltype(&ProcessLists::IsActorTargetingREFinPackage);
			REL::Relocation<func_t> func{ REL::ID(559542) };
			return func(this, a_actor, a_type, a_onlyHigh);
		}

		[[nodiscard]] std::int16_t RequestHighestDetectionLevelAgainstActor(Actor* a_actor, std::uint32_t& a_LOSCount)
		{
			using func_t = decltype(&ProcessLists::RequestHighestDetectionLevelAgainstActor);
			REL::Relocation<func_t> func{ REL::ID(1036693) };
			return func(this, a_actor, a_LOSCount);
		}

		void FinishShaderEffect(TESObjectREFR* a_refr, TESEffectShader* a_shader)
		{
			using func_t = decltype(&ProcessLists::FinishShaderEffect);
			REL::Relocation<func_t> func{ REL::ID(631860) };
			return func(this, a_refr, a_shader);
		}

		// members
		BSSemaphore movementSyncSema;                               // 010
		float crimeUpdateTimer;                                     // 018
		float removeExcessDeadTimer;                                // 01C
		std::int32_t numberHighActors;                              // 020
		std::int32_t numberFullyEnabledHighActors;                  // 024
		std::int32_t crimeNumber;                                   // 028
		ActorHandle statdetect;                                     // 02C
		bool runDetection;                                          // 030
		bool showDetectionStats;                                    // 031
		bool processHigh;                                           // 032
		bool processLow;                                            // 033
		bool processMHigh;                                          // 034
		bool processMLow;                                           // 035
		bool processSche;                                           // 036
		bool showSubtitle;                                          // 037
		bool updatingLowList;                                       // 038
		float secondsPassedNoProcess;                               // 03C
		BSTArray<ActorHandle> highActorHandles;                     // 040
		BSTArray<ActorHandle> lowActorHandles;                      // 058
		BSTArray<ActorHandle> middleHighActorHandles;               // 070
		BSTArray<ActorHandle> middleLowActorHandles;                // 088
		BSTArray<ActorHandle>* allProcesss[4];                      // 0A0
		BSSimpleList<Crime*>* globalCrimes[7];                      // 0C0
		BSTArray<NiPointer<BSTempEffect>> globalTempEffects;        // 0F8
		BSSpinLock globalEffectsLock;                               // 110
		BSTArray<NiPointer<BSTempEffect>> magicEffects;             // 118
		BSSpinLock magicEffectsLock;                                // 130
		BSTArray<NiPointer<BSTempEffect>> interfaceEffects;         // 138
		BSSpinLock interfaceEffectsLock;                            // 150
		BSSimpleList<MuzzleFlash*> referenceMuzzleFlashes;          // 158
		BSTArray<ObjectRefHandle> tempShouldMoves;                  // 168
		BSSimpleList<ActorHandle> aliveActors;                      // 180
		BSSimpleList<ActorHandle> idleChatterActors;                // 190
		BSSimpleList<ActorHandle> randomDialogueActors;             // 1A0
		BSTArray<ActorHandle> initPackageLocationsQueue;            // 1B0
		BSSpinLock packageLocationsQueueLock;                       // 1C8
		BSTArray<ActorHandle> initAnimPositionQueue;                // 1D0
		BSTArray<BSTSmartPointer<SyncQueueObj>> syncPositionQueue;  // 1E8
		float playerActionCommentTimer;                             // 200
		float playerKnockObjectCommentTimer;                        // 204
		std::uint32_t currentLowActor;                              // 208
		std::uint32_t currentMiddleHighActor;                       // 20C
		std::uint32_t currentMiddleLowActor;                        // 210
		bool runSchedules;                                          // 214
		bool runMovement;                                           // 215
		bool runAnimations;                                         // 216
		bool updateActorsInPlayerCell;                              // 217
	};
	static_assert(sizeof(ProcessLists) == 0x218);
}
