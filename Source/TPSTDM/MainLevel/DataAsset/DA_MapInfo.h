// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_MapInfo.generated.h"

/**
 * 
 */
UCLASS()
class TPSTDM_API UDA_MapInfo : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapInfo")
	FText MapDisplayName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapInfo")
	TSoftObjectPtr<UWorld> MapLevel;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapInfo")
	TSoftObjectPtr<UTexture2D> MapThumbnail;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MapInfo")
	uint8 MaxPlayer;
};
