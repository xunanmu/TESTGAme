// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HitBoxBase.h"
#include "DieBoxBase.generated.h"

/**
 * 
 */
UCLASS()
class TESTGAME_API ADieBoxBase : public AHitBoxBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector sphereVector;

	/*累计死亡次数*/
	static unsigned count;
public:
	virtual void OnHitSphere(AActor* sphere) override;
	
};
