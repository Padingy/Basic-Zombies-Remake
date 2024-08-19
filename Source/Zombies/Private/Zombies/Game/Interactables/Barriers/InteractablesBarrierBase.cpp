// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Interactables/Barriers/InteractablesBarrierBase.h"
#include "Zombies/Public/Player/ZombiesCharacter.h"
#include "Zombies/Game/ZombiesCustomGameMode.h"

AInteractablesBarrierBase::AInteractablesBarrierBase()
{
	spawnZone1 = 0;
	spawnZone2 = 1;

	purchased = false;
}

void AInteractablesBarrierBase::OnInteract(AZombiesCharacter* interactingPlayer)
{
	if (interactingPlayer->GetPoints() >= cost && purchased == false)
	{
		purchased = true;
		AZombiesCustomGameMode* gameMode = Cast<AZombiesCustomGameMode>(GetWorld()->GetAuthGameMode());
		
		skeletalMeshComp->PlayAnimation(openAnimation, false);

		interactingPlayer->DecreasePoints(cost);

		gameMode->UpdateSpawnPoints(this);
	}
}

void AInteractablesBarrierBase::OnInteractFree(AZombiesCharacter* interactingPlayer)
{
	AZombiesCustomGameMode* gameMode = Cast<AZombiesCustomGameMode>(GetWorld()->GetAuthGameMode());
		
	skeletalMeshComp->PlayAnimation(openAnimation, false);

	gameMode->UpdateSpawnPoints(this);
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

int32 AInteractablesBarrierBase::GetSpawnZone1()
{
	return spawnZone1;
}

int32 AInteractablesBarrierBase::GetSpawnZone2()
{
	return spawnZone2;
}
