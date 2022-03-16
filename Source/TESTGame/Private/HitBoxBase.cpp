// Fill out your copyright notice in the Description page of Project Settings.


#include "HitBoxBase.h"

#include "SphereBase.h"
#include "Components/BoxComponent.h"


// Sets default values
AHitBoxBase::AHitBoxBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	/*碰撞组件*/
	HitBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	/*触发器，两个物体相碰就调用*/
	HitBoxComponent->OnComponentBeginOverlap.AddDynamic(this,&AHitBoxBase::BeginHit);
}


// Called when the game starts or when spawned
void AHitBoxBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHitBoxBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHitBoxBase::BeginHit(UPrimitiveComponent *OverlappUPrimitiveComponent,AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	/*检查碰撞物体，若转换成功则调用碰撞后发生的动作*/
	if(Cast<ASphereBase>(OtherActor))
	{
		OnHitSphere(Cast<ASphereBase>(OtherActor));
	}
}

void AHitBoxBase::OnHitSphere(AActor* sphere)
{
	
}