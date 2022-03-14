// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "SphereBase.generated.h"

UCLASS()
class TESTGAME_API ASphereBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASphereBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SphereMesh")
	UStaticMeshComponent* SphereMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraArm")
	USpringArmComponent* CameraArmComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
	UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool bIsInput;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="SphereSpeed")
	float SphereSpeed;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="SphereSpeedMin")
	float SphereSpeedMin;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="SphereSpeedMax")
	float SphereSpeedMax;
	
	FVector AngularVector;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void MoveForward(float value);

	UFUNCTION(BlueprintCallable)
	void MoveRight(float value);
};
