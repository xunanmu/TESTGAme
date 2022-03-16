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
		/*获取玩家当前初始位置*/
		CurrentStart = PlayPawn->GetActorLocation();
	}
}

void ATESTGameGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ATESTGameGameModeBase::SetPlayerLocation()
{
	PlayPawn->SetActorLocation(CurrentStart);
	/*把速度和角速度设置为0，使小球复活不动*/
	PlayPawn->SphereMeshComponent->SetPhysicsLinearVelocity(FVector(0));
	PlayPawn->SphereMeshComponent->SetPhysicsAngularVelocityInDegrees(FVector(0));
	
}
void ATESTGameGameModeBase::SetPlayerLocation(FVector Start)
{
	PlayPawn->SetActorLocation(Start);
	/*把速度和角速度设置为0，使小球复活不动*/
	PlayPawn->SphereMeshComponent->SetPhysicsLinearVelocity(FVector(0));
	PlayPawn->SphereMeshComponent->SetPhysicsAngularVelocityInDegrees(FVector(0));
}
