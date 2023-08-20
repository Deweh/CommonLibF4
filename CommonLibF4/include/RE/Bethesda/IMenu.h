#pragma once

#include "RE/Bethesda/Atomic.h"
#include "RE/Bethesda/BGSCreatedObjectManager.h"
#include "RE/Bethesda/BGSInventoryInterface.h"
#include "RE/Bethesda/BGSInventoryItem.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSInputEventUser.h"
#include "RE/Bethesda/BSPointerHandle.h"
#include "RE/Bethesda/BSSoundHandle.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSTInterpolator.h"
#include "RE/Bethesda/BSTOptional.h"
#include "RE/Bethesda/BSTSingleton.h"
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/Bethesda/BSTTuple.h"
#include "RE/Bethesda/Events.h"
#include "RE/Bethesda/InventoryUserUIUtils.h"
#include "RE/Bethesda/SWFToCodeFunctionHandler.h"
#include "RE/Bethesda/SendHUDMessage.h"
#include "RE/Bethesda/TESForms.h"
#include "RE/Bethesda/TESObjectREFRs.h"
#include "RE/Bethesda/UIMessage.h"
#include "RE/Bethesda/UIShaderFXInfo.h"
#include "RE/Bethesda/UserEvents.h"
#include "RE/NetImmerse/NiMatrix3.h"
#include "RE/NetImmerse/NiPoint2.h"
#include "RE/NetImmerse/NiPoint3.h"
#include "RE/NetImmerse/NiQuaternion.h"
#include "RE/NetImmerse/NiRect.h"
#include "RE/NetImmerse/NiSmartPointer.h"
#include "RE/NetImmerse/NiTexture.h"

namespace RE
{
	enum class ContainerMenuMode;
	enum class EQUIP_TYPE;

	namespace Workshop
	{
		struct BuildableAreaEvent;
		struct PlacementStatusEvent;
	}

	class BSInputEnableLayer;
	class BSGFxFunctionBase;
	class BSGFxShaderFXTarget;
	class ExamineMenu;
	class ExtraDataList;
	class MenuOpenCloseEvent;
	class MessageBoxData;
	class NiAVObject;
	class NiControllerManager;
	class NiControllerSequence;
	class NiTexture;
	class TESBoundObject;
	class TESForm;
	class TESObjectREFR;
	class UserEventEnabledEvent;
	class UsesBSGFXFunctionHandler;
	class WorkshopMenuGeometry;

	struct IdleInputEvent;
	struct InvInterfaceStateChangeEvent;
	struct LoadedInventoryModel;
	struct PickRefUpdateEvent;
	struct PipboyValueChangedEvent;
	struct UIAdvanceMenusFunctionCompleteEvent;

	enum class HUDColorTypes
	{
		kNoColorMultiplier = 0,
		kMenuNoColorBackground = 1,
		kGameplayHUDColor = 2,
		kPlayerSetColor = 3,
		kPowerArmorColorOnly = 4,
		kWarningColor = 5,
		kAltWarningColor = 6,
		kCustomColor = 7
	};

	enum class MENU_RENDER_CONTEXT : std::int32_t
	{
		kMenuDelete,
		kPreDisplay,
		kRenderScreenspace,
		kRenderCopyQuads,
		kRenderImagespace,
		kEnsureDisplayMenuCalled,
		kPostDisplay
	};

	enum class PIPBOY_PAGES : std::uint32_t
	{
		kStat,
		kInv,
		kData,
		kMap,
		kRadio
	};

	enum class UI_DEPTH_PRIORITY
	{
		kUndefined,
		k3DUnderHUD,
		kBook,
		kScope,
		kSWFLoader,
		kHUD,
		kStandard,
		kStandard3DModel,
		kPipboy,
		kTerminal,
		kGameMessage,
		kPauseMenu,
		kLoadingFader,
		kLoading3DModel,
		kLoadingMenu,
		kMessage,
		kButtonBarMenu,
		kButtonBarSupressingMenu,
		kDebug,
		kConsole,
		kCursor
	};

	enum class UI_MENU_FLAGS : std::uint32_t
	{
		kPausesGame = 1 << 0,
		kAlwaysOpen = 1 << 1,
		kUsesCursor = 1 << 2,
		kUsesMenuContext = 1 << 3,
		kModal = 1 << 4,
		kFreezeFrameBackground = 1 << 5,
		kOnStack = 1 << 6,
		kDisablePauseMenu = 1 << 7,
		kRequiresUpdate = 1 << 8,
		kTopmostRenderedMenu = 1 << 9,
		kUpdateUsesCursor = 1 << 10,
		kAllowSaving = 1 << 11,
		kRendersOffscreenTargets = 1 << 12,
		kInventoryItemMenu = 1 << 13,
		kDontHideCursorWhenTopmost = 1 << 14,
		kCustomRendering = 1 << 15,
		kAssignCursorToRenderer = 1 << 16,
		kApplicationMenu = 1 << 17,
		kHasButtonBar = 1 << 18,
		kIsTopButtonBar = 1 << 19,
		kAdvancesUnderPauseMenu = 1 << 20,
		kRendersUnderPauseMenu = 1 << 21,
		kUsesBlurredBackground = 1 << 22,
		kCompanionAppAllowed = 1 << 23,
		kFreezeFramePause = 1 << 24,
		kSkipRenderDuringFreezeFrameScreenshot = 1 << 25,
		kLargeScaleformRenderCacheMode = 1 << 26,
		kUsesMovementToDirection = 1 << 27
	};

