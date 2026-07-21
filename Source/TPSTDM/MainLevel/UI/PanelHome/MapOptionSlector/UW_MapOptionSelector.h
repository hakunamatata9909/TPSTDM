// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainLevel/UI/PanelHome/OptionSelectorBase/UW_OptionSelectorBase.h"
#include "UW_MapOptionSelector.generated.h"

/**
 * 
 */
UCLASS()
class TPSTDM_API UUW_MapOptionSelector : public UUW_OptionSelectorBase
{
	GENERATED_BODY()
	
	protected:
	virtual void NativeConstruct() override;
	virtual void SetDisplayText(uint8 NewIndex) override;
	
	protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category= "MapOptionSelector")
	TArray<TObjectPtr<class UDA_MapInfo>> MapInfos;
	
};
