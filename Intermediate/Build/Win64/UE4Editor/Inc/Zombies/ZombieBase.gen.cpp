// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Zombies/Public/Zombie/ZombieBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZombieBase() {}
// Cross Module References
	ZOMBIES_API UClass* Z_Construct_UClass_AZombieBase_NoRegister();
	ZOMBIES_API UClass* Z_Construct_UClass_AZombieBase();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_Zombies();
// End Cross Module References
	void AZombieBase::StaticRegisterNativesAZombieBase()
	{
	}
	UClass* Z_Construct_UClass_AZombieBase_NoRegister()
	{
		return AZombieBase::StaticClass();
	}
	struct Z_Construct_UClass_AZombieBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AZombieBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Zombies,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZombieBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Zombie/ZombieBase.h" },
		{ "ModuleRelativePath", "Public/Zombie/ZombieBase.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AZombieBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZombieBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AZombieBase_Statics::ClassParams = {
		&AZombieBase::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AZombieBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AZombieBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AZombieBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AZombieBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AZombieBase, 2514101672);
	template<> ZOMBIES_API UClass* StaticClass<AZombieBase>()
	{
		return AZombieBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AZombieBase(Z_Construct_UClass_AZombieBase, &AZombieBase::StaticClass, TEXT("/Script/Zombies"), TEXT("AZombieBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AZombieBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
