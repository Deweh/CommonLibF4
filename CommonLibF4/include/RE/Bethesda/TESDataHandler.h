#pragma once

#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTList.h"
#include "RE/Bethesda/BSTSingleton.h"
#include "RE/Bethesda/TESFile.h"
#include "RE/Bethesda/TESForms.h"
#include "RE/NetImmerse/NiTArray.h"
#include "RE/NetImmerse/NiTList.h"

namespace RE
{
	class TESRegionDataManager;

	struct BGSHotloadCompletedEvent;
	struct TESObjectList;
	struct TESRegionList;

	class __declspec(novtable) NEW_REFR_DATA
	{
	public:
		static constexpr auto RTTI{ RTTI::NEW_REFR_DATA };
		static constexpr auto VTABLE{ VTABLE::NEW_REFR_DATA };

		NEW_REFR_DATA()
		{
			stl::emplace_vtable(this);
		}

		virtual void HandlePre3D(TESObjectREFR*) { return; }

		// members
		NiPoint3 location;                                // 08
		NiPoint3 direction;                               // 14
		TESBoundObject* object{ nullptr };                // 20
		TESObjectCELL* interior{ nullptr };               // 28
		TESWorldSpace* world{ nullptr };                  // 30
		TESObjectREFR* reference{ nullptr };              // 38
		BGSPrimitive* addPrimitive{ nullptr };            // 40
		void* additionalData{ nullptr };                  // 48
		BSTSmartPointer<ExtraDataList> extra{ nullptr };  // 50
		INSTANCE_FILTER* instanceFilter{ nullptr };       // 58
		BGSObjectInstanceExtra* modExtra{ nullptr };      // 60
		std::uint16_t maxLevel{ 0 };                      // 68
		bool forcePersist{ false };                       // 6A
		bool clearStillLoadingFlag{ false };              // 6B
		bool initializeScripts{ true };                   // 6C
		bool initiallyDisabled{ false };                  // 6D
	};
	static_assert(sizeof(NEW_REFR_DATA) == 0x70);

	struct TESFileCollection
	{
	public:
		// members
		BSTArray<TESFile*> files;       // 00
		BSTArray<TESFile*> smallFiles;  // 18
	};
	static_assert(sizeof(TESFileCollection) == 0x30);

