// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Interactables/Barriers/AnimNoitify_Barrier.h"
#include "Zombies/Game/Interactables/Barriers/InteractablesBarrierBase.h"

void UAnimNoitify_Barrier::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	UE_LOG(LogTemp, Warning, TEXT("Barrier Open Animation Notify Fired"));

	AActor* meshOwner = MeshComp->GetOwner();

	AInteractablesBarrierBase* barrier = Cast<AInteractablesBarrierBase>(meshOwner);

	barrier->HandleAnimNotify();
}
