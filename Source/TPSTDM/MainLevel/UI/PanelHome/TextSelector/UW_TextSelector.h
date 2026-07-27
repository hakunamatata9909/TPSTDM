// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_TextSelector.generated.h"

class UTextBlock;
class UButton;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTextChangedDelegate,int32,NewSelectedIndex);

UCLASS()
class TPSTDM_API UUW_TextSelector : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetTextArray(const TArray<FText>& NewTextArray);
	UFUNCTION()
	void SetDisplayText(int32 NewSelectedIndex);
public:
	UPROPERTY()
	FOnTextChangedDelegate OnTextChangedDelegate;
	
protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	
	UFUNCTION()
	void OnLeftButtonClicked();
	UFUNCTION()
	void OnRightButtonClicked();
protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> LeftButton;
	
	UPROPERTY(meta=(BindWidget))	
	TObjectPtr<UButton> RightButton;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> TopText;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> DisplayText;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category="SelectorTexts")
	TArray<FText> TextArray;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SelectorIndex")
	int32 SelectedIndex;
};
