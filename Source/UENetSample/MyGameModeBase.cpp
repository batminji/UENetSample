// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPlayerController.h"
#include "MyPlayer.h"
#include "MyHUD.h"
#include "Kismet/KismetSystemLibrary.h"

AMyGameModeBase::AMyGameModeBase()
{
	PlayerControllerClass = AMyPlayerController::StaticClass();

	DefaultPawnClass = AMyPlayer::StaticClass();

	HUDClass = AMyHUD::StaticClass();
}

void AMyGameModeBase::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Begin AMyGameModeBase::PreLogin "));

	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("End AMyGameModeBase::PreLogin "));
}

APlayerController* AMyGameModeBase::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Begin AMyGameModeBase::Login "));

	APlayerController* PC = Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("End AMyGameModeBase::Login "));

	return PC;
}

void AMyGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Begin AMyGameModeBase::PostLogin "));

	Super::PostLogin(NewPlayer);

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("End AMyGameModeBase::PostLogin "));
}

void AMyGameModeBase::StartPlay()
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Begin AMyGameModeBase::StartPlay "));

	Super::StartPlay();

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("End AMyGameModeBase::StartPlay "));
}

void AMyGameModeBase::BeginPlay()
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Begin AMyGameModeBase::BeginPlay "));
	
	Super::BeginPlay();

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("End AMyGameModeBase::BeginPlay "));
}
