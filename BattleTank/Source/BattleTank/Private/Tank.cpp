// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// No need to protect pointers as added at construction
	tankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
}

void ATank::SetBarrelReference(UTankBarrel* barrelToSet)
{
	tankAimingComponent->SetBarrelReference(barrelToSet);
	barrel = barrelToSet;
}

void ATank::SetTurretReference(UTankTurret* turretToSet)
{
	tankAimingComponent->SetTurretReference(turretToSet);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector hitLocation)
{
	tankAimingComponent->AimAt(hitLocation, launchSpeed);
}

void ATank::Fire()
{
	if(!barrel) return;

	// Spawn a projectile at the socket location on the Barrel
	FName projectileSocket = FName("Projectile");
	FVector projectileLocation = barrel->GetSocketLocation(projectileSocket);
	FRotator projectileRotation = barrel->GetSocketRotation(projectileSocket);

	auto projectile = GetWorld()->SpawnActor<AProjectile>(projectileBlueprint, projectileLocation, projectileRotation);
	projectile->LaunchProjectile(launchSpeed);
}
