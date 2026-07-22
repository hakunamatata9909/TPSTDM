// Fill out your copyright notice in the Description page of Project Settings.


#include "MainLevel/UI/PanelSetting/UW_PanelSetting.h"

#include "Components/Button.h"

void UUW_PanelSetting::NativeConstruct()
{
	Super::NativeConstruct();
	
	if (ExitButton)
	{
		ExitButton->OnClicked.AddDynamic(this, &UUW_PanelSetting::Exit);
	}
	if (SaveButton)
	{
		SaveButton->OnClicked.AddDynamic(this, &UUW_PanelSetting::Save);
	}
}

void UUW_PanelSetting::NativeDestruct()
{
	Super::NativeDestruct();
}

void UUW_PanelSetting::Exit()
{
	SetVisibility(ESlateVisibility::Collapsed);
}

void UUW_PanelSetting::Save()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,2.f,FColor::Green,FString::Printf(TEXT("Setting Saved")));
	}
	SetVisibility(ESlateVisibility::Collapsed);
}
