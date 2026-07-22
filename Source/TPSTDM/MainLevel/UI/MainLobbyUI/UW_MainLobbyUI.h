// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_MainLobbyUI.generated.h"

class UUW_PanelQuitGame;
class UUW_PanelSetting;
class UUW_PanelMatch;
class UUW_PanelCharacter;
class UUW_PanelHome;
class UWidgetSwitcher;
enum class ETabEnum : uint8;
class UUW_TopTab;
/**
 * 
 */
UCLASS()
class TPSTDM_API UUW_MainLobbyUI : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	
	UFUNCTION()
	void OnTopTabButtonClicked(ETabEnum TabIndex);
	
	UFUNCTION()
	void ShowSettingMenu();
	
	UFUNCTION()
	void ShowQuitGamePopUp();
	
protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UUW_TopTab> TopTab;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UWidgetSwitcher> MenuSwitcher;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UUW_PanelHome> PanelHome;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UUW_PanelCharacter> PanelCharacter;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UUW_PanelMatch> PanelMatch;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UUW_PanelSetting> PanelSetting;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UUW_PanelQuitGame> PanelQuitGame;
};
