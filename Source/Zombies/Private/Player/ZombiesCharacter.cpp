// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies/Public/Player/ZombiesCharacter.h"

AZombiesCharacter::AZombiesCharacter()
{

}

void AZombiesCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	FP_Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));

	UE_LOG(LogTemp, Warning, TEXT("ZombiesCharacter"));
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
