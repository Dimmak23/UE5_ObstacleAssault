// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatfrom.h"
// #include <algorithm>

// Sets default values
AMovingPlatfrom::AMovingPlatfrom() {
  // Set this actor to call Tick() every frame.  You can turn this off to
  // improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatfrom::BeginPlay() {
  Super::BeginPlay();

  SetActorLocation(CubeLocation);
  SetActorScale3D(CubeScale);

  ExcDeltaX = (1.0 - (CubeLocation.X)) / MovementDeltaTick;
  ExcDeltaY = (2.0 - (CubeLocation.Y)) / MovementDeltaTick;
  ExcDeltaZ = (3.0 - (CubeLocation.Z)) / MovementDeltaTick;
}

// Called every frame
void AMovingPlatfrom::Tick(float DeltaTime) {

  Super::Tick(DeltaTime);

  if (CubeLocation.X < 1.0)
    CubeLocation.X += ExcDeltaX;
  if (CubeLocation.Y < 2.0)
    CubeLocation.Y += ExcDeltaY;

  if ((CubeLocation.X < -10750.0) && (CubeLocation.Y < -1610.0))
    CubeLocation.Z -= ExcDeltaZ;
  else if (CubeLocation.Z > 3.0)
    CubeLocation.Z += ExcDeltaZ;

  SetActorLocation(CubeLocation);
}
