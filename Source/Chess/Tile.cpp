// Fill out your copyright notice in the Description page of Project Settings.


#include "Tile.h"

ATile::ATile()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	StaticMeshComponent->SetupAttachment(RootComponent);
}

void ATile::BeginPlay()
{
	Super::BeginPlay();
}


