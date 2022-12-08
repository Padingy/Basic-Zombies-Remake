// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Zombies/Public/Zombies/Game/CustomZombiesGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomZombiesGameMode() {}
// Cross Module References
	ZOMBIES_API UClass* Z_Construct_UClass_ACustomZombiesGameMode_NoRegister();
	ZOMBIES_API UClass* Z_Construct_UClass_ACustomZombiesGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Zombies();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ZOMBIES_API UClass* Z_Construct_UClass_AZombieBase_NoRegister();
// End Cross Module References
	void ACustomZombiesGameMode::StaticRegisterNativesACustomZombiesGameMode()
	{
	}
	UClass* Z_Construct_UClass_ACustomZombiesGameMode_NoRegister()
	{
		return ACustomZombiesGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ACustomZombiesGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_zombieClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_zombieClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACustomZombiesGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Zombies,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACustomZombiesGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Zombies/Game/CustomZombiesGameMode.h" },
		{ "ModuleRelativePath", "Public/Zombies/Game/CustomZombiesGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACustomZombiesGameMode_Statics::NewProp_zombieClass_MetaData[] = {
		{ "Category", "Zombie Settings" },
		{ "ModuleRelativePath", "Public/Zombies/Game/CustomZombiesGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ACustomZombiesGameMode_Statics::NewProp_zombieClass = { "zombieClass", nullptr, (EPropertyFlags)0x0024080000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACustomZombiesGameMode, zombieClass), Z_Construct_UClass_AZombieBase_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ACustomZombiesGameMode_Statics::NewProp_zombieClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACustomZombiesGameMode_Statics::NewProp_zombieClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACustomZombiesGameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACustomZombiesGameMode_Statics::NewProp_zombieClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACustomZombiesGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACustomZombiesGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACustomZombiesGameMode_Statics::ClassParams = {
		&ACustomZombiesGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ACustomZombiesGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ACustomZombiesGameMode_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ACustomZombiesGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACustomZombiesGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACustomZombiesGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACustomZombiesGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACustomZombiesGameMode, 3023861811);
	template<> ZOMBIES_API UClass* StaticClass<ACustomZombiesGameMode>()
	{
		return ACustomZombiesGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACustomZombiesGameMode(Z_Construct_UClass_ACustomZombiesGameMode, &ACustomZombiesGameMode::StaticClass, TEXT("/Script/Zombies"), TEXT("ACustomZombiesGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACustomZombiesGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
