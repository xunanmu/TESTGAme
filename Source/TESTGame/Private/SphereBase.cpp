// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereBase.h"


// Sets default values
ASphereBase::ASphereBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*默认输出*/
	bIsInput = true;
	/*默认初始速度*/
	SphereSpeed = 300;
	SphereSpeedMin = 300;
	SphereSpeedMax = 500;

	/*球形网格组件*/
	SphereMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMeshComponent"));
	SphereMeshComponent->SetSimulatePhysics(true); /*开启物理模拟*/

	/*相机的弹簧臂组件*/
	CameraArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArmComponent"));
	CameraArmComponent->SetupAttachment(SphereMeshComponent);
	/*关闭相机臂翻转*/
	CameraArmComponent->bInheritYaw = 0;
	CameraArmComponent->bInheritPitch = 0;
	CameraArmComponent->bInheritRoll = 0;

	/*相机组件是附加在弹簧臂组件下面*/
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(CameraArmComponent);
}

// Called when the game starts or when spawned
void ASphereBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASphereBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*TODO旧api先学习到时候改成新api SetPhysicsAngularVelocityInDegrees*/
	if (bIsInput && AngularVector != FVector(0.f))
	{
		SphereMeshComponent->SetPhysicsAngularVelocityInDegrees(AngularVector);
	}
}

// Called to bind functionality to input
void ASphereBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	/*绑定按键*/
	PlayerInputComponent->BindAxis("MoveForward",this,&ASphereBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",this,&ASphereBase::MoveRight);
	PlayerInputComponent->BindAction("SpeedUp",IE_Pressed,this,&ASphereBase::SpeedUp);
	PlayerInputComponent->BindAction("SpeedLow",IE_Released,this,&ASphereBase::SpeedLow);
}

void ASphereBase::MoveForward(float value)
{
	if (bIsInput)
	{
		AngularVector.Y = SphereSpeed*value;
	}
}

void ASphereBase::MoveRight(float value)
{
	if (bIsInput)
	{
		AngularVector.X = SphereSpeed*value;
	}
}

void ASphereBase::SpeedUp()
{
		SphereSpeed =  SphereSpeedMax;
}

void ASphereBase::SpeedLow()
{
		SphereSpeed = SphereSpeedMin;
}
