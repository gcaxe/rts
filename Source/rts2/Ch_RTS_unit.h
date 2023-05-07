// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Ch_RTS_unit.generated.h"

UCLASS()
class RTS2_API ACh_RTS_unit : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACh_RTS_unit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void SetSelected();

	void SetDeselected();

};
