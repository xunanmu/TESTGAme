// Copyright Epic Games, Inc. All Rights Reserved.


#include "TESTGameGameModeBase.h"

// ATESTGameGameModeBase::ATESTGameGameModeBase()
// {
// 	PrimaryActorTick.bCanEverTick = true;
// }


void ATESTGameGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	/*玩家1控制器*/
	ASphereBase *Pawn = Cast<ASphereBase>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (Pawn)
	{
		PlayPawn = Pawn;
	}
}

void ATESTGameGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}


void ATESTGameGameModeBase::SetPlayerLocation(FVector Start)
{
	PlayPawn->SetActorLocation(Start);
}
