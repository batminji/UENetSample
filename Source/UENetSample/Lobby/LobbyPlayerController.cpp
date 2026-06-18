// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPlayerController.h"
#include "LobbyWidgetBase.h"
#include "Kismet/GameplayStatics.h"
#include "LobbyGameModeBase.h"
#include "LobbyGameStateBase.h"

void ALobbyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if(!IsLocalPlayerController())
	{
		return;
	}

	ShowLobbyWidget();
	UpdateConnectionCount();
}

void ALobbyPlayerController::ShowLobbyWidget()
{
	if (LobbyWidgetClass)
	{
		LobbyWidget = CreateWidget<ULobbyWidgetBase>(this, LobbyWidgetClass);
		if (LobbyWidget)
		{
			LobbyWidget->AddToViewport();

			if (HasAuthority())
			{
				LobbyWidget->ShowStartButton();
			}
		}
	}
}

void ALobbyPlayerController::UpdateConnectionCount()
{
	ALobbyGameStateBase* LobbyGameState = GetWorld()->GetGameState<ALobbyGameStateBase>();
	if(LobbyGameState && LobbyWidget)
	{
		LobbyWidget->UpdateConnectionCount(LobbyGameState->ConnectionCount);
	}
}

void ALobbyPlayerController::KickPlayer()
{
	for(FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		ALobbyPlayerController* PlayerController = Cast<ALobbyPlayerController>(*It);
		if(PlayerController && PlayerController != this)
		{
			PlayerController->ClientTravel(TEXT("/Game/Maps/Step01"), TRAVEL_Absolute);
		}
	}
}
