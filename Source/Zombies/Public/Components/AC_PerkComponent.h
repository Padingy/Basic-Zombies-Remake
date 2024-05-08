// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombies/Public/Components/PerkBase.h"
#include "Components/ActorComponent.h"
#include "AC_PerkComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPerksChanged);

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ZOMBIES_API UAC_PerkComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_PerkComponent();

	virtual void BeginPlay() override;

	bool AddPerk(APerkBase* perk);
	void RemovePerk(APerkBase* perk);
	void UpdatePerk(APerkBase* perk);

	APerkBase* QueryPerk(FName perkName);

	UFUNCTION(BlueprintCallable)
	TArray<APerkBase*> GetCurrentPerks();
	
	void UpdateAllPerks();
	void RemoveAllPerks();

protected:

	UPROPERTY()
	TArray<APerkBase*> currentPerks;

	UPROPERTY(BlueprintAssignable)
	FPerksChanged OnPerksChanged;;
};
