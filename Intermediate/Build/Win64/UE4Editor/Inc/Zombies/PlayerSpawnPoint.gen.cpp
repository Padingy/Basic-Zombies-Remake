// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Zombies/Public/Zombies/Game/PlayerSpawnPoint.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerSpawnPoint() {}
// Cross Module References
	ZOMBIES_API UClass* Z_Construct_UClass_APlayerSpawnPoint_NoRegister();
	ZOMBIES_API UClass* Z_Construct_UClass_APlayerSpawnPoint();
	ENGINE_API UClass* Z_Construct_UClass_ATargetPoint();
	UPackage* Z_Construct_UPackage__Script_Zombies();
// End Cross Module References
	void APlayerSpawnPoint::StaticRegisterNativesAPlayerSpawnPoint()
	{
	}
	UClass* Z_Construct_UClass_APlayerSpawnPoint_NoRegister()
	{
		return APlayerSpawnPoint::StaticClass();
	}
	struct Z_Construct_UClass_APlayerSpawnPoint_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APlayerSpawnPoint_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ATargetPoint,
		(UObject* (*)())Z_Construct_UPackage__Script_Zombies,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerSpawnPoint_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Zombies/Game/PlayerSpawnPoint.h" },
		{ "ModuleRelativePath", "Public/Zombies/Game/PlayerSpawnPoint.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APlayerSpawnPoint_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlayerSpawnPoint>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APlayerSpawnPoint_Statics::ClassParams = {
		&APlayerSpawnPoint::StaticClass,
		"Engine",
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
		METADATA_PARAMS(Z_Construct_UClass_APlayerSpawnPoint_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APlayerSpawnPoint_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APlayerSpawnPoint()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APlayerSpawnPoint_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APlayerSpawnPoint, 2831690796);
	template<> ZOMBIES_API UClass* StaticClass<APlayerSpawnPoint>()
	{
		return APlayerSpawnPoint::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APlayerSpawnPoint(Z_Construct_UClass_APlayerSpawnPoint, &APlayerSpawnPoint::StaticClass, TEXT("/Script/Zombies"), TEXT("APlayerSpawnPoint"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlayerSpawnPoint);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
