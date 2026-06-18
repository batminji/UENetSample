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
			PlayerController->S2C_KickPlayer();
		}
	}
}

void ALobbyPlayerController::S2C_KickPlayer_Implementation()
{
	UWorld* World = GetWorld();
	if (World)
	{
		GEngine->HandleDisconnect(World, World->GetNetDriver());
	}
}

void ALobbyPlayerController::C2S_SendMessage_Implementation(const FText& InMessage)
{
	for(auto It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		ALobbyPlayerController* PlayerController = Cast<ALobbyPlayerController>(It->Get());
		if(PlayerController)
		{
			PlayerController->S2C_SendMessage(InMessage);
		}
	}
}

bool ALobbyPlayerController::C2S_SendMessage_Validate(const FText& InMessage)
{
	return true;
}

void ALobbyPlayerController::S2C_SendMessage_Implementation(const FText& InMessage)
{
	if(LobbyWidget)
	{
		LobbyWidget->AddChatMessage(InMessage);
	}
}

void ALobbyPlayerController::ShowLoadingScreen()
{
	if (!HasAuthority())
	{
		return;
	}

	for(FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		ALobbyPlayerController* PlayerController = Cast<ALobbyPlayerController>(*It);
		if (PlayerController)
		{
			PlayerController->S2C_ShowLoadingScreen();
		}
	}
}

void ALobbyPlayerController::S2C_ShowLoadingScreen_Implementation()
{
	if (LoadingScreenWidgetClass)
	{
		UUserWidget* LoadingScreenWidget = CreateWidget<UUserWidget>(this, LoadingScreenWidgetClass);
		if(LoadingScreenWidget)
		{
			LoadingScreenWidget->AddToViewport();
		}
	}
}
