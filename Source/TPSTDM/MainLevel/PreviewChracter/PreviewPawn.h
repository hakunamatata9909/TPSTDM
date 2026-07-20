// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PreviewPawn.generated.h"

UCLASS()
class TPSTDM_API APreviewPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APreviewPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Componenets|SceneComponent")
	TObjectPtr<USceneComponent> SceneComponent;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Components|SkeletalMeshComponent")
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
