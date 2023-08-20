#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSScript/Array.h"
#include "RE/Bethesda/BSScript/ErrorLogger.h"
#include "RE/Bethesda/BSScript/ICachedErrorMessage.h"
#include "RE/Bethesda/BSScript/IFunction.h"
#include "RE/Bethesda/BSScript/ILoader.h"
#include "RE/Bethesda/BSScript/IObjectHandlePolicy.h"
#include "RE/Bethesda/BSScript/ISavePatcherInterface.h"
#include "RE/Bethesda/BSScript/IStackCallbackFunctor.h"
#include "RE/Bethesda/BSScript/Object.h"
#include "RE/Bethesda/BSScript/ObjectBindPolicy.h"
#include "RE/Bethesda/BSScript/ObjectTypeInfo.h"
#include "RE/Bethesda/BSScript/Struct.h"
#include "RE/Bethesda/BSScript/StructTypeInfo.h"
#include "RE/Bethesda/BSScript/TypeInfo.h"
#include "RE/Bethesda/BSScript/Variable.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSTObjectArena.h"
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/Bethesda/BSTTuple.h"
#include "RE/Bethesda/MemoryManager.h"

namespace RE
{
	template <class F>
	using BSTThreadScrapFunction = msvc::function<F>;

	namespace BSScript
	{
		class Array;
		class BoundScript;  // stub
		class ErrorLogger;
		class ICachedErrorMessage;
		class IFunction;
		class ISavePatcherInterface;
		class IStackCallbackFunctor;
		class ITypeLinkedCallback;  // stub
		class JobList;              // stub
		class Object;
		class ObjectBindPolicy;
		class ObjectTypeInfo;
		class Struct;
		class StructTypeInfo;
		class TypeInfo;
		class Variable;

		struct ILoader;
		struct IObjectHandlePolicy;
		struct LogEvent;
		struct StatsEvent;

		namespace UnlinkedTypes
		{
			struct Object;  // stub
		}

		class __declspec(novtable) IVirtualMachine :
			public BSIntrusiveRefCounted  // 08
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__IVirtualMachine };
			static constexpr auto VTABLE{ VTABLE::BSScript__IVirtualMachine };

			virtual ~IVirtualMachine() = default;  // 00

