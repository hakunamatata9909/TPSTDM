// Fill out your copyright notice in the Description page of Project Settings.


#include "MainLevel/UI/MainLobbyUI/UW_MainLobbyUI.h"

#include "Components/WidgetSwitcher.h"
#include "MainLevel/UI/TopTab/UW_TopTab.h"

void UUW_MainLobbyUI::NativeConstruct()
{
	Super::NativeConstruct();
	
#pragma region 델리게이트 바인딩
	if (TopTab)
	{
		TopTab->OnTabButtonClicked.AddUniqueDynamic(this,&ThisClass::OnTopTabButtonClicked);
	}
#pragma endregion
}

void UUW_MainLobbyUI::NativeDestruct()
{
	Super::NativeDestruct();
	
#pragma region 델리게이트 언바인딩
	if (TopTab)
	{
		TopTab->OnTabButtonClicked.RemoveAll(this);
	}
#pragma endregion
}

void UUW_MainLobbyUI::OnTopTabButtonClicked(ETabEnum TabIndex)
{
	// 스위처가 Valid한지 먼저 확인하는 방어 코드
	if (!MenuSwitcher)
	{
		UE_LOG(LogTemp, Warning, TEXT("[MainLobbyUI] MenuSwitcher is nullptr!"));
		return;
	}

	switch (TabIndex)
	{
	case ETabEnum::Home:
		UE_LOG(LogTemp, Log, TEXT("[MainLobbyUI] Switched to Home Tab (Index 0)"));
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("Tab Changed: Home"));
		}
		MenuSwitcher->SetActiveWidgetIndex(0);
		break;

	case ETabEnum::Characters:
		UE_LOG(LogTemp, Log, TEXT("[MainLobbyUI] Switched to Characters Tab (Index 1)"));
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, TEXT("Tab Changed: Characters"));
		}
		MenuSwitcher->SetActiveWidgetIndex(1);
		break;

	case ETabEnum::Matches:
		UE_LOG(LogTemp, Log, TEXT("[MainLobbyUI] Switched to Matches Tab (Index 2)"));
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("Tab Changed: Matches"));
		}
		MenuSwitcher->SetActiveWidgetIndex(2);
		break;

	case ETabEnum::Settings:
		UE_LOG(LogTemp, Log, TEXT("[MainLobbyUI] Settings Opened"));
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Orange, TEXT("Tab Changed: Settings Popup"));
		}
		ShowSettingMenu();
		break;
	case ETabEnum::QuitGame:
		UE_LOG(LogTemp, Log, TEXT("[MainLobbyUI] QUIT GAME POPUP"));
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Tab Changed: Quit Game Popup"));
		}
		ShowQuitGamePopUp();
		break;
	default:
		UE_LOG(LogTemp, Warning, TEXT("[MainLobbyUI] Invalid TabIndex Passed!"));
		break;
	}
}

void UUW_MainLobbyUI::ShowSettingMenu()
{
}

void UUW_MainLobbyUI::ShowQuitGamePopUp()
{
}

