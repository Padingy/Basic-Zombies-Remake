// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Zombies/ZombiesGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZombiesGameMode() {}
// Cross Module References
	ZOMBIES_API UClass* Z_Construct_UClass_AZombiesGameMode_NoRegister();
	ZOMBIES_API UClass* Z_Construct_UClass_AZombiesGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Zombies();
// End Cross Module References
	void AZombiesGameMode::StaticRegisterNativesAZombiesGameMode()
	{
	}
	UClass* Z_Construct_UClass_AZombiesGameMode_NoRegister()
	{
		return AZombiesGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AZombiesGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AZombiesGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Zombies,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZombiesGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "ZombiesGameMode.h" },
		{ "ModuleRelativePath", "ZombiesGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AZombiesGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZombiesGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AZombiesGameMode_Statics::ClassParams = {
		&AZombiesGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AZombiesGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AZombiesGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AZombiesGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AZombiesGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AZombiesGameMode, 4146112921);
	template<> ZOMBIES_API UClass* StaticClass<AZombiesGameMode>()
	{
		return AZombiesGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AZombiesGameMode(Z_Construct_UClass_AZombiesGameMode, &AZombiesGameMode::StaticClass, TEXT("/Script/Zombies"), TEXT("AZombiesGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AZombiesGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
