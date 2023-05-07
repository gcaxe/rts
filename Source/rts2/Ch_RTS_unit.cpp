// Fill out your copyright notice in the Description page of Project Settings.


#include "Ch_RTS_unit.h"

// Sets default values
ACh_RTS_unit::ACh_RTS_unit()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACh_RTS_unit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACh_RTS_unit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACh_RTS_unit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACh_RTS_unit::SetSelected() {
	//
}

void ACh_RTS_unit::SetDeselected() {
	//
}