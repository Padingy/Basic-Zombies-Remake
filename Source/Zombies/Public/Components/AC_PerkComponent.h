// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombies/Public/Components/PerkBase.h"
#include "Components/ActorComponent.h"
#include "AC_PerkComponent.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZOMBIES_API UAC_PerkComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_PerkComponent();

	virtual void BeginPlay() override;

	void AddPerk(APerkBase* perk);
	void RemovePerk(APerkBase* perk);
	void UpdatePerk(APerkBase* perk);

	APerkBase* QueryPerk(FName perkName);
	
	TArray<APerkBase*> GetCurrentPerks();
	
	void UpdateAllPerks();
	void RemoveAllPerks();

protected:
	TArray<APerkBase*> currentPerks;

		
};
