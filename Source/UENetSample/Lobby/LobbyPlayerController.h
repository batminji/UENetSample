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
	void S2C_KickPlayer();
	void S2C_KickPlayer_Implementation();

	UFUNCTION(Server, Reliable, WithValidation)
	void C2S_SendMessage(const FText& InMessage);
	void C2S_SendMessage_Implementation(const FText& InMessage);
	bool C2S_SendMessage_Validate(const FText& InMessage);

	UFUNCTION(Client, Reliable)
	void S2C_SendMessage(const FText& InMessage);
	void S2C_SendMessage_Implementation(const FText& InMessage);

	void ShowLoadingScreen();

	UFUNCTION(Client, Reliable)
	void S2C_ShowLoadingScreen();
	void S2C_ShowLoadingScreen_Implementation();

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<ULobbyWidgetBase> LobbyWidgetClass;

	UPROPERTY()
	TObjectPtr<ULobbyWidgetBase> LobbyWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> LoadingScreenWidgetClass;
};
