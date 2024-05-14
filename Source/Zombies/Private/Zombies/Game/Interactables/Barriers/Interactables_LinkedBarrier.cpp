// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Interactables/Barriers/Interactables_LinkedBarrier.h"

AInteractables_LinkedBarrier::AInteractables_LinkedBarrier()
{
	
}

void AInteractables_LinkedBarrier::OnInteract(AZombiesCharacter* interactingPlayer)
{
	Super::OnInteract(interactingPlayer);

	if (linkedBarriers.Num() > 0)
	{
		for (AInteractablesBarrierBase* linkedBarrier : linkedBarriers)
		{
			linkedBarrier->OnInteract(interactingPlayer);
		}
	}
}

void AInteractables_LinkedBarrier::BeginPlay()
{
	Super::BeginPlay();
}
