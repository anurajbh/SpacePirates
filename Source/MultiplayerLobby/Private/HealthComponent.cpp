// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Does not need to tick
	PrimaryComponentTick.bCanEverTick = false;

	//setting default health value to 100
	m_DefaultHeath = 100.f;
	m_Health = m_DefaultHeath;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	//get the actor that owns this component
	OwningActor = GetOwner();
	if (OwningActor)
	{
		//bind our TakeDamage() method as a delegate to the OnTakeAnyDamage event
		OwningActor->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
	}
}

void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	//early return if no damage
	if (Damage <= 0.0f)
	{
		return;
	}
	//subtract health
	m_Health = FMath::Clamp(m_Health - Damage, 0.0f, m_DefaultHeath);
}

