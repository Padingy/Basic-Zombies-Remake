// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombies/Game/Interactables/Barriers/InteractablesBarrierBase.h"
#include "Interactables_LinkedBarrier.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIES_API AInteractables_LinkedBarrier : public AInteractablesBarrierBase
{
	GENERATED_BODY()

public:
	AInteractables_LinkedBarrier();
	
	virtual void OnInteract(AZombiesCharacter* interactingPlayer) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TArray<AInteractablesBarrierBase*> linkedBarriers;
};
