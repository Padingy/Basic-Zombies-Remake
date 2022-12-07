// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef ZOMBIES_ZombiesProjectile_generated_h
#error "ZombiesProjectile.generated.h already included, missing '#pragma once' in ZombiesProjectile.h"
#endif
#define ZOMBIES_ZombiesProjectile_generated_h

#define Zombies_Source_Zombies_ZombiesProjectile_h_15_SPARSE_DATA
#define Zombies_Source_Zombies_ZombiesProjectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define Zombies_Source_Zombies_ZombiesProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define Zombies_Source_Zombies_ZombiesProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZombiesProjectile(); \
	friend struct Z_Construct_UClass_AZombiesProjectile_Statics; \
public: \
	DECLARE_CLASS(AZombiesProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Zombies"), NO_API) \
	DECLARE_SERIALIZER(AZombiesProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define Zombies_Source_Zombies_ZombiesProjectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAZombiesProjectile(); \
	friend struct Z_Construct_UClass_AZombiesProjectile_Statics; \
public: \
	DECLARE_CLASS(AZombiesProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Zombies"), NO_API) \
	DECLARE_SERIALIZER(AZombiesProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define Zombies_Source_Zombies_ZombiesProjectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AZombiesProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AZombiesProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZombiesProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZombiesProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZombiesProjectile(AZombiesProjectile&&); \
	NO_API AZombiesProjectile(const AZombiesProjectile&); \
public:


#define Zombies_Source_Zombies_ZombiesProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZombiesProjectile(AZombiesProjectile&&); \
	NO_API AZombiesProjectile(const AZombiesProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZombiesProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZombiesProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AZombiesProjectile)


#define Zombies_Source_Zombies_ZombiesProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AZombiesProjectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AZombiesProjectile, ProjectileMovement); }


#define Zombies_Source_Zombies_ZombiesProjectile_h_12_PROLOG
#define Zombies_Source_Zombies_ZombiesProjectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Zombies_Source_Zombies_ZombiesProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	Zombies_Source_Zombies_ZombiesProjectile_h_15_SPARSE_DATA \
	Zombies_Source_Zombies_ZombiesProjectile_h_15_RPC_WRAPPERS \
	Zombies_Source_Zombies_ZombiesProjectile_h_15_INCLASS \
	Zombies_Source_Zombies_ZombiesProjectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Zombies_Source_Zombies_ZombiesProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Zombies_Source_Zombies_ZombiesProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	Zombies_Source_Zombies_ZombiesProjectile_h_15_SPARSE_DATA \
	Zombies_Source_Zombies_ZombiesProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Zombies_Source_Zombies_ZombiesProjectile_h_15_INCLASS_NO_PURE_DECLS \
	Zombies_Source_Zombies_ZombiesProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ZOMBIES_API UClass* StaticClass<class AZombiesProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Zombies_Source_Zombies_ZombiesProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
