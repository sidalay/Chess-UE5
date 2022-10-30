// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void ASpawner::SetupMesh()
{
	StaticMeshComponent = NewObject<UStaticMeshComponent>(this, UStaticMeshComponent::StaticClass(),
														  TEXT("Static Mesh"));

	if (StaticMeshComponent)
	{
		StaticMeshComponent->RegisterComponent();

		StaticMeshComponent->AttachToComponent(RootComponent.Get(), FAttachmentTransformRules::KeepRelativeTransform);

		StaticMeshComponent->CreationMethod = EComponentCreationMethod::Instance;

		if (StaticMesh)
		{
			StaticMeshComponent->SetStaticMesh(StaticMesh);
		}
	}
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
}
