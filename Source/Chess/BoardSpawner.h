// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tile.h"
#include "GameFramework/Actor.h"
#include "BoardSpawner.generated.h"

UCLASS()
class CHESS_API ABoardSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoardSpawner();

	UFUNCTION(BlueprintCallable)
	void BuildBoard(const FVector CenteredLocation, const int X, const int Y);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FVector2D BoardSize{};

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<TObjectPtr<AActor>> BoardTiles{};

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<ATile> TileClass{};
};
