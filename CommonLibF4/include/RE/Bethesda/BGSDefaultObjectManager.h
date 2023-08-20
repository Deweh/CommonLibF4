#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSTSingleton.h"
#include "RE/Bethesda/TESForms.h"

namespace RE
{
	enum class DEFAULT_OBJECT
	{
		kSittingAngleLimit = 1,
		kAllowPlayerShout,
		kGold,
		kLockpick,
		kSkeletonKey,
		kPlayerFaction,
		kGuardFaction,
		kBattleMusic,
		kDeathMusic,
		kDungeonClearedMusic,
		kPlayerVoiceMale,
		kPlayerVoiceMaleChild,
		kPlayerVoiceFemale,
		kPlayerVoiceFemaleChild,
		kEatPackageDefaultFood,
		kVoiceEquip,
		kPotionEquip,
		kEveryActorAbility,
		kCommandedActorAbility,
		kDrugWearsOffImageSpace,
		kFootstepSet,
		kLandscapeMaterial,
		kDragonLandZoneMarker,
		kDragonCrashZoneMarker,
		kCombatStyle,
		kDefaultPackList,
		kWaitForDialoguePackage,
		kVirtualLocation,
		kPersistAllLocation,
		kPathingTestNPC,
		kActionSwimStateChange,
		kActionLook,
		kActionLeftAttack,
		kActionLeftReady,
		kActionLeftRelease,
		kActionLeftInterrupt,
		kActionRightAttack,
		kActionRightReady,
		kActionRightRelease,
		kActionRightInterrupt,
		kActionDualAttack,
		kActionDualRelease,
		kActionActivate,
		kActionJump,
		kActionFall,
		kActionLand,
		kActionMantle,
		kActionSneak,
		kActionVoice,
		kActionVoiceReady,
		kActionVoiceRelease,
		kActionVoiceInterrupt,
		kActionIdle,
		kActionSprintStart,
		kActionSprintStop,
		kActionDraw,
		kActionSheath,
		kActionLeftPowerAttack,
		kActionRightPowerAttack,
		kActionDualPowerAttack,
		kActionLeftSyncAttack,
		kActionRightSyncAttack,
		kActionStaggerStart,
		kActionBlockHit,
		kActionBlockAnticipate,
		kActionRecoil,
		kActionLargeRecoil,
		kActionBleedoutStart,
		kActionBleedoutStop,
		kActionIdleStop,
		kActionWardHit,
		kActionForceEquip,
		kActionShieldChange,
		kActionPathStart,
		kActionPathEnd,
		kActionLargeMovementDelta,
		kActionFlyStart,
		kActionFlyStop,
		kActionHoverStart,
		kActionHoverStop,
		kActionBumpedInto,
		kActionSummonedStart,
		kActionDialogueTalking,
		kActionDialogueListen,
		kActionDialogueListenPositive,
		kActionDialogueListenNegative,
		kActionDialogueListenQuestion,
		kActionDialogueListenNeutral,
		kActionDialogueEnter,
		kActionDialogueExit,
		kActionDeath,
		kActionDeathWait,
		kActionIdleWarn,
		kActionMoveStart,
		kActionMoveStop,
		kActionTurnRight,
		kActionTurnLeft,
		kActionTurnStop,
		kActionMoveForward,
		kActionMoveBackward,
		kActionMoveLeft,
		kActionMoveRight,
		kActionKnockdown,
		kActionGetUp,
		kActionIdleStopInstant,
		kActionRagdollInstant,
		kActionWaterwalkStart,
		kActionReload,
		kActionBoltCharge,
		kActionSighted,
		kActionSightedRelease,
		kActionMelee,
		kActionFireSingle,
		kActionFireCharge,
		kActionFireChargeHold,
		kActionFireAuto,
		kActionFireEmpty,
		kActionThrow,
		kActionEnterCover,
		kActionExitCover,
		kActionCoverSprintStart,
		kActionShuffle,
		kActionPipboy,
		kActionPipboyClose,
		kActionPipboyZoom,
		kActionPipboyStats,
		kActionPipboyInventory,
		kActionPipboyData,
		kActionPipboyMap,
		kActionPipboyTab,
		kActionPipboyTabPrevious,
		kActionPipboySelect,
		kActionPipboyRadioOn,
		kActionPipboyRadioOff,
		kActionPipboyLoadHolotape,
		kActionPipboyInspect,
		kActionNonSupportContact,
		kActionInteractionEnter,
		kActionInteractionExit,
		kActionInteractionExitAlternate,
		kActionInteractionExitQuick,
		kActionIntimidate,
		kActionGunChargeStart,
		kActionGunDown,
		kActionGunRelaxed,
		kActionGunAlert,
		kActionGunReady,
		kActionFlipThrow,
		kActionEnterCombat,
		kActionExitCombat,
		kActionLimbCritical,
		kActionEvade,
		kActionDodge,
		kActionAoEAttack,
		kActionPanic,
		kActionCower,
		kActionTunnel,
		kActionHide,
		kPickupSoundGeneric,
		kPutdownSoundGeneric,
		kPickupSoundWeapon,
		kPutdownSoundWeapon,
		kPickupSoundArmor,
		kPutdownSoundArmor,
		kPickupSoundBook,
		kPutdownSoundBook,
		kPickupSoundIngredient,
		kPutdownSoundIngredient,
		kHarvestSound,
		kHarvestFailedSound,
		kWardBreakSound,
		kWardAbsorbSound,
		kWardDeflectSound,
		kMagicFailSound,
		kShoutFailSound,
		kHeartbeatSoundFast,
		kHeartbeatSoundSlow,
		kImagespaceLowHealth,
		kSoulCapturedSound,
		kNoActivationSound,
		kMapMenuLoopingSound,
		kDialogueVoiceCategory,
		kNonDialogueVoiceCategory,
		kSFXToFadeInDialogueCategory,
		kPauseDuringMenuCategoryFade,
		kPauseDuringMenuCategoryImmediate,
		kPauseDuringLoadingMenuCategory,
		kMusicSoundCategory,
		kStatsMuteCategory,
		kStatsMusic,
		kMasterSoundCategory,
		kDialogueOutputModel3D,
		kDialogueOutputModel2D,
		kPlayersOutputModel1stPerson,
		kPlayersOutputModel3rdPerson,
		kInterfaceOutputModel,
		kReverbType,
		kUnderwaterLoopSound,
		kUnderwaterReverbType,
		kKeywordHorse,
		kKeywordUndead,
		kKeywordNPC,

