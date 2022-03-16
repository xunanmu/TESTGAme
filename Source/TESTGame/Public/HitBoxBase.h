// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "HitBoxBase.generated.h"

UCLASS()
class TESTGAME_API AHitBoxBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHitBoxBase();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UBoxComponent *HitBoxComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*复活时的操作*/
	virtual void OnHitSphere(AActor *sphere);

	UFUNCTION(BlueprintCallable)
	void BeginHit(UPrimitiveComponent *OverlappUPrimitiveComponent,AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
