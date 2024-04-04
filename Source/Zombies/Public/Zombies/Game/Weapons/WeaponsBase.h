// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponsBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAmmoChanged, int32, currentAmmo);

class AZombiesCharacter;

UENUM()
enum class EWeaponState
{
	Idle UMETA(DisplayName = "Idle"),
	Firing UMETA(DisplayName = "Firing"),
	Reloading UMETA(DisplayName = "Reloading"),
	Empty UMETA(DisplayName = "Empty")
};

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	M1911 UMETA(DisplayName = "M1911"),
	AK47 UMETA(DisplayName = "AK47"),
	AR4 UMETA(DisplayName = "AR4"),
	MAC10 UMETA(DisplayName = "MAC10")
};

USTRUCT()
struct FWeaponData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Weapon Data")
	bool bInfiniteAmmo;

	UPROPERTY(EditAnywhere, Category = "Weapon Data")
	float damage;

	UPROPERTY(EditAnywhere, Category = "Weapon Data")
	int32 magazineSize;

	UPROPERTY(EditAnywhere, Category = "Weapon Data")
	int32 magazineAmount;

	UPROPERTY(EditAnywhere, Category = "Weapon Data")
	float fireRate;

	UPROPERTY(EditAnywhere, Category = "Weapon Data")
	float reloadSpeed;

	//Default
	FWeaponData()
	{
		bInfiniteAmmo = false;
		damage = 50.0f;
		magazineSize = 30;
		magazineAmount = 7;
		fireRate = 0.2f;
		reloadSpeed = 0.5f;
	}
};

UCLASS()
class ZOMBIES_API AWeaponsBase : public AActor
{
	GENERATED_BODY()
	
public:
	AWeaponsBase();

public:	
	// Sets default values for this actor's properties

	virtual void Fire();
	virtual void EndFire();
	virtual void Reload();

	bool GetInfiniteAmmo() const;
	float GetDamage() const;
	int32 GetMagaezineSize() const;
	int32 GetMagazineAmount() const;
	float GetFireRate() const;

	void SetCurrentAmmo(int32 newCurrentAmmo);
	void SetCurrentReserveAmmo(int32 newCurrentReserveAmmo);

	void SetNewOwner(AZombiesCharacter* newOwner);
	class AZombiesCharacter* GetWeaponOwner() const;

	UFUNCTION(BlueprintCallable)
		TEnumAsByte<EWeaponType> GetWeaponType();

	UFUNCTION(BlueprintCallable)
		int32 GetCurrentAmmo();
	
	UFUNCTION(BlueprintCallable)
		int32 GetReserveAmmo();

	UFUNCTION(BlueprintCallable)
		void AttachWeaponToMesh();

	UFUNCTION(BlueprintCallable)
		void DetachWeaponFromMesh();

	USkeletalMeshComponent* GetMesh();

	void OnEquip();
	void OnUnequip();

	void AddAmmo(int32 ammo, bool includeCurrentMagazine);

protected:
	virtual void StartFiringCooldown(float time);
	virtual void EndFiringCooldown();

	void SetWeaponState(EWeaponState newState);

	void SetWantsToFire(bool newWantsToFire);
	
	bool CanFire();
	bool CanReload();

	void HandleReload();

	void DetermineWeaponState();

public:
	UPROPERTY(EditAnywhere, Category = Config)
		float spreadMultiplier;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* weaponSkeletalMesh;
	
	UPROPERTY(EditAnywhere, Category = Config)
		FWeaponData weaponData;

	EWeaponState weaponState;

	UPROPERTY(EditAnywhere, Category = Config)
		TEnumAsByte<EWeaponType> weaponType;

	UPROPERTY(Transient)
		class AZombiesCharacter* weaponOwner;

	UPROPERTY(EditAnywhere, Category = Ammo, meta = (ToolTip = "The amount of ammo in the magazine. Also the amount of ammo the gun will start with when spawned"))
		int32 currentAmmo; //Ammo in magazine & Starting Ammo

	UPROPERTY(EditAnywhere, Category = Ammo, meta = (ToolTip = "The total amount of ammo left. This is also used for the starting amount of total bullets when spawned"))
		int32 currentReserveAmmo; //Ammo in Magazine + reserve magaizines & Starting Ammo

	UPROPERTY(BlueprintAssignable)
		FAmmoChanged OnAmmoChanged;

	FTimerHandle cooldownTimerHandle;
	FTimerHandle reloadTimerHandle;

	bool bWantsToReload;
	bool bWantsToFire;
};
