// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CustomCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIES_API UCustomCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_UCLASS_BODY()
	

public:

	virtual float GetMaxSpeed() const override;
};
