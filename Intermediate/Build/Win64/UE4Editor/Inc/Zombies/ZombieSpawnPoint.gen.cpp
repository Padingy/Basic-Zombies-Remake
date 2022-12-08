// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Zombies/Public/Zombies/Game/ZombieSpawnPoint.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZombieSpawnPoint() {}
// Cross Module References
	ZOMBIES_API UClass* Z_Construct_UClass_AZombieSpawnPoint_NoRegister();
	ZOMBIES_API UClass* Z_Construct_UClass_AZombieSpawnPoint();
	ENGINE_API UClass* Z_Construct_UClass_ATargetPoint();
	UPackage* Z_Construct_UPackage__Script_Zombies();
// End Cross Module References
	void AZombieSpawnPoint::StaticRegisterNativesAZombieSpawnPoint()
	{
	}
	UClass* Z_Construct_UClass_AZombieSpawnPoint_NoRegister()
	{
		return AZombieSpawnPoint::StaticClass();
	}
	struct Z_Construct_UClass_AZombieSpawnPoint_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AZombieSpawnPoint_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ATargetPoint,
		(UObject* (*)())Z_Construct_UPackage__Script_Zombies,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZombieSpawnPoint_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Zombies/Game/ZombieSpawnPoint.h" },
		{ "ModuleRelativePath", "Public/Zombies/Game/ZombieSpawnPoint.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AZombieSpawnPoint_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZombieSpawnPoint>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AZombieSpawnPoint_Statics::ClassParams = {
		&AZombieSpawnPoint::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AZombieSpawnPoint_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AZombieSpawnPoint_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AZombieSpawnPoint()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AZombieSpawnPoint_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AZombieSpawnPoint, 3033753802);
	template<> ZOMBIES_API UClass* StaticClass<AZombieSpawnPoint>()
	{
		return AZombieSpawnPoint::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AZombieSpawnPoint(Z_Construct_UClass_AZombieSpawnPoint, &AZombieSpawnPoint::StaticClass, TEXT("/Script/Zombies"), TEXT("AZombieSpawnPoint"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AZombieSpawnPoint);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
