// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ZOMBIES_ZombieBase_generated_h
#error "ZombieBase.generated.h already included, missing '#pragma once' in ZombieBase.h"
#endif
#define ZOMBIES_ZombieBase_generated_h

#define Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_SPARSE_DATA
#define Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_RPC_WRAPPERS
#define Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZombieBase(); \
	friend struct Z_Construct_UClass_AZombieBase_Statics; \
public: \
	DECLARE_CLASS(AZombieBase, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Zombies"), NO_API) \
	DECLARE_SERIALIZER(AZombieBase)


#define Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAZombieBase(); \
	friend struct Z_Construct_UClass_AZombieBase_Statics; \
public: \
	DECLARE_CLASS(AZombieBase, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Zombies"), NO_API) \
	DECLARE_SERIALIZER(AZombieBase)


#define Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AZombieBase(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AZombieBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZombieBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZombieBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZombieBase(AZombieBase&&); \
	NO_API AZombieBase(const AZombieBase&); \
public:


#define Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZombieBase(AZombieBase&&); \
	NO_API AZombieBase(const AZombieBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZombieBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZombieBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AZombieBase)


#define Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_PRIVATE_PROPERTY_OFFSET
#define Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_9_PROLOG
#define Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_PRIVATE_PROPERTY_OFFSET \
	Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_SPARSE_DATA \
	Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_RPC_WRAPPERS \
	Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_INCLASS \
	Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_PRIVATE_PROPERTY_OFFSET \
	Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_SPARSE_DATA \
	Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_INCLASS_NO_PURE_DECLS \
	Zombies_Source_Zombies_Public_Zombie_ZombieBase_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ZOMBIES_API UClass* StaticClass<class AZombieBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Zombies_Source_Zombies_Public_Zombie_ZombieBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
