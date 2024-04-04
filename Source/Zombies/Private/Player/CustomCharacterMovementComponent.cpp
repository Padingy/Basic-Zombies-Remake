// Fill out your copyright notice in the Description page of Project Settings.

#include "Zombies/Public/Player/ZombiesCharacter.h"
#include "Zombies/Public/Player/CustomCharacterMovementComponent.h"

UCustomCharacterMovementComponent::UCustomCharacterMovementComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

float UCustomCharacterMovementComponent::GetMaxSpeed() const
{
	float maxSpeed = Super::GetMaxSpeed();

	AZombiesCharacter* playerCharacter = Cast<AZombiesCharacter>(CharacterOwner);
	if (playerCharacter && playerCharacter->GetIsSprinting())
	{
		maxSpeed *= 1.5f;
	}

	return maxSpeed;
}
