// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponsBase.generated.h"

class AZombiesCharacter;

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


	//Default
	FWeaponData()
	{
		bInfiniteAmmo = false;
		damage = 50.0f;
		magazineSize = 30;
		magazineAmount = 7;
		fireRate = 0.2f;
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
	virtual void Reload();


	bool GetInfiniteAmmo() const;
	float GetDamage() const;
	int32 GetMagaezineSize() const;
	int32 GetMagazineAmount() const;
	float GetFireRate() const;

	void SetNewOwner(AZombiesCharacter* newOwner);
	class AZombiesCharacter* GetWeaponOwner() const;

	UFUNCTION(BlueprintCallable)
		void AttachWeaponToMesh();

	UFUNCTION(BlueprintCallable)
		void DetachWeaponFromMesh();

	void OnEquip();
	void OnUnequip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* weaponSkeletalMesh;
	
	UPROPERTY(EditAnywhere, Category = Config)
		FWeaponData weaponData;

	UPROPERTY(Transient)
		class AZombiesCharacter* weaponOwner;

	int32 currentAmmo;

	int32 currentMaxAmmo;
};
