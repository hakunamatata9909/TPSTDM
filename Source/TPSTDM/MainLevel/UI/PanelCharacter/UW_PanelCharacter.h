// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_PanelCharacter.generated.h"

class UCanvasPanel;
/**
 * 
 */
UCLASS()
class TPSTDM_API UUW_PanelCharacter : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	
protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCanvasPanel> CharacterCanvasPanel;
	
};
