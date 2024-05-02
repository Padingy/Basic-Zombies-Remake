// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Interactables/MyInteractablesBase_DamagePlayer.h"
#include "Zombies/Public/Components/AC_PerkComponent.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"

AMyInteractablesBase_DamagePlayer::AMyInteractablesBase_DamagePlayer()
{
	damageAmount = 50.0f;
}

void AMyInteractablesBase_DamagePlayer::OnInteract(AZombiesCharacter* interactingPlayer)
{
	Super::OnInteract(interactingPlayer);
	FPointDamageEvent damageEvent;
	damageEvent.Damage = damageAmount;

	AController* controller = nullptr;
	interactingPlayer->TakeDamage(damageAmount, damageEvent, controller, this);

}
