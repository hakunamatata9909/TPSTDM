// Fill out your copyright notice in the Description page of Project Settings.


#include "UW_OptionSelectorBase.h"
#include "Components/Button.h"

void UUW_OptionSelectorBase::NativeConstruct()
{
	Super::NativeConstruct();
	
	if (Btn_Next)
	{
		Btn_Next->OnClicked.AddDynamic(this, &UUW_OptionSelectorBase::OnNextBtnClicked);
	}
	if (Btn_Prev)
	{
		Btn_Prev->OnClicked.AddDynamic(this, &UUW_OptionSelectorBase::OnPrevBtnClicked);
	}
	
	OnDataChanged.AddDynamic(this, &UUW_OptionSelectorBase::SetDisplayText);
}

void UUW_OptionSelectorBase::NativeDestruct()
{
	Super::NativeDestruct();
	
	if (Btn_Next)
	{
		Btn_Next->OnClicked.RemoveAll(this);
	}
	if (Btn_Prev)
	{
		Btn_Prev->OnClicked.RemoveAll(this);
	}
}

void UUW_OptionSelectorBase::OnPrevBtnClicked()
{
	if (MaxIndex==0) return;
	
	CurrentIndex = (CurrentIndex-1+MaxIndex) % MaxIndex;
	OnDataChanged.Broadcast(CurrentIndex);
}

void UUW_OptionSelectorBase::OnNextBtnClicked()
{
	if (MaxIndex==0) return;
	
	CurrentIndex = (CurrentIndex+1+MaxIndex) % MaxIndex;
	OnDataChanged.Broadcast(CurrentIndex);
}

void UUW_OptionSelectorBase::SetDisplayText(uint8 NewIndex)
{
}

uint8 UUW_OptionSelectorBase::GetCurrentIndex()
{
	return CurrentIndex;
}

void UUW_OptionSelectorBase::SetCurrentIndex(uint8 NewCurrentIndex)
{
	CurrentIndex = NewCurrentIndex;
}

uint8 UUW_OptionSelectorBase::GetMaxIndex()
{
	return MaxIndex;
}

void UUW_OptionSelectorBase::SetMaxIndex(uint8 NewMaxIndex)
{
	MaxIndex = NewMaxIndex;
}



