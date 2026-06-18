// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LobbyPlayerController.generated.h"

class ULobbyWidgetBase;

UCLASS()
class UENETSAMPLE_API ALobbyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	void ShowLobbyWidget();

	void UpdateConnectionCount();

	UFUNCTION(BlueprintCallable)
	void KickPlayer();

	UFUNCTION(Client, Reliable)
	void Client_KickPlayer();
	void Client_KickPlayer_Implementation();

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<ULobbyWidgetBase> LobbyWidgetClass;

	UPROPERTY()
	TObjectPtr<ULobbyWidgetBase> LobbyWidget;
};
