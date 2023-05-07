// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Ch_RTS_unit.h"
#include "HUD_RTS_map1.generated.h"
/**
 * 
 */
UCLASS()
class RTS2_API AHUD_RTS_map1 : public AHUD
{
	GENERATED_BODY()
	
public:
	FVector2D InitalPoint;//��꿪ʼ��ѡʱ��λ��
	FVector2D CurrentPoint;//�������or������ѡʱ��λ��

	bool isFrameSelecting;

	TArray<ACh_RTS_unit*> FoundUnits;

	virtual void DrawHUD() override;

	FVector2D GetMouusePos2D();
};
