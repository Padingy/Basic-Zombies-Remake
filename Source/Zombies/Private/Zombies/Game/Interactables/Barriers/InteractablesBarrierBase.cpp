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
}

void AInteractablesBarrierBase::BeginPlay()
{
	Super::BeginPlay();
}

void AInteractablesBarrierBase::ChangeOpacityValue(float changeValue)
{
	if (UMaterialInstanceDynamic* dynamicMaterialInstance = Cast<UMaterialInstanceDynamic>(skeletalMeshComp->GetMaterial(0)))
	{
		float currentScalarValue = 0.0f;
		dynamicMaterialInstance->GetScalarParameterValue(FName(FString("FadeOut")), currentScalarValue);

		dynamicMaterialInstance->SetScalarParameterValue("FadeOut", FMath::Clamp(currentScalarValue + changeValue, 0.0f, 1.0f));

		skeletalMeshComp->SetMaterial(0, dynamicMaterialInstance);
	}
}
