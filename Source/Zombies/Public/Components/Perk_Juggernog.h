// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PerkBase.h"
#include "Perk_Juggernog.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIES_API APerk_Juggernog : public APerkBase
{
	GENERATED_BODY()

public:
	APerk_Juggernog();

	virtual void UpdatePerk(AActor* owner) override;

	virtual void RemovePerk(AActor* owner) override;
	
};
