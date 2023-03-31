// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"
#include "ZombieBase.generated.h"

UCLASS()
class ZOMBIES_API AZombieBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZombieBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void DestroyActor();

	

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		float maxHealth;

	UPROPERTY(EditAnywhere)
		float health;

public:	

	void Hit(class AZombiesCharacter* attacker, FString hitBone);

	void HandleBoneHits(class AZombiesCharacter* attacker, FString hitBone);
	bool DecreaseHealth(float value);
	float GetHealth();

};
