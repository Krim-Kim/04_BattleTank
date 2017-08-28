// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float relativeSpeed)
{
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time
	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1, 1);
	float rotationChange = relativeSpeed * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float rawNewRotation = RelativeRotation.Yaw + rotationChange;
	//float rotation = FMath::Clamp<float>(rawNewRotation, minRotationDegrees, maxRotationDegrees);

	SetRelativeRotation(FRotator(0, rawNewRotation, 0));
}



