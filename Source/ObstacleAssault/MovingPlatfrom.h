// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatfrom.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatfrom : public AActor
{
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
		FVector CubeStartLocation{ FVector(-14959.0, -1800.0, 4023.0) };
		// UPROPERTY(EditAnywhere)
		// FVector CubeEndLocation{ FVector(1.0, 2.0, 50.0) };
		// UPROPERTY(EditInstanceOnly)
		// bool GoingUp{ true };

		UPROPERTY(EditAnywhere)
		// FVector CubeScale{ FVector(2.5, 2.5, 0.2) };
		FVector CubeScale{ FVector(1.0, 1.0, 1.0) };

		// UPROPERTY(EditAnywhere)
		// int32 TimeToMove{ 30 };	   // seconds

		// UPROPERTY(VisibleAnywhere)
		// float DistanceFromStart{};
		// UPROPERTY(EditAnywhere)
		// float ExcDeltaX{};
		// UPROPERTY(EditAnywhere)
		// float ExcDeltaY{};
		// UPROPERTY(EditAnywhere)
		// float ExcDeltaZ{};

		UPROPERTY(EditAnywhere, Category = "Moving Platform")
		FVector PlatformVelocity{ FVector(0, 0, 0) };

		UPROPERTY(EditAnywhere, Category = "Moving Platform")
		float MoveDistance{ 100.0 };
};
