// Fill out your copyright notice in the Description page of Project Settings.


#include "StarshipCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
// Sets default values
AStarshipCharacter::AStarshipCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create Spring Arm Component and attach it to Root component
	PlayerSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Player Spring Arm"));
	PlayerSpringArm->SetupAttachment(RootComponent);

	//Create Camera Component and attach it to Spring Arm
	PlayerCam = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	if (nullptr != PlayerSpringArm)
	{
		PlayerCam->SetupAttachment(PlayerSpringArm);
	}

	//Create Floating Pawn Movement Component
	//PlayerFloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Player Floating Pawn Movement"));
}

// Called when the game starts or when spawned
void AStarshipCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStarshipCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AStarshipCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UE_LOG(LogTemp, Warning, TEXT("Set up input"));
	//set up gameplay key bindings
	check(PlayerInputComponent);

	//Movement
	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &AStarshipCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &AStarshipCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveUp", this, &AStarshipCharacter::MoveUp);

	//Rotation
	PlayerInputComponent->BindAxis("Turn Right / Left Mouse", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Look Up / Down Mouse", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Roll", this, &APawn::AddControllerRollInput);
}

void AStarshipCharacter::MoveForward(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Moving forward"));
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value * PlayerSpeed);
	}
}

void AStarshipCharacter::MoveRight(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Moving right"));
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value * PlayerSpeed);

	}
}

void AStarshipCharacter::MoveUp(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Moving up"));
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorUpVector(), Value * PlayerSpeed);

	}
}

