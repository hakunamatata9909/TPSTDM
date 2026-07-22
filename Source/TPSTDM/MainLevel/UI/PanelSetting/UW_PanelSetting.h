// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_PanelSetting.generated.h"

class UButton;
class UCanvasPanel;
/**
 * 
 */
UCLASS()
class TPSTDM_API UUW_PanelSetting : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	
	UFUNCTION()
	virtual void Exit();
	UFUNCTION()
	virtual void Save();
protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCanvasPanel> SettingCanvasPanel;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> ExitButton;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> SaveButton;
	
};