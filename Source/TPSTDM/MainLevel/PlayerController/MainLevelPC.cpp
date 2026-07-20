// Fill out your copyright notice in the Description page of Project Settings.


#include "MainLevel/PlayerController/MainLevelPC.h"
#include "Kismet/GameplayStatics.h"

void AMainLevelPC::BeginPlay()
{
	Super::BeginPlay();
	
	SetCameraView();
}

void AMainLevelPC::SetCameraView()
{
	TArray<AActor*> Cameras;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(),FName("LobbyCamera"),Cameras);
	
	if (Cameras.Num() > 0 && Cameras[0])
	{
		SetViewTargetWithBlend(Cameras[0]);
	}
	
	bShowMouseCursor=true;
	SetInputMode(FInputModeUIOnly());
}
