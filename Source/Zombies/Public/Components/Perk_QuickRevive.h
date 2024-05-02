// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PerkBase.h"
#include "Perk_QuickRevive.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIES_API APerk_QuickRevive : public APerkBase
{
	GENERATED_BODY()

public:
	APerk_QuickRevive();

	void UpdatePerk(AActor* owner) override;

	void RemovePerk(AActor* owner) override;
};
