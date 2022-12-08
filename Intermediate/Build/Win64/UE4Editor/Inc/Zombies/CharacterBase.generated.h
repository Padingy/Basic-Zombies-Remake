// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ZOMBIES_CharacterBase_generated_h
#error "CharacterBase.generated.h already included, missing '#pragma once' in CharacterBase.h"
#endif
#define ZOMBIES_CharacterBase_generated_h

#define Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_SPARSE_DATA
#define Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_RPC_WRAPPERS
#define Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACharacterBase(); \
	friend struct Z_Construct_UClass_ACharacterBase_Statics; \
public: \
	DECLARE_CLASS(ACharacterBase, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Zombies"), NO_API) \
	DECLARE_SERIALIZER(ACharacterBase)


#define Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_INCLASS \
private: \
	static void StaticRegisterNativesACharacterBase(); \
	friend struct Z_Construct_UClass_ACharacterBase_Statics; \
public: \
	DECLARE_CLASS(ACharacterBase, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Zombies"), NO_API) \
	DECLARE_SERIALIZER(ACharacterBase)


#define Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACharacterBase(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACharacterBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACharacterBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACharacterBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACharacterBase(ACharacterBase&&); \
	NO_API ACharacterBase(const ACharacterBase&); \
public:


#define Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACharacterBase(ACharacterBase&&); \
	NO_API ACharacterBase(const ACharacterBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACharacterBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACharacterBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACharacterBase)


#define Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh1P() { return STRUCT_OFFSET(ACharacterBase, Mesh1P); } \
	FORCEINLINE static uint32 __PPO__FP_Gun() { return STRUCT_OFFSET(ACharacterBase, FP_Gun); } \
	FORCEINLINE static uint32 __PPO__FP_MuzzleLocation() { return STRUCT_OFFSET(ACharacterBase, FP_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__FirstPersonCameraComponent() { return STRUCT_OFFSET(ACharacterBase, FirstPersonCameraComponent); }


#define Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_11_PROLOG
#define Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_PRIVATE_PROPERTY_OFFSET \
	Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_SPARSE_DATA \
	Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_RPC_WRAPPERS \
	Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_INCLASS \
	Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_PRIVATE_PROPERTY_OFFSET \
	Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_SPARSE_DATA \
	Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_INCLASS_NO_PURE_DECLS \
	Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ZOMBIES_API UClass* StaticClass<class ACharacterBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Basic_Zombies_Remake_Source_Zombies_Public_Player_CharacterBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
