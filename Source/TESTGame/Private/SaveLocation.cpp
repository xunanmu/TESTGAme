// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveLocation.h"

#include "TESTGame/GemeMode/TESTGameGameModeBase.h"

ASaveLocation::ASaveLocation()
{
	SaveMapComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SaveMap"));
	HitBoxComponent->SetupAttachment(SaveMapComponent);
}

void ASaveLocation::OnHitSphere(AActor *Sphere)
{
	ATESTGameGameModeBase *GameModeBase= Cast<ATESTGameGameModeBase>(GetWorld()->GetAuthGameMode());
	GameModeBase->SetCurrentStart(HitBoxComponent->GetComponentLocation());
}
