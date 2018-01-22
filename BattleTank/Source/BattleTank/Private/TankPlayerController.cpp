// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerControler not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerControler possesing: %s"), *(ControlledTank->GetName()));
	}

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));

}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return;  }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
		// TODO tell controlled tank to aim at this point
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
}

