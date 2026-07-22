// Fill out your copyright notice in the Description page of Project Settings.


#include "MainLevel/UI/PanelQuitGame/UW_PanelQuitGame.h"

#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"

void UUW_PanelQuitGame::NativeConstruct()
{
	Super::NativeConstruct();
	
#pragma region 델리게이트 바인딩
	if (ExitButton)
	{
		ExitButton->OnClicked.AddDynamic(this, &UUW_PanelQuitGame::QuitGamePopUpExit);	
	}
	if (CancelButton)
	{
		CancelButton->OnClicked.AddDynamic(this, &UUW_PanelQuitGame::QuitGamePopUpCancel);
	}
#pragma endregion
}

void UUW_PanelQuitGame::NativeDestruct()
{
	Super::NativeDestruct();
	
#pragma region 델리게이트 언바인딩
	if (ExitButton)
	{
		ExitButton->OnClicked.RemoveAll(this);
	}
	if (CancelButton)
	{
		CancelButton->OnClicked.RemoveAll(this);
	}
#pragma endregion
}

void UUW_PanelQuitGame::QuitGamePopUpExit()
{
	UKismetSystemLibrary::QuitGame(
		GetWorld(),
		GetOwningPlayer(),
		EQuitPreference::Quit,
		false);
}

void UUW_PanelQuitGame::QuitGamePopUpCancel()
{
	SetVisibility(ESlateVisibility::Collapsed);
}
