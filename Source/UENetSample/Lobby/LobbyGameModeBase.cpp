// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameModeBase.h"
#include "TimerManager.h"
#include "LobbyGameStateBase.h"
#include "LobbyPlayerController.h"

void ALobbyGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(
		LeftTimerHandle,
		[&]()
		{
			ALobbyGameStateBase* LobbyGameState = GetGameState<ALobbyGameStateBase>();
			if (LobbyGameState)
			{
				LobbyGameState->LeftTime--;
			}
		},
		1.0f,
		true
	);
}

void ALobbyGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorld()->GetTimerManager().ClearTimer(LeftTimerHandle);

	Super::EndPlay(EndPlayReason);
}

void ALobbyGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	CountConnection();
	UpdateGameStateCountConnection();
}

void ALobbyGameModeBase::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
	
	CountConnection();
	UpdateGameStateCountConnection();
}

void ALobbyGameModeBase::CountConnection()
{
	ConnectionCount = GetNumPlayers();
}

void ALobbyGameModeBase::UpdateGameStateCountConnection()
{
	ALobbyGameStateBase* LobbyGameState = GetGameState<ALobbyGameStateBase>();
	if (LobbyGameState)
	{
		LobbyGameState->ConnectionCount = ConnectionCount;
		LobbyGameState->OnRep_ConnectionCount();
	}
}
