// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SphereBase.h"
#include "GameFramework/GameModeBase.h"
#include "TESTGameGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TESTGAME_API ATESTGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PlayPawn")
	ASphereBase *PlayPawn;
public:
	virtual void BeginPlay() override;

	virtual  void Tick(float DeltaSeconds) override;
public:
	void  SetPlayerLocation(FVector Start);
};
