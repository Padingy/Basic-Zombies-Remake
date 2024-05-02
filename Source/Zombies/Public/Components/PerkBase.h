// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PerkBase.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIES_API APerkBase : public AActor
{
	GENERATED_BODY()

public:
	APerkBase();
	
	virtual void UpdatePerk(AActor* owner);

	virtual void RemovePerk(AActor* owner);

	FName GetName() const;

protected:
	FName name;
};