		kKeywordDummyObject = 204,
		kKeywordUseGeometryEmitter,
		kKeywordMustStop,
		kMaleFaceTextureSetHead,
		kMaleFaceTextureSetMouth,
		kMaleFaceTextureSetEyes,
		kFemaleFaceTextureSetHead,
		kFemaleFaceTextureSetMouth,
		kFemaleFaceTextureSetEyes,
		kImageSpaceModifierForInventoryMenu,
		kImageSpaceModifierForPipboyMenuInPowerArmor,
		kPackageTemplate,
		kMainMenuCell,
		kDefaultMovementTypeDefault,
		kDefaultMovementTypeSwim,
		kDefaultMovementTypeFly,
		kDefaultMovementTypeSneak,
		kKeywordSpecialFurniture,
		kKeywordFurnitureForces1stPerson,
		kKeywordFurnitureForces3rdPerson,
		kKeywordActivatorFurnitureNoPlayer,
		kTelekinesisGrabSound,
		kTelekinesisThrowSound,
		kWorldMapWeather,
		kHelpManualPC,
		kHelpManualXBox,
		kKeywordTypeAmmo,
		kKeywordTypeArmor,
		kKeywordTypeBook,
		kKeywordTypeIngredient,
		kKeywordTypeKey,
		kKeywordTypeMisc,
		kKeywordTypeSoulGem,
		kKeywordTypeWeapon,
		kKeywordTypePotion,
		kBaseWeaponEnchantment,
		kBaseArmorEnchantment,
		kBasePotion,
		kBasePoison,
		kKeywordDragon,
		kKeywordMovable,
		kArtObjectAbsorbEffect,
		kWeaponMaterialList,
		kArmorMaterialList,
		kKeywordDisallowEnchanting,
		kFavortravelmarkerlocation,
		kTeammateReadyWeapon,
		kKeywordHoldLocation,
		kKeywordCivilWarOwner,
		kKeywordCivilWarNeutral,
		kLocRefTypeCivilWarSoldier,
		kKeywordClearableLocation,
		kLocRefTypeResourceDestructible,
		kFormListHairColorList,
		kComplexSceneObject,
		kKeywordReusableSoulGem,
		kKeywordAnimal,
		kKeywordDaedra,
		kKeywordRobot,
		kKeywordNirnroot,
		kFightersGuildFaction,
		kMagesGuildFaction,
		kThievesGuildFaction,
		kDarkBrotherhoodFaction,
		kJarlFaction,
		kBunnyFaction,
		kPlayerIsVampireVariable,

