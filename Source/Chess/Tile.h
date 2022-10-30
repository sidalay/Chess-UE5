// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

USTRUCT(BlueprintType)
struct FTileInfo
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int X{};
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Y{};
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Z{};

	FTileInfo() = default;
	FTileInfo(int const NewX, int const NewY, int const NewZ)
		: X(NewX), Y(NewY), Z(NewZ) {}
};

UCLASS()
class CHESS_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent{};
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = true))
	FTileInfo TileInfo{};
};
