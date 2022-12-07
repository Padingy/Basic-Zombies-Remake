// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Zombies/ZombiesHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZombiesHUD() {}
// Cross Module References
	ZOMBIES_API UClass* Z_Construct_UClass_AZombiesHUD_NoRegister();
	ZOMBIES_API UClass* Z_Construct_UClass_AZombiesHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_Zombies();
// End Cross Module References
	void AZombiesHUD::StaticRegisterNativesAZombiesHUD()
	{
	}
	UClass* Z_Construct_UClass_AZombiesHUD_NoRegister()
	{
		return AZombiesHUD::StaticClass();
	}
	struct Z_Construct_UClass_AZombiesHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AZombiesHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_Zombies,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZombiesHUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "ZombiesHUD.h" },
		{ "ModuleRelativePath", "ZombiesHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AZombiesHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZombiesHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AZombiesHUD_Statics::ClassParams = {
		&AZombiesHUD::StaticClass,
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
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AZombiesHUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AZombiesHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AZombiesHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AZombiesHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AZombiesHUD, 4169634820);
	template<> ZOMBIES_API UClass* StaticClass<AZombiesHUD>()
	{
		return AZombiesHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AZombiesHUD(Z_Construct_UClass_AZombiesHUD, &AZombiesHUD::StaticClass, TEXT("/Script/Zombies"), TEXT("AZombiesHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AZombiesHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
