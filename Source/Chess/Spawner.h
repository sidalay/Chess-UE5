// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class CHESS_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawner();

	UFUNCTION(BlueprintCallable)
	void SetupMesh();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	UStaticMesh* StaticMesh;
};