		kRoadMarker = 272,
		kKeywordScaleActorTo10,
		kKeywordVampire,
		kKeywordForge,
		kKeywordCookingPot,
		kKeywordSmelter,
		kKeywordTanningRack,
		kHelpBasicLockpickingPC,
		kHelpBasicLockpickingConsole,
		kHelpBasicForging,
		kHelpBasicCooking,
		kHelpBasicSmelting,
		kHelpBasicTanning,
		kHelpBasicObjectCreation,
		kHelpBasicEnchanting,
		kHelpBasicSmithingWeapon,
		kHelpBasicSmithingArmor,
		kHelpBasicAlchemy,
		kHelpBarter,
		kHelpLevelingup,
		kHelpSkillsMenu,
		kHelpMapMenu,
		kHelpJournal,
		kHelpLowHealth,
		kHelpLowMagicka,
		kHelpLowStamina,
		kHelpJail,
		kHelpTeamateFavor,
		kHelpWeaponCharge,
		kHelpFavorites,
		kKinectHelpFormList,
		kImagespaceLoadscreen,
		kKeywordWeaponMaterialDaedric,
		kKeywordWeaponMaterialDraugr,
		kKeywordWeaponMaterialDraugrHoned,
		kKeywordWeaponMaterialDwarven,
		kKeywordWeaponMaterialEbony,
		kKeywordWeaponMaterialElven,
		kKeywordWeaponMaterialFalmer,
		kKeywordWeaponMaterialFalmerHoned,
		kKeywordWeaponMaterialGlass,
		kKeywordWeaponMaterialImperial,
		kKeywordWeaponMaterialIron,
		kKeywordWeaponMaterialOrcish,
		kKeywordWeaponMaterialSteel,
		kKeywordWeaponMaterialWood,
		kKeywordWeaponTypeBoundArrow,
		kKeywordArmorMaterialDaedric,
		kKeywordArmorMaterialDragonplate,
		kKeywordArmorMaterialDragonscale,
		kKeywordArmorMaterialDragonbone,
		kKeywordArmorMaterialDwarven,
		kKeywordArmorMaterialEbony,
		kKeywordArmorMaterialElven,
		kKeywordArmorMaterialElvenSplinted,
		kKeywordArmorMaterialFullLeather,
		kKeywordArmorMaterialGlass,
		kKeywordArmorMaterialHide,
		kKeywordArmorMaterialImperial,
		kKeywordArmorMaterialImperialHeavy,
		kKeywordArmorMaterialImperialReinforced,
		kKeywordArmorMaterialIron,
		kKeywordArmorMaterialIronBanded,
		kKeywordArmorMaterialOrcish,
		kKeywordArmorMaterialScaled,
		kKeywordArmorMaterialSteel,
		kKeywordArmorMaterialSteelPlate,
		kKeywordArmorMaterialStormcloak,
		kKeywordArmorMaterialStudded,
		kKeywordGenericCraftableKeyword01,
		kKeywordGenericCraftableKeyword02,
		kKeywordGenericCraftableKeyword03,
		kKeywordGenericCraftableKeyword04,
		kKeywordGenericCraftableKeyword05,
		kKeywordGenericCraftableKeyword06,
		kKeywordGenericCraftableKeyword07,
		kKeywordGenericCraftableKeyword08,
		kKeywordGenericCraftableKeyword09,
		kKeywordGenericCraftableKeyword10,
		kKeywordnullptrMOD,
		kKeywordJewelry,
		kKeywordCuirass,
		kLocalMapHidePlane,
		kSnowLODMaterial,
		kSnowLODMaterialHD,
		kDialogueImagespace,
		kDialogueFollowerQuest,
		kPotentialFollowerFaction,

		kVampireAvailablePerks = 361,

		kVampireRace = 363,
		kVampireSpells,
		kKeywordMount,
		kVerletCape,
		kFurnitureTestNPC,
		kKeywordConditionalExplosion,
		kDefaultLight1,
		kDefaultLight2,
		kDefaultLight3,
		kDefaultLight4,
		kPipboyLight,
		kActionBeginLoopingActivate,
		kActionEndLoopingActivate,
		kWorkshopPlayerOwnership,
		kQuestMarkerFollower,
		kQuestMarkerLocation,
		kQuestMarkerEnemy,
		kQuestMarkerEnemyAbove,
		kQuestMarkerEnemyBelow,
		kWorkshopMiscItemKeyword,
		kHeavyWeaponItemKeyword,
		kMineItemKeyword,
		kGrenadeItemKeyword,
		kChemItemKeyword,
		kAlcoholItemKeyword,
		kFoodItemKeyword,
		kRepairKitItemKeyword,
		kMedbagitemKeyword,
		kGlovesitemKeyword,
		kHelmetitemkeyword,
		kClothesitemkeyword,

