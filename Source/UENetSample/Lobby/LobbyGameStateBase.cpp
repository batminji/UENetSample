// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameStateBase.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "LobbyPlayerController.h"
#include "LobbyWidgetBase.h"

ALobbyGameStateBase::ALobbyGameStateBase()
{
	PrimaryActorTick.bCanEverTick = true;
	LeftTime = 180;
}

void ALobbyGameStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ALobbyGameStateBase, LeftTime);
	DOREPLIFETIME(ALobbyGameStateBase, ConnectionCount);
}

void ALobbyGameStateBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	ALobbyPlayerController* PlayerController = Cast<ALobbyPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (PlayerController && PlayerController->IsLocalPlayerController() && PlayerController->LobbyWidget)
	{
		PlayerController->LobbyWidget->UpdateLeftTime(LeftTime);
		PlayerController->LobbyWidget->UpdateConnectionCount(ConnectionCount);
	}
}
