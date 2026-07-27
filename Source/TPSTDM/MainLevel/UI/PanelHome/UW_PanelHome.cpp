// Fill out your copyright notice in the Description page of Project Settings.


#include "MainLevel/UI/PanelHome/UW_PanelHome.h"

#include "MainLevel/DataAsset/DA_MapInfo.h"
#include "TextSelector/UW_TextSelector.h"

void UUW_PanelHome::NativeConstruct()
{
	Super::NativeConstruct();
	PanelHomeMapSelector->OnTextChangedDelegate.AddUniqueDynamic(this,&ThisClass::OnMapSelectorTextChanged);
	SetMapSelectorTextArray();
}

void UUW_PanelHome::NativeDestruct()
{
	Super::NativeDestruct();
	PanelHomeMapSelector->OnTextChangedDelegate.RemoveAll(this);
}

void UUW_PanelHome::SetMapSelectorTextArray()
{
	if (MapDataAssets.IsEmpty())
	{
#if WITH_EDITOR
		GEngine->AddOnScreenDebugMessage(-1, 2.f , FColor::Green, FString::Printf(TEXT("map data asset empty")));
#endif
		return;
	}
	
	TArray<FText> NewTextArray;
	
	for (int i=0;i<MapDataAssets.Num();i++)
	{
		NewTextArray.Add(MapDataAssets[i]->MapDisplayName);
	}
	
	PanelHomeMapSelector->SetTextArray(NewTextArray);
}

void UUW_PanelHome::OnMapSelectorTextChanged(int32 NewSelectedIndex)
{
	if (MapDataAssets.IsEmpty())
	{
#if WITH_EDITOR
		GEngine->AddOnScreenDebugMessage(-1, 2.f , FColor::Green, FString::Printf(TEXT("map data asset empty")));
#endif
		return;
	}
	if (!MapDataAssets.IsValidIndex(NewSelectedIndex) || !MapDataAssets[NewSelectedIndex])
	{
		return;
	}
	
	int32 MaxPlayers = MapDataAssets[NewSelectedIndex]->MaxPlayer;
	TArray<FText> NewTextArray;
	
	for (int i=2;i<=MaxPlayers;i+=2)
	{	NewTextArray.Add(FText::FromString(FString::FromInt(i)));
	}
	
	if (PanelHomePlayersSelector)
	{
		PanelHomePlayersSelector->SetTextArray(NewTextArray);
		PanelHomePlayersSelector->SetDisplayText(NewTextArray.Num()-1);
	}
}