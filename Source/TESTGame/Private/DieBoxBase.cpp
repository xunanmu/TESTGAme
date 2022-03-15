// Fill out your copyright notice in the Description page of Project Settings.


#include "DieBoxBase.h"

#include "SphereBase.h"
#include "Kismet/KismetStringLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "TESTGame/GemeMode/TESTGameGameModeBase.h"

void ADieBoxBase::OnHitSphere(ASphereBase* sphere)
{
	ATESTGameGameModeBase *GameModeBase= Cast<ATESTGameGameModeBase>(GetWorld()->GetAuthGameMode());
	/*打印复活次数*/
	UKismetSystemLibrary::PrintString(GetWorld(),FString::Printf(TEXT("你的死亡次数：%d"),++count));
	/*设置复活位置*/
	sphere->SetActorLocation(sphereVector);
}

unsigned ADieBoxBase::count = 0;