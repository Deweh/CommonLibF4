#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSScript.h"
#include "RE/Bethesda/BSScript/Array.h"
#include "RE/Bethesda/BSScript/ArrayWrapper.h"
#include "RE/Bethesda/BSScript/CompiledScriptLoader.h"
#include "RE/Bethesda/BSScript/ErrorLogger.h"
#include "RE/Bethesda/BSScript/ICachedErrorMessage.h"
#include "RE/Bethesda/BSScript/IClientVM.h"
#include "RE/Bethesda/BSScript/IComplexType.h"
#include "RE/Bethesda/BSScript/IFunction.h"
#include "RE/Bethesda/BSScript/IHandleReaderWriter.h"
#include "RE/Bethesda/BSScript/ILoader.h"
#include "RE/Bethesda/BSScript/IMemoryPagePolicy.h"
#include "RE/Bethesda/BSScript/IObjectHandlePolicy.h"
#include "RE/Bethesda/BSScript/IObjectProcessor.h"
#include "RE/Bethesda/BSScript/IProfilePolicy.h"
#include "RE/Bethesda/BSScript/ISavePatcherInterface.h"
#include "RE/Bethesda/BSScript/IStackCallbackFunctor.h"
#include "RE/Bethesda/BSScript/IStackCallbackSaveInterface.h"
#include "RE/Bethesda/BSScript/IVMDebugInterface.h"
#include "RE/Bethesda/BSScript/IVMObjectBindInterface.h"
#include "RE/Bethesda/BSScript/IVMSaveLoadInterface.h"
#include "RE/Bethesda/BSScript/IVirtualMachine.h"
#include "RE/Bethesda/BSScript/Internal/AttachedScript.h"
#include "RE/Bethesda/BSScript/Internal/CodeTasklet.h"
#include "RE/Bethesda/BSScript/Internal/EventRelay.h"
#include "RE/Bethesda/BSScript/Internal/FunctionMessage.h"
#include "RE/Bethesda/BSScript/Internal/IFuncCallQuery.h"
#include "RE/Bethesda/BSScript/Internal/RawFuncCallQuery.h"
#include "RE/Bethesda/BSScript/Internal/ReadableStringTable.h"
#include "RE/Bethesda/BSScript/Internal/ReadableTypeTable.h"
#include "RE/Bethesda/BSScript/Internal/ScriptFunction.h"
#include "RE/Bethesda/BSScript/Internal/SuspendedStack.h"
#include "RE/Bethesda/BSScript/Internal/VDescTable.h"
#include "RE/Bethesda/BSScript/Internal/VirtualMachine.h"
#include "RE/Bethesda/BSScript/Internal/WritableStringTable.h"
#include "RE/Bethesda/BSScript/Internal/WritableTypeTable.h"
#include "RE/Bethesda/BSScript/LinkerProcessor.h"
#include "RE/Bethesda/BSScript/LogEvent.h"
#include "RE/Bethesda/BSScript/MergedBoundScript.h"
#include "RE/Bethesda/BSScript/NF_util/NativeFunctionBase.h"
#include "RE/Bethesda/BSScript/Object.h"
#include "RE/Bethesda/BSScript/ObjectBindPolicy.h"
#include "RE/Bethesda/BSScript/ObjectTypeInfo.h"
#include "RE/Bethesda/BSScript/PackedInstructionStream.h"
#include "RE/Bethesda/BSScript/PropertyGroupInfo.h"
#include "RE/Bethesda/BSScript/PropertyTypeInfo.h"
#include "RE/Bethesda/BSScript/SimpleAllocMemoryPagePolicy.h"
#include "RE/Bethesda/BSScript/Stack.h"
#include "RE/Bethesda/BSScript/StackFrame.h"
#include "RE/Bethesda/BSScript/StatsEvent.h"
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
