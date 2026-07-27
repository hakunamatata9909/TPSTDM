// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_PanelHome.generated.h"

class UDA_MapInfo;
class UButton;
class UUW_TextSelector;
class UVerticalBox;
class UCanvasPanel;
/**
 * 
 */
UCLASS()
class TPSTDM_API UUW_PanelHome : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	void SetMapSelectorTextArray();
	UFUNCTION()
	void OnMapSelectorTextChanged(int32 NewSelectedIndex);
protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="PanelHome|DataAsset")
	TArray<UDA_MapInfo*> MapDataAssets;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCanvasPanel> PanelHomeCanvas;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UVerticalBox> PanelHomeVerticalBox;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UUW_TextSelector> PanelHomeMapSelector;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UUW_TextSelector> PanelHomePlayersSelector;
	
	//
	// UPROPERTY(meta=(BindWidget))
	// TObjectPtr<UUW_TextSelector> HomePanelLanSelector;
	//
	// UPROPERTY(meta=(BindWidget))
	// TObjectPtr<UButton> HomePanelCreateGameButton;
};
