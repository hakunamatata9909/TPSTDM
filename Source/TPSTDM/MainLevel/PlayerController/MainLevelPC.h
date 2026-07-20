// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainLevelPC.generated.h"

/**
 * 
 */
UCLASS()
class TPSTDM_API AMainLevelPC : public APlayerController
{
	GENERATED_BODY()
	
	protected:
	virtual void BeginPlay() override;
	
	private:
	void SetCameraView();
};
