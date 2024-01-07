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

USTRUCT()
struct FPlayerData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Player Data")
		float maxHealth;

	UPROPERTY(EditAnywhere, Category = "Player Data")
		float health;

	UPROPERTY(EditAnywhere, Category = "Player Data")
		float reloadSpeedMultiplier;

	FPlayerData()
	{
		maxHealth = 100.0f;
		health = 100.0f;
		reloadSpeedMultiplier = 1.0f;
	}
};

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

	//Firing Functions
	void OnFire();
	void OnEndFire();

	//Reload
	void Reload();

	//Interacting
	void FindInteractableObjects();

	void OnInteract();

	//Weapons Starting / Switching
	void SpawnStartingWeapons();

	void OnNextWeapon();
	void OnPrevWeapon();

	void IncreaseHealth(float increaseValue);
	void DecreaseHealth(float decreaseValue);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	//Points
	void IncreasePoints(int increaseValue);

	void DecreasePoints(int decreaseValue);

	void Heal();

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

	UFUNCTION(Exec)
		void damagePlayer(float damage);

	void Die();

	UFUNCTION(BlueprintNativeEvent)
		void DeathScreen();

	void DeathScreen_Implementation();

	void SetMaxHealth(float newMaxHealth);
	void SetReloadSpeedModifier(float newReloadSpeed);

	float GetMaxHealth();
	float GetHealth();
	float GetReloadSpeedMultiplier();

	int32 GetPoints();


	//Weapons
	FName GetWeaponAttachPoint() const;

	TArray<AWeaponsBase*> GetWeaponArray();

	UFUNCTION(BlueprintCallable)
		AWeaponsBase* GetCurrentWeapon();

	int32 GetMaxWeapons();

	//Weapon Equiping / Switching
	void AddWeapon(AWeaponsBase* weapon);
	void RemoveWeapon(AWeaponsBase* weapon);

	void EquipWeapon(AWeaponsBase* weapon);

	void SetCurrentWeapon(AWeaponsBase* newWeapon);

protected:

	FTimerHandle timerHandle;

	AInteractablesBase* interactable;

	UPROPERTY(EditAnywhere, Category = "Interact Settings")
		float interactDistance;

	UPROPERTY(EditAnywhere, Category = Config)
		FPlayerData playerData;

	UPROPERTY(EditAnywhere, Category = "Weapon Settings")
		TArray<TSubclassOf<class AWeaponsBase>> startingWeaponClasses;

	UPROPERTY(EditAnywhere, Category = "Weapon Settings")
		int32 maxWeapons;

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
