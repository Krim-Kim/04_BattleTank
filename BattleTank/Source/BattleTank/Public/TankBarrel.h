// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

// Holds Barrel's properties and Elevate-method
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max DOWN-movement, and +1 is max UP-movement
	void Elevate(float relativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float maxDegreesPerSecond = 10.0f;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float maxElevationDegrees = 30.0f;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float minElevationDegrees = 0.0f;
};
