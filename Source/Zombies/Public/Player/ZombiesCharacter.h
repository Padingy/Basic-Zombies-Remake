// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombies/Public/Player/CharacterBase.h"
#include "Zombies/Public/Zombies/Game/Interactables/InteractablesBase.h"
#include "Zombies/Public/Zombies/Game/Weapons/WeaponsBase.h"
#include "ZombiesCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPointsChanged, int32, points);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractMessageChanged, FString, message);

class UCameraComponent;

UCLASS()
class ZOMBIES_API AZombiesCharacter : public ACharacterBase
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	AZombiesCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OnFire();

	void Reload();

	void FindInteractableObjects();

	void SpawnStartingWeapons();

	void AddWeapon(AWeaponsBase* weapon);
	void RemoveWeapon(AWeaponsBase* weapon);

	void EquipWeapon(AWeaponsBase* weapon);

	void SetCurrentWeapon(AWeaponsBase* newWeapon);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void OnNextWeapon();
	void OnPrevWeapon();

public:

	void IncreasePoints(int value);

	void DecreasePoints(int value);

	int32 GetPoints();

	FName GetWeaponAttachPoint() const;

protected:

	FTimerHandle timerHandle;

	AInteractablesBase* interactable;

	UPROPERTY(EditAnywhere, Category = "Weapon Settings")
		TArray<TSubclassOf<class AWeaponsBase>> startingWeaponClasses;

	UPROPERTY(EditDefaultsOnly, Category = Weapon)
		FName weaponAttachPoint;

	AWeaponsBase* currentWeapon;

	int32 weaponIndex;
	TArray<AWeaponsBase*> weaponArray;

	UPROPERTY(EditAnywhere)
		int32 points;

	UPROPERTY(BlueprintAssignable)
		FPointsChanged OnPointsChanged;

	UPROPERTY(BlueprintAssignable)
		FInteractMessageChanged OnInteractMessageChanged;
};
