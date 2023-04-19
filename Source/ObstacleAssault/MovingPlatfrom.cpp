// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatfrom.h"
// #include <algorithm>

// Sets default values
AMovingPlatfrom::AMovingPlatfrom()
{
	// Set this actor to call Tick() every frame.  You can turn this off to
	// improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatfrom::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(CubeStartLocation);
	SetActorScale3D(CubeScale);

	// PlatformVelocity.X = (CubeEndLocation.X - (CubeStartLocation.X)) / TimeToMove;	  // 1/60 seconds per frame
	// PlatformVelocity.Y = (CubeEndLocation.Y - (CubeStartLocation.Y)) / TimeToMove;
	// PlatformVelocity.Z = ((CubeEndLocation.Z - 5223.0) + (CubeStartLocation.Z - 5223.0)) / TimeToMove;
}

// Called every frame
void AMovingPlatfrom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Move platform forwards
	// Get current location
	FVector CubeCurrentLocation = GetActorLocation();
	// Add vector to that location
	CubeCurrentLocation += PlatformVelocity * DeltaTime;
	{
		// if (CubeCurrentLocation.X < CubeEndLocation.X)
		// 	CubeCurrentLocation.X += PlatformVelocity.X * DeltaTime;
		// else if (CubeCurrentLocation.X > (CubeEndLocation.X + 1.0))
		// 	CubeCurrentLocation.X -= 0.1 * PlatformVelocity.X * DeltaTime;
		// if (CubeCurrentLocation.Y < CubeEndLocation.Y)
		// 	CubeCurrentLocation.Y += PlatformVelocity.Y * DeltaTime;
		// else if (CubeCurrentLocation.Y > (CubeEndLocation.Y + 1.0))
		// 	CubeCurrentLocation.Y -= 0.1 * PlatformVelocity.Y * DeltaTime;

		// if ((CubeCurrentLocation.Z < 5223.0) && GoingUp)
		// 	CubeCurrentLocation.Z -= PlatformVelocity.Z * DeltaTime;
		// else if (CubeCurrentLocation.Z > CubeEndLocation.Z)
		// {
		// 	GoingUp = false;
		// 	CubeCurrentLocation.Z += PlatformVelocity.Z * DeltaTime;
		// }
		// else if ((CubeCurrentLocation.Z < (CubeEndLocation.Z - 10.0)) && !GoingUp)
		// {
		// 	CubeCurrentLocation.Z -= 0.1 * PlatformVelocity.Z * DeltaTime;
		// }
	}
	// Set the new location
	SetActorLocation(CubeCurrentLocation);

	// DistanceFromStart = static_cast<float>(FVector::Dist(CubeStartLocation, CubeCurrentLocation));

	// Send platform back if gone to far

	// Check how far we've moved
	float DistanceMoved = FVector::Dist(CubeStartLocation, CubeCurrentLocation);

	// Reverse direction of motion if gone too far
	if (DistanceMoved > MoveDistance)
	{
		float OverShoot = DistanceMoved - MoveDistance;
		// UE_LOG(LogTemp, Warning, TEXT("This body have overshoot: [%f]."), OverShoot);
		V_LOGM(LogTemp, " has over shoot: %f", OverShoot);

		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		CubeStartLocation += MoveDirection * MoveDistance;
		SetActorLocation(CubeStartLocation);
		PlatformVelocity *= -1;
	}
}
