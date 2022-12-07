// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Zombies/Public/Zombies/Game/ZombiesGameInstanceBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZombiesGameInstanceBase() {}
// Cross Module References
	ZOMBIES_API UScriptStruct* Z_Construct_UScriptStruct_FMapInfo();
	UPackage* Z_Construct_UPackage__Script_Zombies();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ZOMBIES_API UClass* Z_Construct_UClass_UZombiesGameInstanceBase_NoRegister();
	ZOMBIES_API UClass* Z_Construct_UClass_UZombiesGameInstanceBase();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
// End Cross Module References
class UScriptStruct* FMapInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ZOMBIES_API uint32 Get_Z_Construct_UScriptStruct_FMapInfo_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FMapInfo, Z_Construct_UPackage__Script_Zombies(), TEXT("MapInfo"), sizeof(FMapInfo), Get_Z_Construct_UScriptStruct_FMapInfo_Hash());
	}
	return Singleton;
}
template<> ZOMBIES_API UScriptStruct* StaticStruct<FMapInfo>()
{
	return FMapInfo::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FMapInfo(FMapInfo::StaticStruct, TEXT("/Script/Zombies"), TEXT("MapInfo"), false, nullptr, nullptr);
static struct FScriptStruct_Zombies_StaticRegisterNativesFMapInfo
{
	FScriptStruct_Zombies_StaticRegisterNativesFMapInfo()
	{
		UScriptStruct::DeferCppStructOps<FMapInfo>(FName(TEXT("MapInfo")));
	}
} ScriptStruct_Zombies_StaticRegisterNativesFMapInfo;
	struct Z_Construct_UScriptStruct_FMapInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MapURL_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_MapURL;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MapName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_MapName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MapDescription_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_MapDescription;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MapImage_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MapImage;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMapInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Zombies/Game/ZombiesGameInstanceBase.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMapInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMapInfo>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapURL_MetaData[] = {
		{ "Category", "MapInfo" },
		{ "ModuleRelativePath", "Public/Zombies/Game/ZombiesGameInstanceBase.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapURL = { "MapURL", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMapInfo, MapURL), METADATA_PARAMS(Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapURL_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapURL_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapName_MetaData[] = {
		{ "Category", "MapInfo" },
		{ "ModuleRelativePath", "Public/Zombies/Game/ZombiesGameInstanceBase.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapName = { "MapName", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMapInfo, MapName), METADATA_PARAMS(Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapDescription_MetaData[] = {
		{ "Category", "MapInfo" },
		{ "ModuleRelativePath", "Public/Zombies/Game/ZombiesGameInstanceBase.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapDescription = { "MapDescription", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMapInfo, MapDescription), METADATA_PARAMS(Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapDescription_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapDescription_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapImage_MetaData[] = {
		{ "Category", "MapInfo" },
		{ "ModuleRelativePath", "Public/Zombies/Game/ZombiesGameInstanceBase.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapImage = { "MapImage", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMapInfo, MapImage), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapImage_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapImage_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMapInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapURL,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapDescription,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMapInfo_Statics::NewProp_MapImage,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMapInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Zombies,
		nullptr,
		&NewStructOps,
		"MapInfo",
		sizeof(FMapInfo),
		alignof(FMapInfo),
		Z_Construct_UScriptStruct_FMapInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMapInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMapInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMapInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMapInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FMapInfo_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_Zombies();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("MapInfo"), sizeof(FMapInfo), Get_Z_Construct_UScriptStruct_FMapInfo_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FMapInfo_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FMapInfo_Hash() { return 348080924U; }
	DEFINE_FUNCTION(UZombiesGameInstanceBase::execGoToMap)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_MapURL);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GoToMap(Z_Param_MapURL);
		P_NATIVE_END;
	}
	void UZombiesGameInstanceBase::StaticRegisterNativesUZombiesGameInstanceBase()
	{
		UClass* Class = UZombiesGameInstanceBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GoToMap", &UZombiesGameInstanceBase::execGoToMap },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UZombiesGameInstanceBase_GoToMap_Statics
	{
		struct ZombiesGameInstanceBase_eventGoToMap_Parms
		{
			FString MapURL;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_MapURL;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UZombiesGameInstanceBase_GoToMap_Statics::NewProp_MapURL = { "MapURL", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZombiesGameInstanceBase_eventGoToMap_Parms, MapURL), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZombiesGameInstanceBase_GoToMap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZombiesGameInstanceBase_GoToMap_Statics::NewProp_MapURL,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZombiesGameInstanceBase_GoToMap_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Zombies/Game/ZombiesGameInstanceBase.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UZombiesGameInstanceBase_GoToMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZombiesGameInstanceBase, nullptr, "GoToMap", nullptr, nullptr, sizeof(ZombiesGameInstanceBase_eventGoToMap_Parms), Z_Construct_UFunction_UZombiesGameInstanceBase_GoToMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZombiesGameInstanceBase_GoToMap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZombiesGameInstanceBase_GoToMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZombiesGameInstanceBase_GoToMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZombiesGameInstanceBase_GoToMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UZombiesGameInstanceBase_GoToMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UZombiesGameInstanceBase_NoRegister()
	{
		return UZombiesGameInstanceBase::StaticClass();
	}
	struct Z_Construct_UClass_UZombiesGameInstanceBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UZombiesGameInstanceBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_Zombies,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UZombiesGameInstanceBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UZombiesGameInstanceBase_GoToMap, "GoToMap" }, // 2778137829
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UZombiesGameInstanceBase_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Zombies/Game/ZombiesGameInstanceBase.h" },
		{ "ModuleRelativePath", "Public/Zombies/Game/ZombiesGameInstanceBase.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UZombiesGameInstanceBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UZombiesGameInstanceBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UZombiesGameInstanceBase_Statics::ClassParams = {
		&UZombiesGameInstanceBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UZombiesGameInstanceBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UZombiesGameInstanceBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UZombiesGameInstanceBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UZombiesGameInstanceBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UZombiesGameInstanceBase, 1052231101);
	template<> ZOMBIES_API UClass* StaticClass<UZombiesGameInstanceBase>()
	{
		return UZombiesGameInstanceBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UZombiesGameInstanceBase(Z_Construct_UClass_UZombiesGameInstanceBase, &UZombiesGameInstanceBase::StaticClass, TEXT("/Script/Zombies"), TEXT("UZombiesGameInstanceBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UZombiesGameInstanceBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
