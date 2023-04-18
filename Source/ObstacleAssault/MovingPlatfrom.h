// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatfrom.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatfrom : public AActor {
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  AMovingPlatfrom();

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

  UPROPERTY(EditAnywhere)
  FVector CubeLocation{FVector(-14959.0, -2012.0, 4023.0)};
  UPROPERTY(EditAnywhere)
  FVector CubeScale{FVector(2.5, 2.5, 0.2)};

  UPROPERTY(EditAnywhere)
  int32 MovementDeltaTick{1200};

  UPROPERTY(EditAnywhere)
  float ExcDeltaX{};
  UPROPERTY(EditAnywhere)
  float ExcDeltaY{};
  UPROPERTY(EditAnywhere)
  float ExcDeltaZ{};
};
