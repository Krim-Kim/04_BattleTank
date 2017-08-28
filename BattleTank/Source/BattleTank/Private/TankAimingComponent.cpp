// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; // TODO should this really Tick?
	
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* barrelToSet)
{
	if(!barrelToSet) return;
	barrel = barrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* turretToSet)
{
	if(!turretToSet) return;
	turret = turretToSet;
}

void UTankAimingComponent::AimAt(FVector hitLocation, float launchSpeed)
{
	if(!barrel || !turret) return;

	MoveTurretTowards(hitLocation.GetSafeNormal());

	FVector outLaunchVelocity;
	FVector startLocation = barrel->GetSocketLocation(FName("Projectile"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		outLaunchVelocity,
		startLocation,
		hitLocation,
		launchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	
	if(bHaveAimSolution)
	{
		FVector aimDirection = outLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(aimDirection);
		//auto time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found"), time);
	}
	// If no solution found do nothing
	else
	{
		//auto time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f: No aim solve found"), time);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector aimDirection)
{
	// Work out difference between current barrel rotation and aim direction
	FRotator barrelRotator = barrel->GetForwardVector().Rotation();

	FRotator aimAsRotator = aimDirection.Rotation();
	FRotator barrelDeltaRotator = aimAsRotator - barrelRotator;

	barrel->Elevate(barrelDeltaRotator.Pitch);
}

void UTankAimingComponent::MoveTurretTowards(FVector aimDirection)
{
	FRotator turretRotator = turret->GetForwardVector().Rotation();

	FRotator aimAsRotator = aimDirection.Rotation();
	FRotator turretDeltaRotator = aimAsRotator - turretRotator;

	turret->Rotate(turretDeltaRotator.Yaw);
}
