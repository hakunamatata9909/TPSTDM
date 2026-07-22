// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_PanelQuitGame.generated.h"

class UButton;
class USizeBox;
class UCanvasPanel;
/**
 * 
 */
UCLASS()
class TPSTDM_API UUW_PanelQuitGame : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	
	UFUNCTION()
	void QuitGamePopUpExit();
	UFUNCTION()
	void QuitGamePopUpCancel();
	
protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCanvasPanel> QuitGameCanvasPanel;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<USizeBox> SizeBox;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> ExitButton;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> CancelButton;
};
