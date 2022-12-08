// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZombiesCharacter() {}
// Cross Module References
	ZOMBIES_API UClass* Z_Construct_UClass_AZombiesCharacter_NoRegister();
	ZOMBIES_API UClass* Z_Construct_UClass_AZombiesCharacter();
	ZOMBIES_API UClass* Z_Construct_UClass_ACharacterBase();
	UPackage* Z_Construct_UPackage__Script_Zombies();
// End Cross Module References
	void AZombiesCharacter::StaticRegisterNativesAZombiesCharacter()
	{
	}
	UClass* Z_Construct_UClass_AZombiesCharacter_NoRegister()
	{
		return AZombiesCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AZombiesCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AZombiesCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacterBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Zombies,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZombiesCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Player/ZombiesCharacter.h" },
		{ "ModuleRelativePath", "Public/Player/ZombiesCharacter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AZombiesCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZombiesCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AZombiesCharacter_Statics::ClassParams = {
		&AZombiesCharacter::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AZombiesCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AZombiesCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AZombiesCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AZombiesCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AZombiesCharacter, 3213806687);
	template<> ZOMBIES_API UClass* StaticClass<AZombiesCharacter>()
	{
		return AZombiesCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AZombiesCharacter(Z_Construct_UClass_AZombiesCharacter, &AZombiesCharacter::StaticClass, TEXT("/Script/Zombies"), TEXT("AZombiesCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AZombiesCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