			// add
			virtual void SetLoader(ILoader* a_newLoader) = 0;                                                                                                                                                                                                                                                           // 01
			virtual void SetLinkedCallback(ITypeLinkedCallback* a_typeLinkedCallback) = 0;                                                                                                                                                                                                                              // 02
			virtual void Update(float a_updateBudget) = 0;                                                                                                                                                                                                                                                              // 03
			virtual void UpdateTasklets(float a_updateBudget) = 0;                                                                                                                                                                                                                                                      // 04
			virtual void SetOverstressed(bool a_overstressed) = 0;                                                                                                                                                                                                                                                      // 05
			virtual bool IsCompletelyFrozen() const = 0;                                                                                                                                                                                                                                                                // 06
			virtual bool RegisterObjectType(std::uint32_t a_typeID, const char* a_objectTypeName) = 0;                                                                                                                                                                                                                  // 07
			virtual bool GetScriptObjectType(std::uint32_t a_typeID, BSTSmartPointer<ObjectTypeInfo>& a_objType) = 0;                                                                                                                                                                                                   // 09
			virtual bool GetScriptObjectType(const BSFixedString& a_name, BSTSmartPointer<ObjectTypeInfo>& a_objType) = 0;                                                                                                                                                                                              // 08
			virtual bool GetScriptObjectTypeNoLoad(std::uint32_t a_typeID, BSTSmartPointer<ObjectTypeInfo>& a_objType) const = 0;                                                                                                                                                                                       // 0B
			virtual bool GetScriptObjectTypeNoLoad(const BSFixedString& a_objectTypeName, BSTSmartPointer<ObjectTypeInfo>& a_objType) const = 0;                                                                                                                                                                        // 0A
			virtual bool GetTypeIDForScriptObject(const BSFixedString& a_objectTypeName, std::uint32_t& a_typeID) const = 0;                                                                                                                                                                                            // 0C
			virtual void GetScriptObjectsWithATypeID(BSScrapArray<BSFixedString>& a_objectTypeList) const = 0;                                                                                                                                                                                                          // 0D
			virtual bool GetParentNativeType(const BSFixedString& a_childTypeName, BSTSmartPointer<ObjectTypeInfo>& a_parentType) = 0;                                                                                                                                                                                  // 0E
			virtual bool TypeIsValid(const BSFixedString& a_objectTypeName) = 0;                                                                                                                                                                                                                                        // 0F
			virtual bool ReloadType(const char* a_objectTypeName) = 0;                                                                                                                                                                                                                                                  // 10
			virtual void TasksToJobs(JobList& a_jobList) = 0;                                                                                                                                                                                                                                                           // 11
			virtual void CalculateFullReloadList(const BSTSet<BSFixedString>& a_scriptSet, BSTObjectArena<BSFixedString>& a_scriptList) const = 0;                                                                                                                                                                      // 12
			virtual bool GetScriptStructType(const BSFixedString& a_structTypeName, BSTSmartPointer<StructTypeInfo>& a_structType) = 0;                                                                                                                                                                                 // 13
			virtual bool GetScriptStructTypeNoLoad(const BSFixedString& a_structTypeName, BSTSmartPointer<StructTypeInfo>& a_structType) const = 0;                                                                                                                                                                     // 14
			virtual bool GetChildStructTypes(const BSFixedString& a_parentObjectName, BSTObjectArena<BSFixedString>& a_structTypes) const = 0;                                                                                                                                                                          // 15
			virtual bool CreateObject(const BSFixedString& a_objectTypeName, BSTSmartPointer<Object>& a_newObj) = 0;                                                                                                                                                                                                    // 17
			virtual bool CreateObject(const BSFixedString& a_objectTypeName, const BSTScrapHashMap<BSFixedString, Variable>& a_properties, BSTSmartPointer<Object>& a_newObj) = 0;                                                                                                                                      // 16
			virtual bool CreateStruct(const BSFixedString& a_structTypeName, BSTSmartPointer<Struct>& a_newStruct) = 0;                                                                                                                                                                                                 // 18
			virtual bool CreateArray(TypeInfo::RawType a_elementType, const BSFixedString& a_elementObjectTypeName, std::uint32_t a_elementCount, BSTSmartPointer<Array>& a_newArray) = 0;                                                                                                                              // 1A
			virtual bool CreateArray(const TypeInfo& a_type, std::uint32_t a_elementCount, BSTSmartPointer<Array>& a_newArray) = 0;                                                                                                                                                                                     // 19
			virtual bool BindNativeMethod(IFunction* a_function) = 0;                                                                                                                                                                                                                                                   // 1B
			virtual void SetCallableFromTasklets(const char* a_objectName, const char* a_functionName, bool a_taskletCallable) = 0;                                                                                                                                                                                     // 1D
			virtual void SetCallableFromTasklets(const char* a_objectName, const char* a_stateName, const char* a_functionName, bool a_taskletCallable) = 0;                                                                                                                                                            // 1C
			virtual void ForEachBoundObject(std::uint64_t a_objHandle, const BSTThreadScrapFunction<BSContainer::ForEachResult(Object*)>& a_functor) = 0;                                                                                                                                                               // 1E
			virtual bool FindBoundObject(std::uint64_t a_objHandle, const char* a_objectTypeName, bool a_allowConst, BSTSmartPointer<Object>& a_attachedObj, bool a_exactMatch) const = 0;                                                                                                                              // 1F
			virtual void MoveBoundObjects(std::uint64_t a_sourceHandle, std::uint64_t a_destHandle) = 0;                                                                                                                                                                                                                // 20
			virtual void ResetAllBoundObjects(std::uint64_t a_objHandle) = 0;                                                                                                                                                                                                                                           // 21
			virtual bool CastObject(const BSTSmartPointer<Object>& a_sourceObj, const BSTSmartPointer<ObjectTypeInfo>& a_targetType, BSTSmartPointer<Object>& a_castedObj) = 0;                                                                                                                                         // 22
			virtual bool SetPropertyValue(const BSTSmartPointer<Object>& a_self, const char* a_propName, const Variable& a_newValue, const BSTSmartPointer<IStackCallbackFunctor>& a_callback) = 0;                                                                                                                     // 23
			virtual bool GetPropertyValue(const BSTSmartPointer<Object>& a_self, const char* a_propName, const BSTSmartPointer<IStackCallbackFunctor>& a_callback) = 0;                                                                                                                                                 // 24
			virtual bool GetVariableValue(std::uint64_t a_objHandle, const BSFixedString& a_scriptName, std::uint32_t a_varIndex, Variable& a_var) const = 0;                                                                                                                                                           // 26
			virtual bool GetVariableValue(const BSTSmartPointer<Object>& a_obj, std::uint32_t a_varIndex, Variable& a_var) const = 0;                                                                                                                                                                                   // 25
			virtual bool HandleImplementsEvent(std::uint64_t a_object, const BSFixedString& a_eventName) const = 0;                                                                                                                                                                                                     // 27
			virtual bool AddEventRelay(std::uint64_t a_sourceObject, const BSFixedString& a_eventName, const BSTSmartPointer<Object>& a_destObj) = 0;                                                                                                                                                                   // 28
			virtual void RemoveEventRelay(std::uint64_t a_sourceObject, const BSFixedString& a_eventName, const BSTSmartPointer<Object>& a_destObj) = 0;                                                                                                                                                                // 29
			virtual void RemoveAllEventRelays(const BSTSmartPointer<Object>& a_destObj) = 0;                                                                                                                                                                                                                            // 2A
			virtual void SendEvent(std::uint64_t a_objHandle, const BSFixedString& a_eventName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTThreadScrapFunction<bool(const BSTSmartPointer<Object>&)>& a_filter, const BSTSmartPointer<IStackCallbackFunctor>& a_callback) = 0;  // 2B
			virtual bool DispatchStaticCall(const BSFixedString& a_objName, const BSFixedString& a_funcName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTSmartPointer<IStackCallbackFunctor>& a_callback) = 0;                                                                   // 2C
			virtual bool DispatchMethodCall(std::uint64_t a_objHandle, const BSFixedString& a_objName, const BSFixedString& a_funcName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTSmartPointer<IStackCallbackFunctor>& a_callback) = 0;                                        // 2E
			virtual bool DispatchMethodCall(const BSTSmartPointer<Object>& a_self, const BSFixedString& a_funcName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTSmartPointer<IStackCallbackFunctor>& a_callback) = 0;                                                            // 2D
			virtual bool DispatchUnboundMethodCall(std::uint64_t a_objHandle, const BSTSmartPointer<BoundScript>& a_script, const BSFixedString& a_funcName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTSmartPointer<IStackCallbackFunctor>& a_callback) = 0;                   // 2F
			virtual bool IsWaitingOnLatent(std::uint32_t a_stackID) const = 0;                                                                                                                                                                                                                                          // 30
			virtual void ReturnFromLatent(std::uint32_t a_stackID, const Variable& a_retValue) = 0;                                                                                                                                                                                                                     // 31
			[[nodiscard]] virtual ErrorLogger& GetErrorLogger() const = 0;                                                                                                                                                                                                                                              // 32
			[[nodiscard]] virtual const IObjectHandlePolicy& GetObjectHandlePolicy() const = 0;                                                                                                                                                                                                                         // 34
			[[nodiscard]] virtual IObjectHandlePolicy& GetObjectHandlePolicy() = 0;                                                                                                                                                                                                                                     // 33
			[[nodiscard]] virtual const ObjectBindPolicy& GetObjectBindPolicy() const = 0;                                                                                                                                                                                                                              // 36
			[[nodiscard]] virtual ObjectBindPolicy& GetObjectBindPolicy() = 0;                                                                                                                                                                                                                                          // 35
			[[nodiscard]] virtual ISavePatcherInterface& GetSavePatcherInterface() = 0;                                                                                                                                                                                                                                 // 37
			virtual void RegisterForLogEvent(BSTEventSink<LogEvent>* a_sink) = 0;                                                                                                                                                                                                                                       // 38
			virtual void UnregisterForLogEvent(BSTEventSink<LogEvent>* a_sink) = 0;                                                                                                                                                                                                                                     // 39
			virtual void RegisterForStatsEvent(BSTEventSink<StatsEvent>* a_sink) = 0;                                                                                                                                                                                                                                   // 3A
			virtual void UnregisterForStatsEvent(BSTEventSink<StatsEvent>* a_sink) = 0;                                                                                                                                                                                                                                 // 3B
			virtual void PostCachedErrorToLogger(const ICachedErrorMessage& a_errorFunctor, ErrorLogger::Severity a_severity) const = 0;                                                                                                                                                                                // 3D
			virtual void PostCachedErrorToLogger(const ICachedErrorMessage& a_errorFunctor, std::uint32_t a_stackID, ErrorLogger::Severity a_severity) const = 0;                                                                                                                                                       // 3C

