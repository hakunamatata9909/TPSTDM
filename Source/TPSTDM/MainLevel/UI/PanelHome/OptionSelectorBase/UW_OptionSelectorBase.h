// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_OptionSelectorBase.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDataChanged,uint8,NewIndex);

UCLASS()
class TPSTDM_API UUW_OptionSelectorBase : public UUserWidget
{
	GENERATED_BODY()
public:
	uint8 GetCurrentIndex();
	void SetCurrentIndex(uint8 NewCurrentIndex);
	uint8 GetMaxIndex();
	void SetMaxIndex(uint8 NewMaxIndex);
public:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<class UTextBlock> DisplayText;
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<class UButton> Btn_Prev;
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> Btn_Next;
	
	
protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	UFUNCTION()
	virtual void OnPrevBtnClicked();
	UFUNCTION()
	virtual void OnNextBtnClicked();
	UFUNCTION()
	virtual void SetDisplayText(uint8 NewIndex);
	
protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "OptionSelector")
	uint8 MaxIndex=0;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "OptionSelector")
	uint8 CurrentIndex=0;
	UPROPERTY(BlueprintAssignable)
	FOnDataChanged OnDataChanged;
	
};
