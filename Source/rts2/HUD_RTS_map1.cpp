// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD_RTS_map1.h"

void AHUD_RTS_map1::DrawHUD() {
	if (isFrameSelecting) {//��ѡ
		//��һ����
		CurrentPoint = GetMouusePos2D();
		DrawRect(FLinearColor(0, 0, 1, .15f), InitalPoint.X, InitalPoint.Y, 
			CurrentPoint.X - InitalPoint.X, CurrentPoint.Y - InitalPoint.Y);//cpp��size����Ϊ��

		//������Ʊ�ѡ�е�λ���µ�ԲȦ	
		if (FoundUnits.Num() > 0) {
			for (int32 i = 0; i < FoundUnits.Num(); i++) {
				FoundUnits[i]->SetDeselected();
			}
		}
		FoundUnits.Empty();
		GetActorsInSelectionRectangle<ACh_RTS_unit>(InitalPoint, CurrentPoint, FoundUnits, false);
		if (FoundUnits.Num() > 0) {
			for (int32 i = 0; i < FoundUnits.Num(); i++) {
				FoundUnits[i]->SetSelected();
			}
		}
		//UE_LOG(LogTemp, Warning, TEXT(" %d"), FoundUnits.Num());
	}
}

FVector2D AHUD_RTS_map1::GetMouusePos2D() {
	APlayerController* pc = GetOwningPlayerController();
	ULocalPlayer* LocalPlayer = pc->GetLocalPlayer();
	FVector2D MousePosition;
	if (LocalPlayer && LocalPlayer->ViewportClient)
	{
		LocalPlayer->ViewportClient->GetMousePosition(MousePosition);
	}
	//GetOwningPlayerController()->GetMousePosition(x,y);
	return MousePosition;
}