			template <typename LT = bool, class F>
			void BindNativeMethod(
				stl::zstring a_object,
				stl::zstring a_function,
				F a_func,
				std::optional<bool> a_taskletCallable = std::nullopt,
				bool a_isLatent = false);

			void PostError(std::string_view a_msg, std::uint32_t a_stackID, ErrorLogger::Severity a_severity)
			{
				class ErrorImpl :
					public ICachedErrorMessage
				{
				public:
					ErrorImpl(std::string_view a_message) noexcept :
						_message(a_message)
					{}

					void GetErrorMsg(BSFixedString& a_message) const override { a_message = _message; }

				private:
					std::string_view _message;
				};

				const ErrorImpl e{ a_msg };
				PostCachedErrorToLogger(e, a_stackID, a_severity);
			}

			void PostErrorStr(std::string a_msg, std::uint32_t a_stackID, ErrorLogger::Severity a_severity)
			{
				class ErrorImpl :
					public ICachedErrorMessage
				{
				public:
					ErrorImpl(std::string a_message) noexcept :
						_message(a_message)
					{}

					void GetErrorMsg(BSFixedString& a_message) const override { a_message = _message; }

				private:
					std::string _message;
				};

				const ErrorImpl e{ a_msg };
				PostCachedErrorToLogger(e, a_stackID, a_severity);
			}
		};
		static_assert(sizeof(IVirtualMachine) == 0x10);
	}
}
