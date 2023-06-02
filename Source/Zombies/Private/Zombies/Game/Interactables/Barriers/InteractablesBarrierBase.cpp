// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Interactables/Barriers/InteractablesBarrierBase.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"

AInteractablesBarrierBase::AInteractablesBarrierBase()
{

}

void AInteractablesBarrierBase::OnInteract(AZombiesCharacter* interactingPlayer)
{
	if (interactingPlayer->GetPoints() >= cost)
	{
		skeletalMeshComp->PlayAnimation(openAnimation, false);

		interactingPlayer->DecreasePoints(cost);
	}
}

//Used on the AnimationNotify to remove collisions after the animation is finished
void AInteractablesBarrierBase::HandleAnimNotify()
{
	boxCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	this->Destroy();
}

void AInteractablesBarrierBase::BeginPlay()
{
	Super::BeginPlay();
}
