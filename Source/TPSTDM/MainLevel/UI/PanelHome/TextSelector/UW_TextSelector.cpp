// Fill out your copyright notice in the Description page of Project Settings.


#include "MainLevel/UI/PanelHome/TextSelector/UW_TextSelector.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UUW_TextSelector::NativeConstruct()
{
	Super::NativeConstruct();
	
	SelectedIndex = 0; 

#pragma region 델리게이트 바인딩
	if (LeftButton)
	{
		LeftButton->OnClicked.AddUniqueDynamic(this, &UUW_TextSelector::OnLeftButtonClicked);
	}
	if (RightButton)
	{
		RightButton->OnClicked.AddUniqueDynamic(this, &UUW_TextSelector::OnRightButtonClicked);
	}
#pragma endregion
}

void UUW_TextSelector::NativeDestruct()
{
	Super::NativeDestruct();
	
#pragma region 델리게이트 언바인딩
	if (LeftButton)
	{
		LeftButton->OnClicked.RemoveAll(this);
	}
	if (RightButton)
	{
		RightButton->OnClicked.RemoveAll(this);
	}
	
	OnTextChangedDelegate.Clear();
#pragma endregion
}

void UUW_TextSelector::OnLeftButtonClicked()
{
	if (TextArray.IsEmpty()) return;
	
	int32 TextArraySize = TextArray.Num();
	int32 NewSelectedIndex = (SelectedIndex - 1  + TextArraySize) % TextArraySize;
	SelectedIndex = NewSelectedIndex;
	
	SetDisplayText(SelectedIndex);
}

void UUW_TextSelector::OnRightButtonClicked()
{
	if (TextArray.IsEmpty()) return;
	
	int32 TextArraySize = TextArray.Num();
	int32 NewSelectedIndex = (SelectedIndex + 1 + TextArraySize) % TextArraySize;
	SelectedIndex = NewSelectedIndex;

	SetDisplayText(SelectedIndex);
}

void UUW_TextSelector::SetDisplayText(int32 NewSelectedIndex)
{
	DisplayText->SetText(TextArray[NewSelectedIndex]);
	SelectedIndex = NewSelectedIndex;
	OnTextChangedDelegate.Broadcast(NewSelectedIndex);
}

void UUW_TextSelector::SetTextArray(const TArray<FText>& NewTextArray)
{
	TextArray = NewTextArray;
	SelectedIndex = 0;
	
	if (!TextArray.IsEmpty())
	{
		SetDisplayText(SelectedIndex);
	}
}
