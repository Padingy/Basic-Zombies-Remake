// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PerkBase.h"
#include "Perk_DoubleTap.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIES_API APerk_DoubleTap : public APerkBase
{
	GENERATED_BODY()

public:
	APerk_DoubleTap();

	void UpdatePerk(AActor* owner) override;

	void RemovePerk(AActor* owner) override;
};