	class TESDataHandler :
		public BSTEventSource<BGSHotloadCompletedEvent>,  // 0000
		public BSTSingletonSDM<TESDataHandler>            // 0058
	{
	public:
		[[nodiscard]] static TESDataHandler* GetSingleton()
		{
			REL::Relocation<TESDataHandler**> singleton{ REL::ID(711558) };
			return *singleton;
		}

		[[nodiscard]] bool AddFormToDataHandler(TESForm* a_form)
		{
			using func_t = decltype(&TESDataHandler::AddFormToDataHandler);
			REL::Relocation<func_t> func{ REL::ID(350112) };
			return func(this, a_form);
		}

		[[nodiscard]] bool CheckModsLoaded(bool a_everModded)
		{
			using func_t = decltype(&TESDataHandler::CheckModsLoaded);
			REL::Relocation<func_t> func{ REL::ID(1432894) };
			return func(this, a_everModded);
		}

		[[nodiscard]] ObjectRefHandle CreateReferenceAtLocation(NEW_REFR_DATA& a_data)
		{
			using func_t = decltype(&TESDataHandler::CreateReferenceAtLocation);
			REL::Relocation<func_t> func{ REL::ID(500304) };
			return func(this, a_data);
		}

		template <class T>
		[[nodiscard]] BSTArray<T*>& GetFormArray() noexcept  //
			requires(std::derived_from<T, TESForm> &&
					 !std::is_pointer_v<T> &&
					 !std::is_reference_v<T>)
		{
			assert(T::FORM_ID < ENUM_FORM_ID::kTotal);
			return reinterpret_cast<BSTArray<T*>&>(formArrays[stl::to_underlying(T::FORM_ID)]);
		}

		TESForm* LookupForm(std::uint32_t a_rawFormID, std::string_view a_modName)
		{
			auto file = LookupLoadedFile(a_modName);
			if (!file.first) {
				return nullptr;
			}

			uint32_t formID = 0;
			if (file.second) {
				formID = file.first->compileIndex << 24;
				formID += (a_rawFormID & 0x00FFFFFF);
			} else {
				formID = 0xFE000000;
				formID += file.first->smallFileCompileIndex << 12;
				formID += (a_rawFormID & 0x00000FFF);
			}

			return TESForm::GetFormByID(formID);
		}

		template <class T>
		T* LookupForm(std::uint32_t a_rawFormID, std::string_view a_modName)
		{
			auto form = LookupForm(a_rawFormID, a_modName);
			if (!form) {
				return nullptr;
			}

			return form->As<T>();
		}

		const std::pair<TESFile*, bool> LookupLoadedFile(std::string_view a_fileName) {
			std::pair<TESFile*, bool> result;
			for (auto fullFile : compiledFileCollection.files) {
				if (a_fileName.size() == strlen(fullFile->filename) &&
					_strnicmp(fullFile->filename, a_fileName.data(), a_fileName.size()) == 0) {
					return { fullFile, true };
				}
			}
			for (auto smallFile : compiledFileCollection.smallFiles) {
				if (a_fileName.size() == strlen(smallFile->filename) &&
					_strnicmp(smallFile->filename, a_fileName.data(), a_fileName.size()) == 0) {
					return { smallFile, false };
				}
			}
			return { nullptr, false };
		}

		const TESFile* LookupModByName(std::string_view a_modName)
		{
			for (auto& file : files) {
				if (a_modName.size() == strlen(file->filename) &&
					_strnicmp(file->filename, a_modName.data(), a_modName.size()) == 0) {
					return file;
				}
			}
			return nullptr;
		}

		std::optional<std::uint8_t> GetModIndex(std::string_view a_modName)
		{
			auto mod = LookupModByName(a_modName);
			return mod ? std::make_optional(mod->compileIndex) : std::nullopt;
		}

		const TESFile* LookupLoadedModByName(std::string_view a_modName)
		{
			for (auto& file : compiledFileCollection.files) {
				if (a_modName.size() == strlen(file->filename) &&
					_strnicmp(file->filename, a_modName.data(), a_modName.size()) == 0) {
					return file;
				}
			}
			return nullptr;
		}

		const TESFile* LookupLoadedModByIndex(std::uint8_t a_index)
		{
			for (auto& file : compiledFileCollection.files) {
				if (file->compileIndex == a_index) {
					return file;
				}
			}
			return nullptr;
		}

		std::optional<std::uint8_t> GetLoadedModIndex(std::string_view a_modName)
		{
			auto mod = LookupLoadedModByName(a_modName);
			return mod ? std::make_optional(mod->compileIndex) : std::nullopt;
		}

		const TESFile* LookupLoadedLightModByName(std::string_view a_modName)
		{
			for (auto& smallFile : compiledFileCollection.smallFiles) {
				if (a_modName.size() == strlen(smallFile->filename) &&
					_strnicmp(smallFile->filename, a_modName.data(), a_modName.size()) == 0) {
					return smallFile;
				}
			}
			return nullptr;
		}

		const TESFile* LookupLoadedLightModByIndex(std::uint16_t a_index)
		{
			for (auto& smallFile : compiledFileCollection.smallFiles) {
				if (smallFile->smallFileCompileIndex == a_index) {
					return smallFile;
				}
			}
			return nullptr;
		}

		std::optional<std::uint16_t> GetLoadedLightModIndex(std::string_view a_modName)
		{
			auto mod = LookupLoadedLightModByName(a_modName);
			return mod ? std::make_optional(mod->smallFileCompileIndex) : std::nullopt;
		}

		// members
		TESObjectList* objectList;                                                // 0060
		BSTArray<TESForm*> formArrays[stl::to_underlying(ENUM_FORM_ID::kTotal)];  // 0068
		TESRegionList* regionList;                                                // 0F50
		NiTPrimitiveArray<TESObjectCELL*> interiorCells;                          // 0F58
		NiTPrimitiveArray<BGSAddonNode*> addonNodes;                              // 0F70
		NiTList<TESForm*> badForms;                                               // 0F88
		std::uint32_t nextID;                                                     // 0FA0
		TESFile* activeFile;                                                      // 0FA8
		BSSimpleList<TESFile*> files;                                             // 0FB0
		TESFileCollection compiledFileCollection;                                 // 0FC0
		BSTArray<std::uint32_t> releasedFormIDArray;                              // 0FF0
		bool masterSave;                                                          // 1008
		bool blockSave;                                                           // 1009
		bool saveLoadGame;                                                        // 100A
		bool autoSaving;                                                          // 100B
		bool exportingPlugin;                                                     // 100C
		bool clearingData;                                                        // 100D
		bool hasDesiredFiles;                                                     // 100E
		bool checkingModels;                                                      // 100F
		bool loadingFiles;                                                        // 1010
		bool dontRemoveIDs;                                                       // 1011
		char gameSettingsLoadState;                                               // 1012
		TESRegionDataManager* regionDataManager;                                  // 1018
	};
	static_assert(sizeof(TESDataHandler) == 0x1020);
}
