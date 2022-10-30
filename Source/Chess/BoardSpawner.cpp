// Fill out your copyright notice in the Description page of Project Settings.


#include "BoardSpawner.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ABoardSpawner::ABoardSpawner()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ABoardSpawner::BuildBoard(const FVector CenteredLocation, const int X, const int Y)
{
	UE_LOG(LogTemp, Warning, TEXT("BuildBoard called"));
	// Do not execute if BoardTiles != empty
	if (BoardTiles.IsEmpty())
	{
		BoardSize.X = X;
		BoardSize.Y = Y;

		// 2D Grid Execution Macro
		for (auto OuterIndex{0}; OuterIndex <= Y - 1; ++OuterIndex)
		{
			for (auto InnerIndex{0}; InnerIndex <= X - 1; ++InnerIndex)
			{
				float constexpr SectorSize{100.f};

				// Prepare a Spawn Transform
				FVector SpawnLocation{
					FVector(static_cast<float>(InnerIndex) - static_cast<float>(X) / 2.f,
							static_cast<float>(OuterIndex) - static_cast<float>(Y) / 2.f,
							0.f)
					* SectorSize
					* 1.f
					+ CenteredLocation};

				FTransform SpawnTransform{};
				SpawnTransform.SetLocation(SpawnLocation);

				if (TileClass.LoadSynchronous())
				{
					AActor* TileToSpawn{UGameplayStatics::BeginDeferredActorSpawnFromClass(this, TileClass.LoadSynchronous(), SpawnTransform)};

					ATile* Tile{Cast<ATile>(TileToSpawn)};
					if (Tile)
					{
						Tile->SetTileInfo({InnerIndex, OuterIndex, 0});
					}

					TileToSpawn->FinishSpawning(SpawnTransform);
					BoardTiles.Add(TileToSpawn);
					TileToSpawn->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
				}
			}
		}
	}
}

void ABoardSpawner::BeginPlay()
{
	Super::BeginPlay();
}


