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
  FVector EarthVector{FVector(1.1, 3.12, 43.12)};
};
