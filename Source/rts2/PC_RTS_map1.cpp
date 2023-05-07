// Fill out your copyright notice in the Description page of Project Settings.
#include "AIController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "PC_RTS_map1.h"
#include "CH_RTS_MoveableUnit.h"

APC_RTS_map1::APC_RTS_map1() {
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void APC_RTS_map1::BeginPlay() {
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;

	HUDPtr = Cast<AHUD_RTS_map1>(GetHUD());
}

void APC_RTS_map1::SetupInputComponent() {
	Super::SetupInputComponent();

	InputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &APC_RTS_map1::FrameSelectionPressed);
	InputComponent->BindAction("LeftMouseClick", IE_Released, this, &APC_RTS_map1::FrameSelectionReleased);

	InputComponent->BindAction("RightMouseClick", IE_Pressed, this, &APC_RTS_map1::MovePressed);
	//InputComponent->BindAction("RightMouseClick", IE_Pressed, this, &APC_RTS_map1::MovePressed);
	//InputComponent->BindAction("LeftMouseClick", IE_Released, this, &APC_RTS_map1::SelectionReleased);
}

void APC_RTS_map1::FrameSelectionPressed() {
	HUDPtr->isFrameSelecting = true;
	HUDPtr->InitalPoint = HUDPtr->GetMouusePos2D();

}

void APC_RTS_map1::FrameSelectionReleased() {
	HUDPtr->isFrameSelecting = false;
	CurSlectedUnitsGroup = HUDPtr->FoundUnits;

}

void APC_RTS_map1::MovePressed() {
	if (CurSlectedUnitsGroup.Num() > 0) {
		FHitResult Hit;
		GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, Hit);
		FVector MoveLocation = Hit.Location;

		for (int32 i = 0; i < CurSlectedUnitsGroup.Num(); i++) {
			//FVector MoveLocation = Hit.Location + FVector(i/2*10 ,i/2*10 , 0);//给予不同的目标来防止挤在一起
			//AAIController::MoveToLocation();
			
			if( ACH_RTS_MoveableUnit* MoveableUnit = Cast<ACH_RTS_MoveableUnit>(CurSlectedUnitsGroup[i]) ) {
			//auto p1 = u->GetController();
			//AAIController* p2 = UAIBlueprintHelperLibrary::GetAIController(u);
			/*AAIController* aipc =*/ //auto p = Cast<AAIController>(CurSlectedUnitsGroup[i]->GetController());
			//aipc->MoveToLocation(MoveLocation);
				UAIBlueprintHelperLibrary::SimpleMoveToLocation(MoveableUnit->GetController(), MoveLocation);
			}
		}
	}
}

//void APC_RTS_map1::PlayerTick() {
//	if (HUDPtr->isSelecting) {
//		//d;
//	}
//}





