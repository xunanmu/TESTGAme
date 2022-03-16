// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HitBoxBase.h"
#include "SaveLocation.generated.h"

/**
 * 
 */
UCLASS()
class TESTGAME_API ASaveLocation : public AHitBoxBase
{
	GENERATED_BODY()
public:

	ASaveLocation();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent *SaveMapComponent;
public:
	virtual void OnHitSphere(AActor* sphere) override;
};
 