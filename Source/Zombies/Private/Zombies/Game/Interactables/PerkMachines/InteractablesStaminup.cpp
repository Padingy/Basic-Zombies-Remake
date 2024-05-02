// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Interactables/PerkMachines/InteractablesStaminup.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"
#include "Zombies/Public/Player/CustomCharacterMovementComponent.h"

AInteractablesStaminup::AInteractablesStaminup()
{
	staminaMultiplier = 2.0f;
}

void AInteractablesStaminup::OnInteract(AZombiesCharacter* interactingPlayer)
{
	if (interactingPlayer)
	{
		interactingPlayer->SetMoveSpeedMultiplier(1.07f);
		interactingPlayer->SetMaxStamina(interactingPlayer->GetMaxStamina() * 2.0f);
		interactingPlayer->GetCharacterMovement()->MaxWalkSpeed *= 2.0f;
	}
}

void AInteractablesStaminup::BeginPlay()
{

}