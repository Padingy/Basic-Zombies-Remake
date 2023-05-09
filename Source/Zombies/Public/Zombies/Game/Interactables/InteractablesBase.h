// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractablesBase.generated.h"

UCLASS()
class ZOMBIES_API AInteractablesBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractablesBase();

	virtual void OnInteract(class AZombiesCharacter* interactingPlayer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	FString UIMessage;

	FString name;

	int32 cost;

};
