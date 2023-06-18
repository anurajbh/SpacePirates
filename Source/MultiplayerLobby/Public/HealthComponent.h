// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MULTIPLAYERLOBBY_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	//default health value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Stats")
		float m_DefaultHeath;

	//current health
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Stats")
		float m_Health;

	//damage function
	UFUNCTION()
		void TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	class AActor* OwningActor = nullptr;
};