	class __declspec(novtable) FlatScreenModel :
		public BSTSingletonSDM<FlatScreenModel>,                  // 08
		public BSTEventSink<UIAdvanceMenusFunctionCompleteEvent>  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::FlatScreenModel };
		static constexpr auto VTABLE{ VTABLE::FlatScreenModel };

		[[nodiscard]] static FlatScreenModel* GetSingleton()
		{
			REL::Relocation<FlatScreenModel**> singleton{ REL::ID(847741) };
			return *singleton;
		}

		// members
		BSFixedString customRendererName;  // 10
		void* model;                       // 18 - TODO
	};
	static_assert(sizeof(FlatScreenModel) == 0x20);

	class IMenu :
		public SWFToCodeFunctionHandler,  // 00
		public BSInputEventUser           // 10
	{
	public:
		static constexpr auto RTTI{ RTTI::IMenu };
		static constexpr auto VTABLE{ VTABLE::IMenu };

		using SWFToCodeFunctionHandler::operator new;
		using SWFToCodeFunctionHandler::operator delete;

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~IMenu()  // 00
		{
			if (uiMovie) {
				const auto id = Scaleform::GetCurrentThreadId();
				uiMovie->SetCaptureThread(id);

				const auto heap = uiMovie->GetHeap();
				if (heap) {
					heap->AssignToCurrentThread();
				}
			}
		}

		// override (BSInputEventUser)
		bool ShouldHandleEvent(const InputEvent* a_event) override  // 01
		{
			using func_t = decltype(&IMenu::ShouldHandleEvent);
			REL::Relocation<func_t> func{ REL::ID(1241790) };
			return func(this, a_event);
		}

		void HandleEvent(const ButtonEvent* a_event) override  // 08
		{
			if (menuObj.IsObject()) {
				auto strUserEvent = a_event->QUserEvent();
				if (a_event->disabled && CanHandleWhenDisabled(a_event)) {
					strUserEvent = a_event->QRawUserEvent();
				}

				if (inputEventHandlingEnabled && menuObj.HasMember("ProcessUserEvent")) {
					Scaleform::GFx::Value args[2];
					args[0] = strUserEvent.c_str();
					args[1] = a_event->QJustPressed();
					menuObj.Invoke("ProcessUserEvent", nullptr, args, 2);
				}
			}
		}

		// add
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message)  // 03
		{
			switch (*a_message.type) {
			case UI_MESSAGE_TYPE::kShow:
			case UI_MESSAGE_TYPE::kHide:
				return UI_MESSAGE_RESULTS::kHandled;
			case UI_MESSAGE_TYPE::kScaleformEvent:
				return ProcessScaleformEvent(uiMovie.get(), a_message.QData());
			case UI_MESSAGE_TYPE::kUpdateController:
				RefreshPlatform();
				return UI_MESSAGE_RESULTS::kPassOn;
			default:
				return UI_MESSAGE_RESULTS::kPassOn;
			}
		}

		virtual void AdvanceMovie(float a_timeDelta, [[maybe_unused]] std::uint64_t a_time)  // 04
		{
			if (uiMovie) {
				DoAdvanceMovie(a_timeDelta);
				hasDoneFirstAdvanceMovie = true;
			}
		}

		virtual void PreDisplay() { return; }   // 05
		virtual void PostDisplay() { return; }  // 06

		virtual bool PassesRenderConditionText(MENU_RENDER_CONTEXT a_reason, const BSFixedString& a_customRendererName) const  // 07
		{
			using func_t = decltype(&IMenu::PassesRenderConditionText);
			REL::Relocation<func_t> func{ REL::ID(937304) };
			return func(this, a_reason, a_customRendererName);
		}

		virtual void SetIsTopButtonBar([[maybe_unused]] bool a_isTopButtonBar) { return; }  // 08

		virtual void OnMenuStackChanged(const BSFixedString& a_topMenuName, bool a_passesTopMenuTest)  // 09
		{
			const bool topMenuTest = a_passesTopMenuTest || (a_topMenuName == "PauseMenu"sv && RendersUnderPauseMenu());
			if (passesTopMenuTest != topMenuTest) {
				passesTopMenuTest = topMenuTest;
				OnMenuDisplayStateChanged();
			}
		}

		virtual void OnMenuDisplayStateChanged() { return; }  // 0A

		virtual void OnAddedToMenuStack()  // 0B
		{
			menuFlags.set(UI_MENU_FLAGS::kOnStack);
			OnMenuDisplayStateChanged();
		}

		virtual void OnRemovedFromMenuStack()  // 0C
		{
			menuFlags.reset(UI_MENU_FLAGS::kOnStack);
			OnMenuDisplayStateChanged();
		}

		virtual bool CanAdvanceMovie(bool a_pauseMenuShowing)  // 0D
		{
			return !a_pauseMenuShowing || depthPriority > UI_DEPTH_PRIORITY::kGameMessage || AdvancesUnderPauseMenu();
		}

		virtual bool CanHandleWhenDisabled([[maybe_unused]] const ButtonEvent* a_event) { return false; }                      // 0E
		virtual bool OnButtonEventRelease([[maybe_unused]] const BSFixedString& a_eventName) { return false; }                 // 0F
		virtual bool CacheShaderFXQuadsForRenderer_Impl() { return false; }                                                    // 10
		virtual void TransferCachedShaderFXQuadsForRenderer([[maybe_unused]] const BSFixedString& a_rendererName) { return; }  // 11
		virtual void SetViewportRect([[maybe_unused]] const NiRect<float>& a_viewportRect) { return; }                         // 12

		[[nodiscard]] bool AdvancesUnderPauseMenu() const noexcept { return menuFlags.all(UI_MENU_FLAGS::kAdvancesUnderPauseMenu); }
		[[nodiscard]] bool AssignsCursorToRenderer() const noexcept { return menuFlags.all(UI_MENU_FLAGS::kAssignCursorToRenderer); }

		void DoAdvanceMovie(float a_timeDelta)
		{
			++advanceWithoutRenderCount;
			uiMovie->Advance(a_timeDelta);
		}

		void OnSetSafeRect()
		{
			using func_t = decltype(&IMenu::OnSetSafeRect);
			REL::Relocation<func_t> func{ REL::ID(964859) };
			return func(this);
		}

		[[nodiscard]] bool OnStack() const noexcept { return menuFlags.all(UI_MENU_FLAGS::kOnStack); }

		UI_MESSAGE_RESULTS ProcessScaleformEvent(Scaleform::GFx::Movie* a_movie, const IUIMessageData* a_data)
		{
			using func_t = decltype(&IMenu::ProcessScaleformEvent);
			REL::Relocation<func_t> func{ REL::ID(150211) };
			return func(this, a_movie, a_data);
		}

		void RefreshPlatform()
		{
			using func_t = decltype(&IMenu::RefreshPlatform);
			REL::Relocation<func_t> func{ REL::ID(1071829) };
			return func(this);
		}

		[[nodiscard]] bool RendersUnderPauseMenu() const noexcept { return menuFlags.all(UI_MENU_FLAGS::kRendersUnderPauseMenu); }

		[[nodiscard]] constexpr bool IsMenuDisplayEnabled() const noexcept { return passesTopMenuTest && menuCanBeVisible; }

		void SetMenuCodeObject(Scaleform::GFx::Movie& a_movie, stl::zstring a_menuObjPath)
		{
			a_movie.GetVariable(std::addressof(menuObj), a_menuObjPath.data());
			RegisterCodeObject(a_movie, menuObj);
		}

		void UpdateFlag(UI_MENU_FLAGS a_flag, bool a_set) noexcept
		{
			if (a_set) {
				menuFlags.set(a_flag);
			} else {
				menuFlags.reset(a_flag);
			}
		}

		[[nodiscard]] bool UsesCursor() const noexcept { return menuFlags.all(UI_MENU_FLAGS::kUsesCursor); }

		// members
		Scaleform::GFx::Value menuObj;                                                                                     // 20
		Scaleform::Ptr<Scaleform::GFx::Movie> uiMovie;                                                                     // 40
		BSFixedString customRendererName;                                                                                  // 48
		BSFixedString menuName;                                                                                            // 50
		stl::enumeration<UI_MENU_FLAGS, std::uint32_t> menuFlags;                                                          // 58
		BSTAtomicValue<std::uint32_t> advanceWithoutRenderCount{ 0 };                                                      // 5C
		bool passesTopMenuTest{ true };                                                                                    // 60
		bool menuCanBeVisible{ true };                                                                                     // 61
		bool hasQuadsForCumstomRenderer{ false };                                                                          // 62
		bool hasDoneFirstAdvanceMovie{ false };                                                                            // 63
		stl::enumeration<UI_DEPTH_PRIORITY, std::uint8_t> depthPriority{ UI_DEPTH_PRIORITY::kStandard };                   // 64
		stl::enumeration<UserEvents::INPUT_CONTEXT_ID, std::int32_t> inputContext{ UserEvents::INPUT_CONTEXT_ID::kNone };  // 68
	};
	static_assert(sizeof(IMenu) == 0x70);

	class HUDModeType
	{
	public:
		HUDModeType(const char* a_modeString) :
			modeString(a_modeString)
		{}

		// members
		BSFixedString modeString;  // 0
	};
	static_assert(sizeof(HUDModeType) == 0x8);

	class __declspec(novtable) BSGFxFunctionHandler :
		public Scaleform::GFx::FunctionHandler  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSGFxFunctionHandler };
		static constexpr auto VTABLE{ VTABLE::BSGFxFunctionHandler };

		virtual ~BSGFxFunctionHandler();  // 00

		// override
		virtual void Call(const Scaleform::GFx::FunctionHandler::Params&) override;  // 01

		// members
		Scaleform::GFx::Value flashTarget;                 // 10
		Scaleform::GFx::Value originalFunctionDefinition;  // 30
		BSFixedStringCS funcName;                          // 50
		BSGFxFunctionBase* owner;                          // 58
	};
	static_assert(sizeof(BSGFxFunctionHandler) == 0x60);

	class __declspec(novtable) BSGFxFunctionBase
	{
	public:
		static constexpr auto RTTI{ RTTI::BSGFxFunctionBase };
		static constexpr auto VTABLE{ VTABLE::BSGFxFunctionBase };

		virtual ~BSGFxFunctionBase();  // 00

		// add
		virtual void CallFlashFunction(const Scaleform::GFx::FunctionHandler::Params&) = 0;

		// members
		Scaleform::Ptr<BSGFxFunctionHandler> handler;  // 08
		BSFixedStringCS funcName;                      // 10
		UsesBSGFXFunctionHandler* owner;               // 18
	};
	static_assert(sizeof(BSGFxFunctionBase) == 0x20);

	class UsesBSGFXFunctionHandler
	{
	public:
		static constexpr auto RTTI{ RTTI::UsesBSGFXFunctionHandler };

		// members
		BSTArray<msvc::unique_ptr<BSGFxFunctionBase>> functions;  // 00
	};
	static_assert(sizeof(UsesBSGFXFunctionHandler) == 0x18);

	class BSGFxObject :
		public Scaleform::GFx::Value,    // 00
		public UsesBSGFXFunctionHandler  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::BSGFxObject };

		BSGFxObject(const Scaleform::GFx::Value& a_flashObject) :
			Scaleform::GFx::Value(a_flashObject)
		{}

		BSGFxObject(const Scaleform::GFx::Value& a_flashObject, const char* a_relativePathToMember)
		{
			AcquireFlashObjectByMemberName(a_flashObject, a_relativePathToMember);
		}

		BSGFxObject(const Scaleform::GFx::Movie& a_parentMovie, const char* a_pathToObject)
		{
			AcquireFlashObjectByPath(a_parentMovie, a_pathToObject);
		}

		Scaleform::GFx::Value* AcquireFlashObjectByMemberName(const Scaleform::GFx::Value& a_flashObject, const char* a_relativePathToMember)
		{
			using func_t = decltype(&BSGFxObject::AcquireFlashObjectByMemberName);
			REL::Relocation<func_t> func{ REL::ID(1172680) };
			return func(this, a_flashObject, a_relativePathToMember);
		}

		Scaleform::GFx::Value* AcquireFlashObjectByPath(const Scaleform::GFx::Movie& a_parentMovie, const char* a_absolutePathToMember)
		{
			using func_t = decltype(&BSGFxObject::AcquireFlashObjectByPath);
			REL::Relocation<func_t> func{ REL::ID(1065592) };
			return func(this, a_parentMovie, a_absolutePathToMember);
		}
	};
	static_assert(sizeof(BSGFxObject) == 0x38);

	class BSGFxDisplayObject :
		public BSGFxObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSGFxDisplayObject };
		static constexpr auto VTABLE{ VTABLE::BSGFxDisplayObject };

		struct InitialDisplayState
		{
		public:
			// members
			float originalWidth;   // 00
			float originalHeight;  // 04
		};
		static_assert(sizeof(InitialDisplayState) == 0x08);

		BSGFxDisplayObject(const Scaleform::GFx::Value& a_flashObject) :
			BSGFxObject(a_flashObject)
		{
			ctor_shared();
		}

		BSGFxDisplayObject(const Scaleform::GFx::Value& a_flashObject, const char* a_relativePathToMember) :
			BSGFxObject(a_flashObject, a_relativePathToMember)
		{
			ctor_shared();
		}

		BSGFxDisplayObject(const Scaleform::GFx::Movie& a_parentMovie, const char* a_pathToObject) :
			BSGFxObject(a_parentMovie, a_pathToObject)
		{
			ctor_shared();
		}

		virtual ~BSGFxDisplayObject()
		{
			if (parentDisplayObject) {
				parentDisplayObject->RemoveChild(*this);
			}
		}

		void RemoveChild(const BSGFxDisplayObject& a_child) const
		{
			using func_t = decltype(&BSGFxDisplayObject::RemoveChild);
			REL::Relocation<func_t> func{ REL::ID(1229383) };
			return func(this, a_child);
		}

		// members
		const BSGFxDisplayObject* parentDisplayObject{ nullptr };  // 40
		InitialDisplayState initialState;                          // 48

	private:
		void ctor_shared()
		{
			if (HasMember("height")) {
				Scaleform::GFx::Value height;
				if (GetMember("height", &height)) {
					if (height.IsNumber()) {
						initialState.originalHeight = static_cast<float>(height.GetNumber());
					}
				}
			}

			if (HasMember("width")) {
				Scaleform::GFx::Value width;
				if (GetMember("width", &width)) {
					if (width.IsNumber()) {
						initialState.originalWidth = static_cast<float>(width.GetNumber());
					}
				}
			}
		}
	};
	static_assert(sizeof(BSGFxDisplayObject) == 0x50);

	class BSGFxShaderFXTarget :
		public BSGFxDisplayObject,                  // 00
		public BSTEventSink<ApplyColorUpdateEvent>  // 50
	{
	public:
		static constexpr auto RTTI{ RTTI::BSGFxShaderFXTarget };
		static constexpr auto VTABLE{ VTABLE::BSGFxShaderFXTarget };

		BSGFxShaderFXTarget(const Scaleform::GFx::Value& a_flashObject) :
			BSGFxDisplayObject(a_flashObject)
		{
			ctor_shared();
		}

		BSGFxShaderFXTarget(const Scaleform::GFx::Value& a_flashObject, const char* a_relativePathToMember) :
			BSGFxDisplayObject(a_flashObject, a_relativePathToMember)
		{
			ctor_shared();
		}

		BSGFxShaderFXTarget(const Scaleform::GFx::Movie& a_parentMovie, const char* a_pathToObject) :
			BSGFxDisplayObject(a_parentMovie, a_pathToObject)
		{
			ctor_shared();
		}

		virtual ~BSGFxShaderFXTarget()
		{
			if (auto source = ApplyColorUpdateEvent::GetEventSource(); source) {
				source->UnregisterSink(this);
			}
		}

		// override
		virtual BSEventNotifyControl ProcessEvent(const ApplyColorUpdateEvent& a_event, BSTEventSource<ApplyColorUpdateEvent>* a_source) override  // 01
		{
			using func_t = decltype(&BSGFxShaderFXTarget::ProcessEvent);
			REL::Relocation<func_t> func{ REL::ID(848563) };
			return func(this, a_event, a_source);
		}

		// add
		virtual void AppendShaderFXInfos(BSTArray<UIShaderFXInfo>& a_colorFXInfo, BSTArray<UIShaderFXInfo>& a_backgroundFXInfo)  // 02
		{
			using func_t = decltype(&BSGFxShaderFXTarget::AppendShaderFXInfos);
			REL::Relocation<func_t> func{ REL::ID(544646) };
			return func(this, a_colorFXInfo, a_backgroundFXInfo);
		}

		void CreateAndSetFiltersToHUD(HUDColorTypes a_colorType, float a_scale = 1.0)
		{
			using func_t = decltype(&BSGFxShaderFXTarget::CreateAndSetFiltersToHUD);
			REL::Relocation<func_t> func{ REL::ID(876001) };
			func(this, a_colorType, a_scale);
		}

		void EnableShadedBackground(HUDColorTypes a_colorType, float a_scale = 1.0)
		{
			using func_t = decltype(&BSGFxShaderFXTarget::EnableShadedBackground);
			REL::Relocation<func_t> func{ REL::ID(278402) };
			func(this, a_colorType, a_scale);
		}

		void SetToHUDColor(bool a_useWarningColor)
		{
			auto colorType = (a_useWarningColor) ? RE::HUDColorTypes::kWarningColor : RE::HUDColorTypes::kGameplayHUDColor;
			CreateAndSetFiltersToHUD(colorType, 1.0);
		}

		// members
		UIShaderColors shaderFX;                                             // 58
		BSTArray<BSGFxShaderFXTarget*> shaderFXObjects;                      // 90
		stl::enumeration<HUDColorTypes, std::uint32_t> HUDColorType;         // A8
		stl::enumeration<HUDColorTypes, std::uint32_t> backgroundColorType;  // AC

	private:
		void ctor_shared()
		{
			if (HasMember("bUseShadedBackground")) {
				Scaleform::GFx::Value bUseShadedBackground;
				if (GetMember("bUseShadedBackground", &bUseShadedBackground)) {
					if (bUseShadedBackground.IsBoolean()) {
						if (bUseShadedBackground.GetBoolean()) {
							EnableShadedBackground(HUDColorTypes::kMenuNoColorBackground);
						}
					}
				}
			}

			if (auto source = ApplyColorUpdateEvent::GetEventSource(); source) {
				source->RegisterSink(this);
			}
		}
	};
	static_assert(sizeof(BSGFxShaderFXTarget) == 0xB0);

	class __declspec(novtable) ButtonHintBar :
		public BSGFxShaderFXTarget  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ButtonHintBar };
		static constexpr auto VTABLE{ VTABLE::ButtonHintBar };

		// members
		Scaleform::GFx::Value sourceButtons;  // B0
		bool redirectToButtonBarMenu;         // D0
		bool isTopButtonBar;                  // D1
	};
	static_assert(sizeof(ButtonHintBar) == 0xD8);

	class GameMenuBase :
		public IMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::GameMenuBase };
		static constexpr auto VTABLE{ VTABLE::GameMenuBase };

		GameMenuBase()
		{
			customRendererName = "FlatScreenModel";
		}

		virtual ~GameMenuBase() = default;

		// override
		virtual void SetIsTopButtonBar(bool a_isTopButtonBar) override  // 08
		{
			using func_t = decltype(&GameMenuBase::SetIsTopButtonBar);
			REL::Relocation<func_t> func{ REL::ID(1367353) };
			return func(this, a_isTopButtonBar);
		}

		virtual void OnMenuDisplayStateChanged() override  // 0A
		{
			using func_t = decltype(&GameMenuBase::OnMenuDisplayStateChanged);
			REL::Relocation<func_t> func{ REL::ID(1274450) };
			return func(this);
		}

		virtual void OnAddedToMenuStack() override  // 0B
		{
			IMenu::OnAddedToMenuStack();
			if (this->menuHUDMode.has_value()) {
				SendHUDMessage::PushHUDMode(this->menuHUDMode.value());
			}
		}

		virtual void OnRemovedFromMenuStack() override  // 0C
		{
			IMenu::OnRemovedFromMenuStack();
			if (this->menuHUDMode.has_value()) {
				SendHUDMessage::PopHUDMode(this->menuHUDMode.value());
			}
		}

		virtual bool CacheShaderFXQuadsForRenderer_Impl() override  // 10
		{
			using func_t = decltype(&GameMenuBase::CacheShaderFXQuadsForRenderer_Impl);
			REL::Relocation<func_t> func{ REL::ID(863029) };
			return func(this);
		}

		virtual void TransferCachedShaderFXQuadsForRenderer(const BSFixedString& a_rendererName) override  // 11
		{
			using func_t = decltype(&GameMenuBase::TransferCachedShaderFXQuadsForRenderer);
			REL::Relocation<func_t> func{ REL::ID(65166) };
			return func(this, a_rendererName);
		}

		virtual void SetViewportRect(const NiRect<float>& a_viewportRect) override  // 12
		{
			using func_t = decltype(&GameMenuBase::SetViewportRect);
			REL::Relocation<func_t> func{ REL::ID(1554334) };
			return func(this, a_viewportRect);
		}

		// add
		virtual void AppendShaderFXInfos(BSTAlignedArray<UIShaderFXInfo>& a_colorFXInfos, BSTAlignedArray<UIShaderFXInfo>& a_backgroundFXInfos) const  // 13
		{
			using func_t = decltype(&GameMenuBase::AppendShaderFXInfos);
			REL::Relocation<func_t> func{ REL::ID(583584) };
			return func(this, a_colorFXInfos, a_backgroundFXInfos);
		}

		void SetUpButtonBar(BSGFxShaderFXTarget& a_parentObject, const char* a_buttonBarPath, HUDColorTypes a_colorType)
		{
			using func_t = decltype(&GameMenuBase::SetUpButtonBar);
			REL::Relocation<func_t> func{ REL::ID(531584) };
			func(this, a_parentObject, a_buttonBarPath, a_colorType);
		}

		// members
		BSTArray<BSGFxShaderFXTarget*> shaderFXObjects;           // 70
		msvc::unique_ptr<BSGFxShaderFXTarget> filterHolder;       // 88
		msvc::unique_ptr<ButtonHintBar> buttonHintBar;            // 90
		BSTAlignedArray<UIShaderFXInfo> cachedColorFXInfos;       // 98
		BSTAlignedArray<UIShaderFXInfo> cachedBackgroundFXInfos;  // B0
		BSReadWriteLock cachedQuadsLock;                          // C8
		BSTOptional<HUDModeType> menuHUDMode;                     // D0
	};
	static_assert(sizeof(GameMenuBase) == 0xE0);

	struct Rumble
	{
	public:
		struct AutoRumblePause
		{
		public:
		};
		static_assert(std::is_empty_v<AutoRumblePause>);
	};
	static_assert(std::is_empty_v<Rumble>);

	struct __declspec(novtable) Console :
		public GameMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::Console };
		static constexpr auto VTABLE{ VTABLE::Console };
		static constexpr auto MENU_NAME{ "Console"sv };

		static void ExecuteCommand(const char* a_command)
		{
			using func_t = decltype(&Console::ExecuteCommand);
			REL::Relocation<func_t> func{ REL::ID(1061864) };
			return func(a_command);
		}

		[[nodiscard]] static decltype(auto) GetCurrentPickIndex()
		{
			REL::Relocation<std::int32_t*> currentPickIndex{ REL::ID(1407033) };
			return *currentPickIndex;
		}

		[[nodiscard]] static decltype(auto) GetPickRef()
		{
			REL::Relocation<ObjectRefHandle*> ref{ REL::ID(170742) };
			return *ref;
		}

		[[nodiscard]] static decltype(auto) GetPickRefs()
		{
			REL::Relocation<BSTArray<ObjectRefHandle>*> pickRefs{ REL::ID(875116) };
			return *pickRefs;
		}

		[[nodiscard]] static ObjectRefHandle GetCurrentPickREFR()
		{
			const auto idx = GetCurrentPickIndex();
			const auto& refs = GetPickRefs();
			return 0 <= idx && static_cast<std::size_t>(idx) < refs.size() ?
                       refs[static_cast<std::size_t>(idx)] :
                       ObjectRefHandle{};
		}

		void SetCurrentPickREFR(stl::not_null<ObjectRefHandle*> a_refr)
		{
			using func_t = decltype(&Console::SetCurrentPickREFR);
			REL::Relocation<func_t> func{ REL::ID(79066) };
			return func(this, a_refr);
		}

		// members
		Rumble::AutoRumblePause* rumbleLock;  // E0
		bool minimized;                       // E8
	};
	static_assert(sizeof(Console) == 0xF0);

	struct BaseLoadedInventoryModel
	{
	public:
		// members
		CreatedObjPtr<TESForm> itemBase;  // 00
		TESBoundObject* modelObj;         // 08
		NiPointer<NiAVObject> model;      // 10
		NiPoint2 panMinima;               // 18
		NiPoint2 panMaxima;               // 20
		float initialDistance;            // 28
		float boundRadius;                // 2C
		float horizontalBound;            // 30
		float verticalBound;              // 34
		float verticalBoundOffset;        // 38
	};
	static_assert(sizeof(BaseLoadedInventoryModel) == 0x40);

	struct DisplayItemModel :
		public BaseLoadedInventoryModel  // 00
	{
	public:
		// members
		float itemRotation;         // 40
		std::uint32_t uniqueIndex;  // 44
		std::uint16_t column;       // 48
		std::uint16_t index;        // 4A
		std::uint16_t row;          // 4C
	};
	static_assert(sizeof(DisplayItemModel) == 0x50);

	namespace nsInventory3DManager
	{
		class NewInventoryMenuItemLoadTask;
	}

	class __declspec(novtable) Inventory3DManager :
		public BSInputEventUser  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::Inventory3DManager };
		static constexpr auto VTABLE{ VTABLE::Inventory3DManager };

		void ClearModel()
		{
			using func_t = decltype(&Inventory3DManager::ClearModel);
			REL::Relocation<func_t> func{ REL::ID(63218) };
			return func(this);
		}

		// members
		bool useBoundForScale: 1;                                                // 010:0
		bool startedZoomThisFrame: 1;                                            // 010:1
		bool useStoredModelPosition: 1;                                          // 010:2
		bool rotating: 1;                                                        // 010:3
		bool modelPositionInScreenCoords: 1;                                     // 010:4
		bool centerOnBoundCenter: 1;                                             // 010:5
		NiPoint3 modelPosition;                                                  // 014
		float modelScale;                                                        // 020
		alignas(0x10) BSTArray<LoadedInventoryModel> loadedModels;               // 030
		NiPoint3 initialPosition;                                                // 048
		NiPoint3 storedPostion;                                                  // 054
		NiMatrix3 initialRotation;                                               // 060
		NiQuaternion storedRotation;                                             // 090
		NiPoint2 previousInput;                                                  // 0A0
		NiPointer<nsInventory3DManager::NewInventoryMenuItemLoadTask> loadTask;  // 0A8
		TESObjectREFR* tempRef;                                                  // 0B0
		BSTSmartPointer<ExtraDataList> originalExtra;                            // 0B8
		BSFixedString str3DRendererName;                                         // 0C0
		BGSInventoryItem queuedDisplayItem;                                      // 0C8
		std::uint32_t itemExtraIndex;                                            // 0D8
		TESForm* itemBase;                                                       // 0E0
		std::int8_t disableInputUserCount;                                       // 0E8
		BSTSet<BSFixedString> disableRendererUsers;                              // 0F0
		float storedXRotation;                                                   // 120
		float zoomDirection;                                                     // 124
		float zoomProgress;                                                      // 128
		float minZoomModifier;                                                   // 12C
		float maxZoomModifier;                                                   // 130
		std::uint32_t hightlightedPart;                                          // 134
		bool queueShowItem;                                                      // 138
		bool mouseRotation;                                                      // 139
		bool prevUsesCursorFlag;                                                 // 13A
		bool prevUpdateUsesCursorFlag;                                           // 13B
		bool addedLightsToScene;                                                 // 13C
	};
	static_assert(sizeof(Inventory3DManager) == 0x140);

	class __declspec(novtable) WorkshopMenu :
		public GameMenuBase,                                 // 000
		public BSTEventSink<UserEventEnabledEvent>,          // 0E0
		public BSTEventSink<Workshop::BuildableAreaEvent>,   // 0E8
		public BSTEventSink<PickRefUpdateEvent>,             // 0F0
		public BSTEventSink<Workshop::PlacementStatusEvent>  // 0F8
	{
	public:
		static constexpr auto RTTI{ RTTI::WorkshopMenu };
		static constexpr auto VTABLE{ VTABLE::WorkshopMenu };
		static constexpr auto MENU_NAME{ "WorkshopMenu"sv };

		class FXWorkshopMenu :
			public BSGFxShaderFXTarget  // 000
		{
		public:
			// members
			msvc::unique_ptr<BSGFxShaderFXTarget> happyBackground1;            // 0B0
			msvc::unique_ptr<BSGFxShaderFXTarget> happyBackground2;            // 0B8
			msvc::unique_ptr<BSGFxShaderFXTarget> happyBackground3;            // 0C0
			msvc::unique_ptr<BSGFxShaderFXTarget> happyBackground4;            // 0C8
			msvc::unique_ptr<BSGFxShaderFXTarget> happyBackground5;            // 0D0
			msvc::unique_ptr<BSGFxShaderFXTarget> happyBackground6;            // 0D8
			msvc::unique_ptr<BSGFxShaderFXTarget> happyBackground7;            // 0E0
			msvc::unique_ptr<BSGFxShaderFXTarget> happyBackground8;            // 0E8
			msvc::unique_ptr<BSGFxShaderFXTarget> buttonBackground;            // 0F0
			msvc::unique_ptr<BSGFxShaderFXTarget> iconCardBackground;          // 0F8
			msvc::unique_ptr<BSGFxShaderFXTarget> requirementsListBackground;  // 100
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessPeopleBase;         // 108
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessFoodBase;           // 110
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessWaterBase;          // 118
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessPowerBase;          // 120
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessSafetyBase;         // 128
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessBedsBase;           // 130
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessHappyValue;         // 138
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessHappyLabel;         // 140
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessHappyIcon;          // 148
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessHappyArrow;         // 150
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessSizeBase;           // 158
			msvc::unique_ptr<BSGFxShaderFXTarget> happinessBarBrackets;        // 160
			msvc::unique_ptr<BSGFxShaderFXTarget> requirementsBase;            // 168
			msvc::unique_ptr<BSGFxShaderFXTarget> itemName;                    // 170
			msvc::unique_ptr<BSGFxShaderFXTarget> selectionBracket;            // 178
			msvc::unique_ptr<BSGFxShaderFXTarget> itemCounts;                  // 180
			msvc::unique_ptr<BSGFxShaderFXTarget> newRecipeIcon;               // 188
			msvc::unique_ptr<BSGFxShaderFXTarget> iconCardBracketsAndText;     // 190
			msvc::unique_ptr<BSGFxShaderFXTarget> producesIcons;               // 198
			msvc::unique_ptr<BSGFxShaderFXTarget> requiresIcon1;               // 1A0
			msvc::unique_ptr<BSGFxShaderFXTarget> requiresIcon2;               // 1A8
			msvc::unique_ptr<BSGFxShaderFXTarget> assignmentIcon;              // 1B0
			msvc::unique_ptr<BSGFxShaderFXTarget> rowBrackets;                 // 1B8
			msvc::unique_ptr<BSGFxShaderFXTarget> displayPath;                 // 1C0
			msvc::unique_ptr<BSGFxShaderFXTarget> perkPanel1;                  // 1C8
			msvc::unique_ptr<BSGFxShaderFXTarget> perkPanel2;                  // 1D0
			msvc::unique_ptr<BSGFxShaderFXTarget> descriptionBase;             // 1D8
			msvc::unique_ptr<BSGFxShaderFXTarget> iconBackground;              // 1E0
		};
		static_assert(sizeof(FXWorkshopMenu) == 0x1E8);

		struct IconBG
		{
		public:
			BSTAlignedArray<UIShaderFXInfo> cachedColorFXInfos;       // 00
			BSTAlignedArray<UIShaderFXInfo> cachedBackgroundFXInfos;  // 18
			BSReadWriteLock cachedQuadsLock;                          // 30
		};
		static_assert(sizeof(IconBG) == 0x38);

		void CheckAndSetItemForPlacement()
		{
			using func_t = decltype(&WorkshopMenu::CheckAndSetItemForPlacement);
			REL::Relocation<func_t> func{ REL::ID(1541862) };
			return func(this);
		}

		void UpdateButtonText()
		{
			using func_t = decltype(&WorkshopMenu::UpdateButtonText);
			REL::Relocation<func_t> func{ REL::ID(1089189) };
			return func(this);
		}

		// members
		BSTArray<NiPoint3> item3DPositions[4];                                                                          // 100
		BSTArray<BSTTuple<DisplayItemModel, TESObjectREFR*>> displayItemModels;                                         // 160
		IconBG iconBG;                                                                                                  // 178
		Inventory3DManager inv3DModelManager;                                                                           // 1B0
		BSTArray<BSTTuple<NiPointer<nsInventory3DManager::NewInventoryMenuItemLoadTask>, NiPoint3>> loadTasks;          // 2F0
		BSTInterpolator<float, EaseOutInterpolator, GetCurrentPositionFunctor> upDownGlassAnimationInterpolator;        // 308
		BSTInterpolator<float, EaseOutInterpolator, GetCurrentPositionFunctor> leftRightGlassAnimationInterpolator[4];  // 320
		BSTSmartPointer<WorkshopMenuGeometry> displayGeometry;                                                          // 380
		BSFixedString dpadInput;                                                                                        // 388
		BGSListForm includeList;                                                                                        // 390
		BGSListForm excludeList;                                                                                        // 3D8
		long double lastBudget;                                                                                         // 420
		std::uint16_t topMenuCount;                                                                                     // 428
		bool inputAdjustMode;                                                                                           // 42A
		bool verticalAdjustment;                                                                                        // 42B
		bool disableAdjustOnThumbEvent;                                                                                 // 42C
		bool initialized;                                                                                               // 42D
		bool inEditMode;                                                                                                // 42E
		bool electricalDevice;                                                                                          // 42F
		bool useMovementAsDirectional;                                                                                  // 430
		bool motionBlurActive;                                                                                          // 431
		bool exitDebounce;                                                                                              // 432
		msvc::unique_ptr<FXWorkshopMenu> workshopMenuBase;                                                              // 438
	};
	static_assert(sizeof(WorkshopMenu) == 0x440);

	class __declspec(novtable) PipboySubMenu :
		public BSTEventSink<PipboyValueChangedEvent>  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboySubMenu };
		static constexpr auto VTABLE{ VTABLE::PipboySubMenu };

		// override (BSTEventSink<PipboyValueChangedEvent>)
		BSEventNotifyControl ProcessEvent(const PipboyValueChangedEvent& a_event, BSTEventSource<PipboyValueChangedEvent>* a_source) override
		{
			using func_t = decltype(&PipboySubMenu::ProcessEvent);
			REL::Relocation<func_t> func{ REL::ID(893703) };
			return func(this, a_event, a_source);
		}

		// add
		virtual void UpdateData() = 0;  // 02

		// members
		Scaleform::GFx::Value& dataObj;  // 08
		Scaleform::GFx::Value& menuObj;  // 10
	};
	static_assert(sizeof(PipboySubMenu) == 0x18);

	class __declspec(novtable) PipboyStatsMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyStatsMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyStatsMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboyStatsMenu::UpdateData);
			REL::Relocation<func_t> func{ REL::ID(332518) };
			return func(this);
		}

		// members
		BSSoundHandle perkSound;  // 18
	};
	static_assert(sizeof(PipboyStatsMenu) == 0x20);

	class __declspec(novtable) PipboySpecialMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboySpecialMenu };
		static constexpr auto VTABLE{ VTABLE::PipboySpecialMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboySpecialMenu::UpdateData);
			REL::Relocation<func_t> func{ REL::ID(1426810) };
			return func(this);
		}
	};
	static_assert(sizeof(PipboySpecialMenu) == 0x18);

	class __declspec(novtable) PipboyPerksMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyPerksMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyPerksMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboyPerksMenu::UpdateData);
			REL::Relocation<func_t> func{ REL::ID(783380) };
			return func(this);
		}
	};
	static_assert(sizeof(PipboyPerksMenu) == 0x18);

	class __declspec(novtable) PipboyInventoryMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyInventoryMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyInventoryMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboyInventoryMenu::UpdateData);
			REL::Relocation<func_t> func{ REL::ID(762897) };
			return func(this);
		}
	};
	static_assert(sizeof(PipboyInventoryMenu) == 0x18);

	class __declspec(novtable) PipboyQuestMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyQuestMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyQuestMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboyQuestMenu::UpdateData);
			REL::Relocation<func_t> func{ REL::ID(1495929) };
			return func(this);
		}
	};
	static_assert(sizeof(PipboyQuestMenu) == 0x18);

	class __declspec(novtable) PipboyWorkshopMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyWorkshopMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyWorkshopMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboyWorkshopMenu::UpdateData);
			REL::Relocation<func_t> func{ REL::ID(1370368) };
			return func(this);
		}
	};
	static_assert(sizeof(PipboyWorkshopMenu) == 0x18);

	class __declspec(novtable) PipboyLogMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyLogMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyLogMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboyLogMenu::UpdateData);
			REL::Relocation<func_t> func{ REL::ID(672256) };
			return func(this);
		}
	};
	static_assert(sizeof(PipboyLogMenu) == 0x18);

	class BSScaleformExternalTexture
	{
	public:
		// members
		NiPointer<NiTexture> gamebryoTexture;  // 00
		std::uint32_t renderTarget;            // 08
		BSFixedString texturePath;             // 10
	};
	static_assert(sizeof(BSScaleformExternalTexture) == 0x18);

	class __declspec(novtable) PipboyMapMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyMapMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyMapMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboyMapMenu::UpdateData);
			REL::Relocation<func_t> func{ REL::ID(92696) };
			return func(this);
		}

		// members
		BSScaleformExternalTexture worldMapTexture;  // 18
		Scaleform::GFx::Value mapPageObj;            // 30
		std::uint32_t centeredQuestMarkerID;         // 50
		std::uint32_t centeredMapMarkerID;           // 54
		std::uint32_t queuedFastTravelId;            // 58
		bool mapTexturesSentToMenu;                  // 5C
		bool requestedDelayedLocalMapRender;         // 5D
	};
	static_assert(sizeof(PipboyMapMenu) == 0x60);

	class __declspec(novtable) PipboyRadioMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyRadioMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyRadioMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboyRadioMenu::UpdateData);
			REL::Relocation<func_t> func{ REL::ID(713423) };
			return func(this);
		}

		bool radioModeOn;  // 18
	};
	static_assert(sizeof(PipboyRadioMenu) == 0x20);

	class __declspec(novtable) PipboyPlayerInfoMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyPlayerInfoMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyPlayerInfoMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboyPlayerInfoMenu::UpdateData);
			REL::Relocation<func_t> func{ REL::ID(426990) };
			return func(this);
		}
	};
	static_assert(sizeof(PipboyPlayerInfoMenu) == 0x18);

	class __declspec(novtable) PipboyMenu :
		public GameMenuBase,                      // 000
		public BSTEventSink<MenuOpenCloseEvent>,  // 0E0
		public BSTEventSink<IdleInputEvent>       // 0E8
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyMenu };
		static constexpr auto MENU_NAME{ "PipboyMenu"sv };

		// members
		Scaleform::GFx::Value dataObj;           // 0F0
		PipboyStatsMenu statsMenuObj;            // 110
		PipboySpecialMenu specialMenuObj;        // 130
		PipboyPerksMenu perksMenuObj;            // 148
		PipboyInventoryMenu inventoryMenuObj;    // 160
		PipboyQuestMenu questMenuObj;            // 178
		PipboyWorkshopMenu workshopMenuObj;      // 190
		PipboyLogMenu logMenuObj;                // 1A8
		PipboyMapMenu mapMenuObj;                // 1C0
		PipboyRadioMenu radioMenuObj;            // 220
		PipboyPlayerInfoMenu playerInfoMenuObj;  // 240
		std::int8_t disableInputCounter;         // 258
		bool pipboyCursorEnabled;                // 259
		bool showingModalMessage;                // 25A
		bool pipboyHiddenByAnotherMenu;          // 25B
		bool performFastTravelCheck;             // 25C
	};
	static_assert(sizeof(PipboyMenu) == 0x260);

	class __declspec(novtable) CursorMenu :
		public GameMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::CursorMenu };
		static constexpr auto VTABLE{ VTABLE::CursorMenu };
		static constexpr auto MENU_NAME{ "CursorMenu"sv };

		// members
		msvc::unique_ptr<BSGFxShaderFXTarget> cursor;  // E0
	};
	static_assert(sizeof(CursorMenu) == 0xE8);

	struct DisableHeavyItemsFunc
	{
	public:
		// members
		float playerCurrEncumbrance;     // 00
		float playerMaxEncumbrance;      // 04
		float containerCurrEncumbrance;  // 08
		float containerMaxEncumbrance;   // 0C
	};
	static_assert(sizeof(DisableHeavyItemsFunc) == 0x10);

	struct InventoryUserUIInterfaceEntry
	{
	public:
		// members
		InventoryInterface::Handle invHandle;       // 00
		BSTSmallArray<std::uint8_t, 4> stackIndex;  // 08
	};
	static_assert(sizeof(InventoryUserUIInterfaceEntry) == 0x20);

	class __declspec(novtable) InventoryUserUIInterface :
		public BSTEventSource<InvInterfaceStateChangeEvent>  // 00
	{
	public:
		// members
		ObjectRefHandle inventoryRef;                            // 58
		BSTArray<InventoryUserUIInterfaceEntry> stackedEntries;  // 60
		bool entriesInvalid;                                     // 78
	};
	static_assert(sizeof(InventoryUserUIInterface) == 0x80);

	class __declspec(novtable) ContainerMenuBase :
		public GameMenuBase,                                // 000
		public BSTEventSink<InvInterfaceStateChangeEvent>,  // 0E0
		public BSTEventSink<MenuOpenCloseEvent>             // 0E8
	{
	public:
		static constexpr auto RTTI{ RTTI::ContainerMenuBase };
		static constexpr auto VTABLE{ VTABLE::ContainerMenuBase };

		class __declspec(novtable) FXQuantityMenu :
			public BSGFxShaderFXTarget  // 000
		{
		public:
			// members
			BSGFxShaderFXTarget label;                  // 0B0
			BSGFxShaderFXTarget value;                  // 160
			BSGFxShaderFXTarget quantityBracketHolder;  // 210
		};
		static_assert(sizeof(FXQuantityMenu) == 0x2C0);

		struct ItemSorter
		{
		public:
			enum class SORT_ON_FIELD
			{
				kAlphabetical = 0,
				kDamage = 1,
				kRateOfFire = 2,
				kRange = 3,
				kAccuracy = 4,
				kValue = 5,
				kWeight = 6,
			};

			void IncrementSort()
			{
				using func_t = decltype(&ItemSorter::IncrementSort);
				REL::Relocation<func_t> func{ REL::ID(1307263) };
				return func(this);
			}

			void SetTab(std::uint32_t a_tab)
			{
				currentTab = a_tab;
			}

			// members
			stl::enumeration<SORT_ON_FIELD, std::uint32_t> currentSort[14];  // 00
			std::uint32_t currentTab;                                        // 38
		};
		static_assert(sizeof(ItemSorter) == 0x3C);

		// override
		virtual void Call(const Params&) override;                                    // 01
		virtual void MapCodeObjectFunctions() override;                               // 02
		virtual void AdvanceMovie(float a_timeDelta, std::uint64_t a_time) override;  // 04
		virtual void PreDisplay() override;                                           // 05

		// add
		virtual void ConfirmInvestment() { return; }                                                                                                                          // 14
		virtual void DoItemTransfer(std::uint32_t a_itemIndex, std::uint32_t a_count, bool a_fromContainer) = 0;                                                              // 15
		virtual bool GetDisplayBarterValues() { return false; }                                                                                                               // 16
		virtual bool GetCanEquipItem([[maybe_unused]] std::uint32_t a_itemIndex, [[maybe_unused]] bool a_inContainer) { return false; }                                       // 17
		virtual bool GetIsItemEquipped([[maybe_unused]] std::uint32_t a_itemIndex, [[maybe_unused]] bool a_inContainer) { return false; }                                     // 18
		virtual void ToggleItemEquipped([[maybe_unused]] std::uint32_t a_itemIndex, [[maybe_unused]] bool a_inContainer) { return; }                                          // 19
		virtual std::uint32_t GetItemValue(std::uint32_t a_itemIndex, bool a_inContainer);                                                                                    // 1A
		virtual const InventoryUserUIInterfaceEntry* GetInventoryItemByListIndex(bool a_inContainer, std::uint32_t a_index);                                                  // 1B
		virtual void PopulateMenuObj(ObjectRefHandle a_inventoryRef, const InventoryUserUIInterfaceEntry& a_entry, Scaleform::GFx::Value& a_menuObj) = 0;                     // 1C
		virtual void SetMenuSuppressed(bool a_suppressed);                                                                                                                    // 1D
		virtual void UpdateEncumbranceAndCaps(bool a_inContainer, std::int32_t a_capsDifferential);                                                                           // 1E
		virtual void UpdateItemPickpocketInfo([[maybe_unused]] std::int32_t a_index, [[maybe_unused]] bool a_inContainer, [[maybe_unused]] std::int32_t a_count) { return; }  // 1F
		virtual void UpdateList(bool a_inContainer) = 0;                                                                                                                      // 20

		void SetMessageBoxMode(bool a_messageBoxMode)
		{
			if (menuObj.IsObject() && menuObj.HasMember("messageBoxIsActive"sv)) {
				menuObj.SetMember("messageBoxIsActive"sv, a_messageBoxMode);
			}
		}

		// members
		ItemSorter containerItemSorter;                                       // 0F0
		ItemSorter playerItemSorter;                                          // 12C
		msvc::unique_ptr<BSGFxShaderFXTarget> playerBracketBackground_mc;     // 168
		msvc::unique_ptr<BSGFxShaderFXTarget> containerBracketBackground_mc;  // 170
		msvc::unique_ptr<BSGFxShaderFXTarget> containerList_mc;               // 178
		msvc::unique_ptr<BSGFxShaderFXTarget> playerInventory_mc;             // 180
		msvc::unique_ptr<BSGFxShaderFXTarget> containerInventory_mc;          // 188
		msvc::unique_ptr<BSGFxShaderFXTarget> itemCard_mc;                    // 190
		msvc::unique_ptr<FXQuantityMenu> quantityMenu_mc;                     // 198
		InventoryUserUIInterface playerInv;                                   // 1A0
		InventoryUserUIInterface containerInv;                                // 220
		Inventory3DManager inv3DModelManager;                                 // 2A0
		BSTArray<const TESBoundObject*> partialPlayerUpdateList;              // 3E0
		BSTArray<const TESBoundObject*> partialContainerUpdateList;           // 3F8
		stl::enumeration<ContainerMenuMode, std::uint32_t> menuMode;          // 410
		Rumble::AutoRumblePause autoRumblePause;                              // 414
		DisableHeavyItemsFunc disableHeavyFunc;                               // 418
		ObjectRefHandle containerRef;                                         // 428
		bool suppressed;                                                      // 42C
		bool menuOpening;                                                     // 42D
	};
	static_assert(sizeof(ContainerMenuBase) == 0x430);

	class __declspec(novtable) ContainerMenu :
		public ContainerMenuBase  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::ContainerMenu };
		static constexpr auto VTABLE{ VTABLE::ContainerMenu };
		static constexpr auto MENU_NAME{ "ContainerMenu"sv };

		// override
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;                                                                               // 03
		virtual void DoItemTransfer(std::uint32_t a_itemIndex, std::uint32_t a_count, bool a_fromContainer) override;                                           // 15
		virtual bool GetCanEquipItem(std::uint32_t a_itemIndex, bool a_inContainer) override;                                                                   // 17
		virtual bool GetIsItemEquipped(std::uint32_t a_itemIndex, bool a_inContainer) override;                                                                 // 18
		virtual void ToggleItemEquipped(std::uint32_t a_itemIndex, bool a_inContainer) override;                                                                // 19
		virtual void PopulateMenuObj(ObjectRefHandle a_inventoryRef, const InventoryUserUIInterfaceEntry& a_entry, Scaleform::GFx::Value& a_menuObj) override;  // 22
		virtual void UpdateItemPickpocketInfo(std::int32_t a_index, bool a_inContainer, std::int32_t a_count) override;                                         // 25
		virtual void UpdateList(bool a_inContainer) override;                                                                                                   // 26

		void TakeAllItems()
		{
			using func_t = decltype(&ContainerMenu::TakeAllItems);
			REL::Relocation<func_t> func{ REL::ID(1323703) };
			return func(this);
		}

		// members
		msvc::unique_ptr<BSGFxShaderFXTarget> pickpocketInfo_mc;  // 430
		std::uint32_t valueStolenFromContainer;                   // 438
		bool containerAccessed;                                   // 43C
		bool addedTempItems;                                      // 43D
		bool plantedExplosiveWeapon;                              // 43E
		bool containerIsAnimatingOpen;                            // 43F
	};
	static_assert(sizeof(ContainerMenu) == 0x440);

	class __declspec(novtable) BarterMenuTentativeInventoryUIInterface :
		public InventoryUserUIInterface  // 00
	{
	public:
	};
	static_assert(sizeof(BarterMenuTentativeInventoryUIInterface) == 0x80);

	class __declspec(novtable) BarterMenu :
		public ContainerMenuBase  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BarterMenu };
		static constexpr auto VTABLE{ VTABLE::BarterMenu };
		static constexpr auto MENU_NAME{ "BarterMenu"sv };

		struct ItemBarterData
		{
		public:
			// members
			BSTHashMap<std::uint32_t, std::int32_t> stackQuantityMap;  // 00
			std::uint32_t capsOwedByPlayer;                            // 30
		};
		static_assert(sizeof(ItemBarterData) == 0x38);

		// override
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;                                                                               // 03
		virtual bool OnButtonEventRelease(const BSFixedString& a_eventName) override;                                                                           // 0F
		virtual void ConfirmInvestment() override;                                                                                                              // 14
		virtual void DoItemTransfer(std::uint32_t a_itemIndex, std::uint32_t a_count, bool a_fromContainer) override;                                           // 15
		virtual bool GetDisplayBarterValues() override;                                                                                                         // 16
		virtual std::uint32_t GetItemValue(std::uint32_t a_itemIndex, bool a_inContainer) override;                                                             // 1A
		virtual const InventoryUserUIInterfaceEntry* GetInventoryItemByListIndex(bool a_inContainer, std::uint32_t a_index) override;                           // 1B
		virtual void PopulateMenuObj(ObjectRefHandle a_inventoryRef, const InventoryUserUIInterfaceEntry& a_entry, Scaleform::GFx::Value& a_menuObj) override;  // 1C
		virtual void SetMenuSuppressed(bool a_suppressed) override;                                                                                             // 1D
		virtual void UpdateEncumbranceAndCaps(bool a_inContainer, std::int32_t a_capsDifferential) override;                                                    // 1E
		virtual void UpdateList(bool a_inContainer) override;                                                                                                   // 20

		void ClearTradingData()
		{
			using func_t = decltype(&BarterMenu::ClearTradingData);
			REL::Relocation<func_t> func{ REL::ID(1112285) };
			return func(this);
		}

		void CompleteTrade()
		{
			using func_t = decltype(&BarterMenu::CompleteTrade);
			REL::Relocation<func_t> func{ REL::ID(379932) };
			return func(this);
		}

		[[nodiscard]] std::int64_t GetCapsOwedByPlayer()
		{
			using func_t = decltype(&BarterMenu::GetCapsOwedByPlayer);
			REL::Relocation<func_t> func{ REL::ID(672405) };
			return func(this);
		}

		// members
		BSTHashMap<InventoryInterface::Handle*, ItemBarterData*> barteredItems;  // 430
		msvc::unique_ptr<BSGFxShaderFXTarget> capsTransferInfo_mc;               // 460
		msvc::unique_ptr<BSGFxShaderFXTarget> capsTransferBackground_mc;         // 468
		ObjectRefHandle vendorChestRef;                                          // 470
		ObjectRefHandle vendorActor;                                             // 474
		BarterMenuTentativeInventoryUIInterface playerTentativeInv;              // 478
		BarterMenuTentativeInventoryUIInterface containerTentativeInv;           // 4F8
		bool confirmingTrade;                                                    // 578
	};
	static_assert(sizeof(BarterMenu) == 0x580);

	class __declspec(novtable) MessageBoxMenu :
		public GameMenuBase,                      // 00
		public BSTEventSink<MenuModeChangeEvent>  // E0
	{
	public:
		static constexpr auto RTTI{ RTTI::MessageBoxMenu };
		static constexpr auto VTABLE{ VTABLE::MessageBoxMenu };
		static constexpr auto MENU_NAME{ "MessageBoxMenu"sv };

		// override
		virtual void Call(const Params&) override;                           // 01
		virtual void MapCodeObjectFunctions() override;                      // 02
		virtual UI_MESSAGE_RESULTS ProcessMessage(RE::UIMessage&) override;  // 03

		void ShowMessage()
		{
			using func_t = decltype(&MessageBoxMenu::ShowMessage);
			REL::Relocation<func_t> func{ REL::ID(442479) };
			return func(this);
		}

		// members
		MessageBoxData* currentMessage;  // E8
	};
	static_assert(sizeof(MessageBoxMenu) == 0xF0);

	class __declspec(novtable) WorkbenchMenuBase :
		public GameMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::WorkbenchMenuBase };
		static constexpr auto VTABLE{ VTABLE::WorkbenchMenuBase };

		enum class HighlightMode
		{
			kModMenu,
			kAll,
			kWorld
		};

		struct ModChoiceData
		{
		public:
			// members
			union
			{
				BGSMod::Attachment::Mod* mod;
				TESBoundObject* object;
			};                                                                              // 00
			const BGSConstructibleObject* recipe;                                           // 08
			BSTArray<BSTTuple<TESForm*, BGSTypedFormValuePair::SharedVal>>* requiredItems;  // 10
			BSTArray<BSTTuple<BGSPerk*, std::uint32_t>> requiredPerks;                      // 18
			std::uint8_t rank;                                                              // 30
			std::uint8_t index;                                                             // 31
		};
		static_assert(sizeof(ModChoiceData) == 0x38);

		virtual ~WorkbenchMenuBase();  // 00

		// override (GameMenuBase)
		virtual void Call(const Params&) override;                                                               // 01
		virtual void MapCodeObjectFunctions() override;                                                          // 02
		virtual void PreDisplay() override;                                                                      // 05
		virtual void OnMenuStackChanged(const BSFixedString& a_topMenuName, bool a_passesTopMenuTest) override;  // 09

		// override (BSInputEventUser)
		virtual bool ShouldHandleEvent(const InputEvent*) override;  // 01
		virtual void HandleEvent(const ThumbstickEvent*) override;   // 04
		virtual void HandleEvent(const CursorMoveEvent*) override;   // 05
		virtual void HandleEvent(const ButtonEvent*) override;       // 08

		// add
		virtual void OnHideMenu();                                 // 14
		virtual void UpdateMenu();                                 // 15
		virtual void BuildCanceled();                              // 16
		virtual void BuildConfirmed(bool a_ownerIsWorkbench) = 0;  // 17
		virtual bool GetWorkbenchHasInventory();                   // 18
		virtual const ModChoiceData* QCurrentModChoiceData();      // 19
		virtual void ShowBuildFailureMessage();                    // 1A
		virtual bool TryCreate() = 0;                              // 1B

		// members
		NiPointer<TESObjectREFR> sharedContainerRef;                   // 0E0
		NiPointer<TESObjectREFR> workbenchContainerRef;                // 0E8
		BSTArray<NiPointer<TESObjectREFR>> sharedContainers;           // 0F0
		Inventory3DManager inv3DModelManager;                          // 110
		BGSInventoryList optimizedAutoBuildInv;                        // 250
		BSTArray<ModChoiceData> modChoiceArray;                        // 2D0
		std::uint32_t modChoiceIndex;                                  // 2E8
		std::uint32_t lastModChoiceIndex;                              // 2EC
		bool repairing;                                                // 2F0
		bool queueHide;                                                // 2F1
		bool hiding;                                                   // 2F2
		bool VATSWasEnabled;                                           // 2F3
		NiPointer<TESObjectREFR> workbenchRef;                         // 2F8
		BSTSmartPointer<ExtraDataList> recipeExtraDataList;            // 300
		NiPointer<NiNode> item3DGeometry;                              // 308
		BSTArray<TESForm*> queuedCraftingComponents;                   // 310
		std::uint64_t soundTimer;                                      // 328
		stl::enumeration<HighlightMode, std::uint32_t> highlightMode;  // 330
		Rumble::AutoRumblePause autoRumblePause;                       // 334
		bool initialized;                                              // 335
		bool soundsQueued;                                             // 336
	};
	static_assert(sizeof(WorkbenchMenuBase) == 0x340);

	class __declspec(novtable) ExamineConfirmMenu :
		public GameMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExamineConfirmMenu };
		static constexpr auto VTABLE{ VTABLE::ExamineConfirmMenu };
		static constexpr auto MENU_NAME{ "ExamineConfirmMenu"sv };

		enum class CONFIRM_TYPE
		{
			kSimple,
			kBuild,
			kScrap,
			kRepairFailure
		};

		class __declspec(novtable) ICallback
		{
		public:
			static constexpr auto RTTI{ RTTI::ExamineConfirmMenu__ICallback };
			static constexpr auto VTABLE{ VTABLE::ExamineConfirmMenu__ICallback };

			ICallback(ExamineMenu* a_thisMenu) :
				thisMenu(a_thisMenu)
			{
				stl::emplace_vtable(this);
			}

			virtual ~ICallback() = default;  // 00

			// add
			virtual void OnAccept() = 0;  // 01

			F4_HEAP_REDEFINE_NEW(ICallback);

			// members
			ExamineMenu* thisMenu;  // 08
		};
		static_assert(sizeof(ICallback) == 0x10);

		class __declspec(novtable) InitData
		{
		public:
			static constexpr auto RTTI{ RTTI::ExamineConfirmMenu__InitData };
			static constexpr auto VTABLE{ VTABLE::ExamineConfirmMenu__InitData };

			InitData(BSFixedString a_confirmQuestion, BSFixedStringCS a_buttonLabel, CONFIRM_TYPE a_confirmType) :
				confirmQuestion(a_confirmQuestion),
				buttonLabel(a_buttonLabel),
				confirmType(a_confirmType)
			{
				stl::emplace_vtable(this);
			}

			virtual ~InitData() = default;  // 00

			F4_HEAP_REDEFINE_NEW(InitData);

			// members
			BSFixedString confirmQuestion;                                                      // 08
			BSFixedStringCS buttonLabel;                                                        // 10
			stl::enumeration<CONFIRM_TYPE, std::int32_t> confirmType{ CONFIRM_TYPE::kSimple };  // 18
			bool hasCancelButton{ true };                                                       // 1C
		};
		static_assert(sizeof(InitData) == 0x20);

		class __declspec(novtable) InitDataScrap :
			public InitData  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::ExamineConfirmMenu__InitDataScrap };
			static constexpr auto VTABLE{ VTABLE::ExamineConfirmMenu__InitDataScrap };

			InitDataScrap(const char* a_confirmQuestion, const char* a_buttonLabel, const char* a_scrapSourceName, BSTArray<BSTTuple<TESBoundObject*, std::uint32_t>> a_scrapResults) :
				InitData(a_confirmQuestion, a_buttonLabel, CONFIRM_TYPE::kScrap),
				scrapSourceName(a_scrapSourceName),
				scrapResults(a_scrapResults)
			{
				stl::emplace_vtable(this);
			}

			virtual ~InitDataScrap() = default;  // 00

			F4_HEAP_REDEFINE_NEW(InitDataScrap);

			// members
			BSFixedStringCS scrapSourceName;                                  // 20
			BSTArray<BSTTuple<TESBoundObject*, std::uint32_t>> scrapResults;  // 28
		};
		static_assert(sizeof(InitDataScrap) == 0x40);

		// members
		Scaleform::GFx::Value confirmObj;  // E0
	};
	static_assert(sizeof(ExamineConfirmMenu) == 0x100);

	class __declspec(novtable) ScrapItemCallback :
		public ExamineConfirmMenu::ICallback  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::__ScrapItemCallback };
		static constexpr auto VTABLE{ VTABLE::__ScrapItemCallback };

		ScrapItemCallback(ExamineMenu* a_thisMenu, std::uint32_t a_itemIndex) :
			ExamineConfirmMenu::ICallback(a_thisMenu),
			itemIndex(a_itemIndex)
		{
			stl::emplace_vtable(this);
		}

		virtual ~ScrapItemCallback() = default;  // 00

		// override
		virtual void OnAccept() override;  // 01

		F4_HEAP_REDEFINE_NEW(ScrapItemCallback);

		// members
		std::uint32_t itemIndex;  // 10
	};
	static_assert(sizeof(ScrapItemCallback) == 0x18);

	class __declspec(novtable) ExamineMenu :
		public WorkbenchMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExamineMenu };
		static constexpr auto VTABLE{ VTABLE::ExamineMenu };
		static constexpr auto MENU_NAME{ "ExamineMenu"sv };

		enum class INSPECT_MODE_STATE;

		struct ComponentBuilderFunctor
		{
		public:
			// members
			BSTArray<BSTTuple<BGSComponent*, std::uint8_t>> components;  // 00
			TESObjectMISC* a_object;                                     // 18
			std::uint32_t a_index;                                       // 20
		};
		static_assert(sizeof(ComponentBuilderFunctor) == 0x28);

		virtual ~ExamineMenu();  // 00

		// override (WorkbenchMenuBase)
		virtual void Call(const Params&) override;                                    // 01
		virtual void MapCodeObjectFunctions() override;                               // 02
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;     // 03
		virtual void AdvanceMovie(float a_timeDelta, std::uint64_t a_time) override;  // 04
		virtual void OnHideMenu() override;                                           // 14
		virtual void BuildConfirmed(bool a_ownerIsWorkbench) override;                // 17
		virtual bool TryCreate() override;                                            // 1B

		// override (BSInputEventUser)
		virtual bool ShouldHandleEvent(const InputEvent*) override;  // 01
		virtual void HandleEvent(const ThumbstickEvent*) override;   // 04
		virtual void HandleEvent(const CursorMoveEvent*) override;   // 05
		virtual void HandleEvent(const ButtonEvent*) override;       // 08

		// add
		virtual EQUIP_TYPE GetInventoryEntryEquipState(const InventoryUserUIInterfaceEntry& a_entry);                                                    // 1C
		virtual void ShowCurrent3D();                                                                                                                    // 1D
		virtual TESBoundObject* GetCurrentObj();                                                                                                         // 1E
		virtual void FindWeaponMods(TESBoundObject* a_object, Scaleform::GFx::Value& a_modList);                                                         // 1F
		virtual void BuildPossibleModList(TESBoundObject* a_object);                                                                                     // 20
		virtual void SwitchMod(std::int32_t a_index, Scaleform::GFx::Value& a_entryList);                                                                // 21
		virtual void NextItemPart();                                                                                                                     // 22
		virtual void PreviousItemPart();                                                                                                                 // 23
		virtual void AttachModToPreview(bool a_storeModelPosition);                                                                                      // 24
		virtual BGSObjectInstanceExtra* GetInitialObjectInstanceExtra();                                                                                 // 25
		virtual BGSObjectInstanceExtra* GetObjectInstanceExtra();                                                                                        // 26
		virtual const ExtraDataList* GetItemExtraDataList();                                                                                             // 27
		virtual void HighlightWeaponPart();                                                                                                              // 28
		virtual void ResetHighlight();                                                                                                                   // 29
		virtual void CreateModdedInventoryItem();                                                                                                        // 2A
		virtual void RevertToInventoryItem();                                                                                                            // 2B
		virtual const char* GetCurrentName();                                                                                                            // 2C
		virtual void RenameCurrent(const char* a_newName);                                                                                               // 2D
		virtual void UpdateItemCard(bool a_compare);                                                                                                     // 2E
		virtual void UpdateItemList(std::int32_t a_indexToSelect);                                                                                       // 2F
		virtual const char* GetBuildConfirmButtonLabel();                                                                                                // 30
		virtual void GetBuildConfirmQuestion(char* a_buffer, std::uint32_t a_bufferLength);                                                              // 31
		virtual bool GetCanRepairSelectedItem();                                                                                                         // 32
		virtual NiAVObject* GetCurrent3D();                                                                                                              // 33
		virtual bool GetCurrent3DLoaded();                                                                                                               // 34
		virtual bool GetIsValidInventoryItem(const BGSInventoryItem& a_item, std::uint32_t a_stackID);                                                   // 35
		virtual const char* GetMenuName();                                                                                                               // 36
		virtual void OnSwitchBaseItem();                                                                                                                 // 37
		virtual void PopulateInventoryItemObj(ObjectRefHandle a_owner, const InventoryUserUIInterfaceEntry& a_entry, Scaleform::GFx::Value& a_itemObj);  // 38
		virtual void RegisterMenuComponents(const Scaleform::GFx::FunctionHandler::Params& a_params);                                                    // 39
		virtual void RepairSelectedItem();                                                                                                               // 3A
		virtual void SetFilter();                                                                                                                        // 3B
		virtual void SetMouseRotation(bool a_rotation);                                                                                                  // 3C
		virtual void ToggleItemEquipped();                                                                                                               // 3D
		virtual void UpdateModSlotList();                                                                                                                // 3E
		virtual void UpdateModChoiceList();                                                                                                              // 3F
		virtual const char* GetRankSuffix(std::uint32_t a_rank);                                                                                         // 40
		virtual bool QIgnoreRank();                                                                                                                      // 41
		virtual bool ShouldInitToFirstMod();                                                                                                             // 42
		virtual void SetDataForConditionCheck();                                                                                                         // 43
		virtual bool AddLooseModToModChoiceArray(BGSMod::Attachment::Mod* a_mod, std::uint8_t a_rank);                                                   // 44
		virtual bool ShouldShowModSlot(const BGSKeyword* a_keyword);                                                                                     // 45

		void BuildWeaponScrappingArray()
		{
			using func_t = decltype(&ExamineMenu::BuildWeaponScrappingArray);
			REL::Relocation<func_t> func{ REL::ID(646841) };
			return func(this);
		}

		[[nodiscard]] std::uint32_t GetSelectedIndex()
		{
			using func_t = decltype(&ExamineMenu::GetSelectedIndex);
			REL::Relocation<func_t> func{ REL::ID(776503) };
			return func(this);
		}

		void ShowConfirmMenu(ExamineConfirmMenu::InitData* a_data, ExamineConfirmMenu::ICallback* a_callback)
		{
			using func_t = decltype(&ExamineMenu::ShowConfirmMenu);
			REL::Relocation<func_t> func{ REL::ID(443081) };
			return func(this, a_data, a_callback);
		}

		// members
		ComponentBuilderFunctor componentFunctor;                              // 340
		stl::enumeration<INSPECT_MODE_STATE, std::uint32_t> inspectModeState;  // 368
		ObjectRefHandle inventorySource;                                       // 36C
		InventoryUserUIInterface invInterface;                                 // 370
		InventoryInterface::Handle modItem;                                    // 3F0
		std::uint32_t modStack;                                                // 3F4
		BSTHashMap<std::uint32_t, std::uint32_t> scrappableItemsMap;           // 3F8
		BSTArray<BSTTuple<TESBoundObject*, std::uint32_t>> scrappingArray;     // 420
		BSTArray<BSTTuple<NiAVObject*, BGSKeyword const*>> slotObjects;        // 440
		BSTSmartPointer<ExtraDataList> extraDataList;                          // 458
		std::uint32_t slotObjectIndex;                                         // 460
		Scaleform::GFx::Value buttonAnimBase;                                  // 468
		Scaleform::GFx::Value itemList;                                        // 488
		Scaleform::GFx::Value itemNameTextField;                               // 4A8
		Scaleform::GFx::Value itemInfoList;                                    // 4C8
		Scaleform::GFx::Value modChoiceList;                                   // 4E8
		Scaleform::GFx::Value modSlotList;                                     // 508
		Scaleform::GFx::Value currentModsList;                                 // 528
		BGSInventoryItem moddedInventoryItem;                                  // 548
		bool queueItemHighlight;                                               // 558
		float zoomDistance;                                                    // 55C
		float lastFrameDelta;                                                  // 560
		float menuCursorLeftPct;                                               // 564
		float menuCursorRightPct;                                              // 568
		float menuCursorTopPct;                                                // 56C
		float menuCursorBottomPct;                                             // 570
		BSTArray<BGSComponent*> queuedSoundArray;                              // 578
		std::byte attachPointSource3D[0x598 - 0x590];                          // 590 - TODO
		const BGSMod::Attachment::Mod* nullMod;                                // 598
		Scaleform::GFx::Value requirementsList;                                // 5A0
		Scaleform::GFx::Value itemSelectList;                                  // 5C0
		const BGSKeyword* keyword;                                             // 5E0
		bool queueChangeCameraPosition;                                        // 5E8
		bool returnToInspect;                                                  // 5E9
		bool highlightStoredItem;                                              // 5EA
		bool textEntry;                                                        // 5EB
		bool virtualKeyboardPendingEvt;                                        // 5EC
		bool inspectMode;                                                      // 5ED
		bool inspectingSingleItem;                                             // 5EE
		bool inspectingFeaturedItem;                                           // 5EF
		bool showFeaturedItemMessage;                                          // 5F0
		char renameItemTo[260];                                                // 5F1
		char renameItemCancelState[260];                                       // 6F5
		BSTSmartPointer<BSInputEnableLayer> inputLayer;                        // 800
	};
	static_assert(sizeof(ExamineMenu) == 0x810);

	class __declspec(novtable) LockpickingMenu :
		public GameMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::LockpickingMenu };
		static constexpr auto VTABLE{ VTABLE::LockpickingMenu };
		static constexpr auto MENU_NAME{ "LockpickingMenu"sv };

		virtual ~LockpickingMenu();  // 00

		// override (GameMenuBase)
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;      // 03
		virtual void AdvanceMovie(float a_timeDelta, std::uint64_t a_time) override;   // 04
		virtual bool OnButtonEventRelease(const BSFixedString& a_eventName) override;  // 0F

		// override (BSInputEventUser)
		virtual bool ShouldHandleEvent(const InputEvent*) override;  // 01
		virtual void HandleEvent(const ThumbstickEvent*) override;   // 04
		virtual void HandleEvent(const MouseMoveEvent*) override;    // 06
		virtual void HandleEvent(const ButtonEvent*) override;       // 08

		static void OpenLockpickingMenu(TESObjectREFR* a_lockedRef)
		{
			using func_t = decltype(&LockpickingMenu::OpenLockpickingMenu);
			REL::Relocation<func_t> func{ REL::ID(129892) };
			return func(a_lockedRef);
		}

		// members
		NiMatrix3 origPickRotate;              // 0E0
		NiPoint3 origPickTranslate;            // 110
		NiControllerManager* lockAnimManager;  // 120
		NiControllerSequence* lockIntroAnim;   // 128
		NiControllerSequence* lockRotateAnim;  // 130
		NiControllerManager* pickAnimManager;  // 138
		NiControllerSequence* pickIntroAnim;   // 140
		NiControllerSequence* pickBendAnim;    // 148
		NiControllerSequence* pickBreakAnim;   // 150
		NiControllerSequence* currPickAnim;    // 158
		NiControllerSequence* currLockAnim;    // 160
		void* lockModel;                       // 168
		void* pickModel;                       // 170
		NiPointer<NiNode> lockRoot;            // 178
		float currPickAnimElapsedSecs;         // 180
		float currLockAnimElapsedSecs;         // 184
		float pickAngle;                       // 188
		float lockAngle;                       // 18C
		float lockDamagePickAngle;             // 190
		float pickBreakSecs;                   // 194
		BSSoundHandle pickTensionSound;        // 198
		float sweetSpotCenter;                 // 1A0
		float sweetSpotLength;                 // 1A4
		float partialPickLength;               // 1A8
		std::uint32_t picksBroken;             // 1AC
		bool modelsInit;                       // 1B0
		bool animating;                        // 1B1
		bool turningLock;                      // 1B2
		bool menuCleanedUp;                    // 1B3
		bool tutorialMenuOpening;              // 1B4
		bool crimeDetected;                    // 1B5
		bool VATSWasEnabled;                   // 1B6
		bool VATSDepthTestMask;                // 1B7
	};
	static_assert(sizeof(LockpickingMenu) == 0x1C0);
}
