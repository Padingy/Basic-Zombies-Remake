// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Public/Player/ZombiesCharacter.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"
#include "Zombies/Public/Zombie/ZombieBase.h"

AZombiesCharacter::AZombiesCharacter()
{
	points = 500;

}

void AZombiesCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	FP_Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));

	UE_LOG(LogTemp, Warning, TEXT("ZombiesCharacter"));
}

void AZombiesCharacter::OnFire()
{
	UE_LOG(LogTemp, Warning, TEXT("ZombiesCharacter OnFire"));

	FVector start = GetFirstPersonCameraComponent()->GetComponentLocation();
	FVector rot = GetFirstPersonCameraComponent()->GetComponentRotation().Vector();
	FVector end = start + rot * 2000.0f;

	FCollisionQueryParams collisionQuery;
	FCollisionResponseParams collisionResponse;
	collisionQuery.AddIgnoredActor(this);

	TArray<FHitResult>hitResults;
	DrawDebugLine(GetWorld(), start, end, FColor::Red, false, 2.0f, 0.0f, 1.0f);

	if (GetWorld()->LineTraceMultiByChannel(hitResults, start, end, ECollisionChannel::ECC_GameTraceChannel1, collisionQuery, collisionResponse))
	{
		for (FHitResult hit : hitResults)
		{
			if (AZombieBase* zombie = Cast<AZombieBase>(hit.GetActor()))
			{
				FString hitBone = hit.BoneName.ToString();

				zombie->Hit(this, hitBone);

				UE_LOG(LogTemp, Warning, TEXT("Shot Hit on Channel: %s"), *zombie->GetName());

				UE_LOG(LogTemp, Warning, TEXT("Bone Hit: %s"), *hitBone);
			}
		}
	}

}

void AZombiesCharacter::IncreasePoints(int value)
{
	points += value;
	OnPointsChanged.Broadcast(points);
}

void AZombiesCharacter::DecreasePoints(int value)
{
	points -= value;
	OnPointsChanged.Broadcast(points);
}

int32 AZombiesCharacter::GetPoints()
{
	return points;
}

// Called to bind functionality to input
void AZombiesCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AZombiesCharacter::OnFire);

	PlayerInputComponent->BindAxis("MoveForward", this, &AZombiesCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AZombiesCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AZombiesCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AZombiesCharacter::LookUpAtRate);
}
