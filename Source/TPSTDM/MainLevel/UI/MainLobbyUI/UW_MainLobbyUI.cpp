// Fill out your copyright notice in the Description page of Project Settings.


#include "MainLevel/UI/MainLobbyUI/UW_MainLobbyUI.h"

#include "Components/WidgetSwitcher.h"
#include "MainLevel/UI/PanelQuitGame/UW_PanelQuitGame.h"
#include "MainLevel/UI/PanelSetting/UW_PanelSetting.h"
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
	
	PanelSetting->SetVisibility(ESlateVisibility::Collapsed);
	PanelQuitGame->SetVisibility(ESlateVisibility::Collapsed);
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
	if (!MenuSwitcher)
	{
		UE_LOG(LogTemp, Warning, TEXT("[MainLobbyUI] MenuSwitcher is nullptr!"));
		return;
	}
    
	switch (TabIndex)
	{
	case ETabEnum::Home:
	case ETabEnum::Characters:
	case ETabEnum::Matches:
		{
			uint8 WidgetIndex = static_cast<uint8>(TabIndex);
			MenuSwitcher->SetActiveWidgetIndex(WidgetIndex);
          
			UE_LOG(LogTemp, Log, TEXT("[MainLobbyUI] Switched Tab to Index: %d"), WidgetIndex);
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Tab Changed: Index %d"), WidgetIndex));
			}
		}
		break;

	case ETabEnum::Settings:
		ShowSettingMenu();
		UE_LOG(LogTemp,Warning,TEXT("[MainLobbyUI] Settings Pop Up"));
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1,2.f,FColor::Green,TEXT("Settings Pop Up"));
		break;

	case ETabEnum::QuitGame:
		ShowQuitGamePopUp();
		UE_LOG(LogTemp,Warning,TEXT("[MainLobbyUI] Quit Game Pop Up"));
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1,2.f,FColor::Green,TEXT("Quit Game Pop Up"));
		break;

	default:
		UE_LOG(LogTemp, Warning, TEXT("[MainLobbyUI] Invalid TabIndex Passed!"));
		break;
	}
}

void UUW_MainLobbyUI::ShowSettingMenu()
{
	PanelSetting->SetVisibility(ESlateVisibility::Visible);
}

void UUW_MainLobbyUI::ShowQuitGamePopUp()
{
	PanelQuitGame->SetVisibility(ESlateVisibility::Visible);
}

