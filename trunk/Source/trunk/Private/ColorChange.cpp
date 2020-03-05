// Fill out your copyright notice in the Description page of Project Settings.


#include "ColorChange.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"

// Sets default values
AColorChange::AColorChange()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AColorChange::BeginPlay()
{
	Super::BeginPlay();
	auto Cube = FindComponentByClass<UStaticMeshComponent>();
	auto Material = Cube->GetMaterial(0);

	DynamicMaterial = UMaterialInstanceDynamic::Create(Material, NULL);
	Cube->SetMaterial(0, DynamicMaterial);
}

// Called every frame
void AColorChange::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float blend = 0.5f + FMath::Cos(rand());
	DynamicMaterial->SetScalarParameterValue(TEXT("Blend"), blend);
}

