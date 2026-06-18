// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameModeBase.h"
#include "TimerManager.h"
#include "LobbyGameStateBase.h"

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
