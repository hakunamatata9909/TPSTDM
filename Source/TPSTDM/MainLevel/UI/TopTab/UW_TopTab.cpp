// Fill out your copyright notice in the Description page of Project Settings.


#include "UW_TopTab.h"

#include "Components/Button.h"

void UUW_TopTab::NativeConstruct()
{
	Super::NativeConstruct();
	
#pragma region 델리게이트 바인딩
	if (Btn_Home)
	{
		Btn_Home->OnClicked.AddDynamic(this,&ThisClass::OnHomeButtonClicked);
	}
	if (Btn_Characters)
	{
		Btn_Characters->OnClicked.AddDynamic(this,&ThisClass::OnCharactersButtonClicked);
	}
	if (Btn_Matches)
	{
		Btn_Matches->OnClicked.AddDynamic(this,&ThisClass::OnMatchesButtonClicked);
	}
	if (Btn_Settings)
	{
		Btn_Settings->OnClicked.AddDynamic(this,&ThisClass::OnSettingsButtonClicked);
	}
	if (Btn_QuitGame)
	{
		Btn_QuitGame->OnClicked.AddDynamic(this,&ThisClass::OnQuitGameButtonClicked);
	}
#pragma endregion
	
}

void UUW_TopTab::NativeDestruct()
{
	Super::NativeDestruct();
	
#pragma region 델리게이트 언바인딩
	if (Btn_Home)
	{
		Btn_Home->OnClicked.RemoveAll(this);
	}
	if (Btn_Characters)
	{
		Btn_Characters->OnClicked.RemoveAll(this);
	}
	if (Btn_Matches)
	{
		Btn_Matches->OnClicked.RemoveAll(this);
	}
	if (Btn_Settings)
	{
		Btn_Settings->OnClicked.RemoveAll(this);
	}
	if (Btn_QuitGame)
	{
		Btn_QuitGame->OnClicked.RemoveAll(this);
	}
#pragma endregion
	
}

void UUW_TopTab::OnHomeButtonClicked()
{
	OnTabButtonClicked.Broadcast(ETabEnum::Home);
}

void UUW_TopTab::OnCharactersButtonClicked()
{
	OnTabButtonClicked.Broadcast(ETabEnum::Characters);
}

void UUW_TopTab::OnMatchesButtonClicked()
{
	OnTabButtonClicked.Broadcast(ETabEnum::Matches);
}

void UUW_TopTab::OnSettingsButtonClicked()
{
	OnTabButtonClicked.Broadcast(ETabEnum::Settings);
}

void UUW_TopTab::OnQuitGameButtonClicked()
{
	OnTabButtonClicked.Broadcast(ETabEnum::QuitGame);
}
