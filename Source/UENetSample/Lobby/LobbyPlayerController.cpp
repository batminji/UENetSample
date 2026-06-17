// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPlayerController.h"
#include "LobbyWidgetBase.h"

void ALobbyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if(!IsLocalPlayerController())
	{
		return;
	}

	ShowLobbyWidget();
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
