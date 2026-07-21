// Fill out your copyright notice in the Description page of Project Settings.


#include "UW_MapOptionSelector.h"
#include "Components/TextBlock.h"
#include "MainLevel/DataAsset/DA_MapInfo.h"

void UUW_MapOptionSelector::NativeConstruct()
{
	Super::NativeConstruct();
	
	MaxIndex = MapInfos.Num();
	
	if (MaxIndex>0)
	{
		SetDisplayText(CurrentIndex);
	}
}

void UUW_MapOptionSelector::SetDisplayText(uint8 NewIndex)
{
	Super::SetDisplayText(NewIndex);
	
	if (MapInfos.IsValidIndex(NewIndex) && NewIndex<MaxIndex && DisplayText)
	{
		DisplayText->SetText(MapInfos[NewIndex]->MapDisplayName);
	}
}
