// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StarshipCharacter.generated.h"

UCLASS()
class MULTIPLAYERLOBBY_API AStarshipCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AStarshipCharacter();

	//Camera component
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera")
		class UCameraComponent* PlayerCam = nullptr;

	//Spring arm component
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera")
		class USpringArmComponent* PlayerSpringArm = nullptr;

	//Floating Pawn Component
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		class UFloatingPawnMovement* PlayerFloatingPawnMovement = nullptr;

	//Floating Pawn Component
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		float PlayerSpeed = 100.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void MoveUp(float Value);

};
