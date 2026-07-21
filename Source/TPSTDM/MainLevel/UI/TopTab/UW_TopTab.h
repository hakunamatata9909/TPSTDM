// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_TopTab.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class ETabEnum : uint8
{
	Home = 0,
	Characters = 1,
	Matches = 2,
	Settings =3,
	QuitGame = 4,
};

class UButton;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTabButtonClicked, ETabEnum, TabIndex);

UCLASS()
class TPSTDM_API UUW_TopTab : public UUserWidget
{
	GENERATED_BODY()
	
	public:
	UPROPERTY(BlueprintAssignable,BlueprintCallable, Category = "Events")
	FOnTabButtonClicked OnTabButtonClicked;
	
	protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	
	UFUNCTION()
	void OnHomeButtonClicked();
	UFUNCTION()
	void OnCharactersButtonClicked();
	UFUNCTION()
	void OnMatchesButtonClicked();
	UFUNCTION()
	void OnSettingsButtonClicked();
	UFUNCTION()
	void OnQuitGameButtonClicked();
	
	protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> Btn_Home;
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> Btn_Characters;
	UPROPERTY(meta=(bindWidget))
	TObjectPtr<UButton> Btn_Matches;
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> Btn_Settings;
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> Btn_QuitGame;
	
};