		kTotal
	};

	enum class DEFAULT_OBJECT_TYPE
	{
		kMisc,
		kFacegen,
		kMovement,
		kActions,
		kItems,
		kSounds,
		kKeywords
	};

	struct DEFAULT_OBJECT_DATA
	{
	public:
		// members
		const char* name;                                            // 00
		stl::enumeration<ENUM_FORM_ID, std::uint8_t> type;           // 08
		std::uint32_t uniqueID;                                      // 0C
		stl::enumeration<DEFAULT_OBJECT_TYPE, std::int32_t> doType;  // 10
		const char* newObjectName;                                   // 18
	};
	static_assert(sizeof(DEFAULT_OBJECT_DATA) == 0x20);

	[[nodiscard]] inline std::span<DEFAULT_OBJECT_DATA, 394> GetDefaultObjectData()
	{
		REL::Relocation<DEFAULT_OBJECT_DATA(*)[394]> data{ REL::ID(838886) };
		return { *data };
	}

	class __declspec(novtable) BGSDefaultObjectManager :
		public TESForm,                                       // 00
		public BSTSingletonImplicit<BGSDefaultObjectManager>  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSDefaultObjectManager };
		static constexpr auto VTABLE{ VTABLE::BGSDefaultObjectManager };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kDOBJ };

		[[nodiscard]] static BGSDefaultObjectManager* GetSingleton()
		{
			using func_t = decltype(&BGSDefaultObjectManager::GetSingleton);
			REL::Relocation<func_t> func{ REL::ID(484974) };
			return func();
		}

		[[nodiscard]] TESForm* GetDefaultObject(DEFAULT_OBJECT a_obj) const noexcept
		{
			assert(a_obj < DEFAULT_OBJECT::kTotal);
			return objectInitArray[stl::to_underlying(a_obj)] ?
                       objectArray[stl::to_underlying(a_obj)] :
                       nullptr;
		}

		template <class T>
		[[nodiscard]] T* GetDefaultObject(DEFAULT_OBJECT a_obj) const  //
			requires(std::derived_from<T, TESForm> &&
					 !std::is_pointer_v<T> &&
					 !std::is_reference_v<T>)
		{
			const auto obj = GetDefaultObject(a_obj);
			return obj ? obj->As<T>() : nullptr;
		}

		// members
		TESForm* objectArray[stl::to_underlying(DEFAULT_OBJECT::kTotal)];  // 020
		bool objectInitArray[stl::to_underlying(DEFAULT_OBJECT::kTotal)];  // C70
	};
	static_assert(sizeof(BGSDefaultObjectManager) == 0xE00);

	class __declspec(novtable) BGSDefaultObject :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSDefaultObject };
		static constexpr auto VTABLE{ VTABLE::BGSDefaultObject };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kDFOB };

		BGSDefaultObject(const char* a_name, ENUM_FORM_ID a_formType, const char* a_description)
		{
			ctor(a_name, a_formType, a_description);
		}

		[[nodiscard]] static BSTArray<BGSDefaultObject*>* GetSingleton()
		{
			REL::Relocation<BSTArray<BGSDefaultObject*>**> singleton{ REL::ID(561749) };
			return *singleton;
		}

		template <class T = TESForm>
		[[nodiscard]] T* GetForm()
		{
			return form ? form->As<T>() : nullptr;
		}

		// members
		TESForm* form;                                      // 20
		stl::enumeration<ENUM_FORM_ID, std::uint8_t> type;  // 28
		BSFixedString formEditorID;                         // 30

	private:
		BGSDefaultObject* ctor(const char* a_name, ENUM_FORM_ID a_formType, const char* a_description)
		{
			using func_t = decltype(&BGSDefaultObject::ctor);
			REL::Relocation<func_t> func{ REL::ID(1144014) };
			return func(this, a_name, a_formType, a_description);
		}
	};
	static_assert(sizeof(BGSDefaultObject) == 0x38);
}
