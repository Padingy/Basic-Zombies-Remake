// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombies/Public/Player/CharacterBase.h"
#include "ZombiesCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPointsChanged, int32, points);

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

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	void IncreasePoints(int value);

	void DecreasePoints(int value);

	int32 GetPoints();

protected:

	UPROPERTY(EditDefaultsOnly)
		int32 points;

	UPROPERTY(BlueprintAssignable)
		FPointsChanged OnPointsChanged;
};
