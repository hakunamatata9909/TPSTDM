// Fill out your copyright notice in the Description page of Project Settings.


#include "MainLevel/PreviewChracter/PreviewPawn.h"

// Sets default values
APreviewPawn::APreviewPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);
	
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMeshComponent");
	SkeletalMeshComponent->SetupAttachment(SceneComponent);
}

// Called when the game starts or when spawned
void APreviewPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APreviewPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APreviewPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

