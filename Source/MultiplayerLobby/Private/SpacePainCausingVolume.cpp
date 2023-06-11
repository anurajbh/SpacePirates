// Fill out your copyright notice in the Description page of Project Settings.


#include "SpacePainCausingVolume.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))
void ASpacePainCausingVolume::BeginPlay()
{
    Super::BeginPlay();

    DrawDebugBox(GetWorld(), GetActorLocation(), GetActorScale() * 100, FColor::Cyan, true, -1, 0, 5);

}

ASpacePainCausingVolume::ASpacePainCausingVolume()
{
    //Register Events
    OnActorBeginOverlap.AddDynamic(this, &ASpacePainCausingVolume::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &ASpacePainCausingVolume::OnOverlapEnd);
}

void ASpacePainCausingVolume::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this)) 
    {
        // print to screen using above defined method when actor enters trigger volume
        print("Overlap Begin");
        printFString("Other Actor = %s", *OtherActor->GetName());
        
        UGameplayStatics::ApplyDamage(OtherActor, DamageAmount, GetInstigatorController(), this, SpaceDamageType);
    }
}

void ASpacePainCausingVolume::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this)) 
    {
        // print to screen using above defined method when actor leaves trigger volume
        print("Overlap Ended");
        printFString("%s has left the Trigger Volume", *OtherActor->GetName());
    }
}
