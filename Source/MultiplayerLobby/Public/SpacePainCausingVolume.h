// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/DamageType.h"
#include "SpacePainCausingVolume.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERLOBBY_API ASpacePainCausingVolume : public ATriggerBox
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// constructor sets default values for this actor's properties
	ASpacePainCausingVolume();

	// overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// overlap end function
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	UPROPERTY(EditAnywhere, Category = "Stats", BlueprintReadWrite)
		float DamageAmount;
	UPROPERTY(EditAnywhere, Category = "Stats", BlueprintReadWrite)
		TSubclassOf<UDamageType> SpaceDamageType;
};
