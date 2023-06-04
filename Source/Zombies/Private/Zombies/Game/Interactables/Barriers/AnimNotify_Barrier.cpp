// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Game/Interactables/Barriers/AnimNotify_Barrier.h"
#include "Zombies/Game/Interactables/Barriers/InteractablesBarrierBase.h"

void UAnimNotify_Barrier::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);

	
}

void UAnimNotify_Barrier::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	if (MeshComp && MeshComp->GetOwner()) 
	{
		if (AInteractablesBarrierBase* barrier = Cast<AInteractablesBarrierBase>(MeshComp->GetOwner()))
		{
			/*float opacityValue = 0.0f;
			for (const FAnimNotifyEvent& notifyEvent : Animation->Notifies)
			{
				opacityValue = (notifyEvent.GetDuration() * FrameDeltaTime) * 10;

				UE_LOG(LogTemp, Warning, TEXT("AnimNotifyDuration: %f"), opacityValue);
			}*/
			barrier->ChangeOpacityValue(-0.02f);
		}
	}
}

void UAnimNotify_Barrier::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (MeshComp && MeshComp->GetOwner())
	{
		if (AInteractablesBarrierBase* barrier = Cast<AInteractablesBarrierBase>(MeshComp->GetOwner()))
		{
			barrier->HandleAnimNotify();
			barrier->MarkPendingKill();
		}
	}
}