// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "HUD_RTS_map1.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PC_RTS_map1.generated.h"

/**
 * 
 */
UCLASS()
class RTS2_API APC_RTS_map1 : public APlayerController
{
	GENERATED_BODY()

public:
	APC_RTS_map1();

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	//virtual void PlayerTick() override;

	AHUD_RTS_map1* HUDPtr;

protected:

	void FrameSelectionPressed();
	
	void FrameSelectionReleased();

	void MovePressed();

	TArray<ACh_RTS_unit*> CurSlectedUnitsGroup;

	
};
