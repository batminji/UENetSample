// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Kismet/KismetSystemLibrary.h"

AMyPlayerController::AMyPlayerController()
{
}

void AMyPlayerController::OnPossess(APawn* InPawn)
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Begin AMyPlayerController::OnPossess "));

	Super::OnPossess(InPawn);

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("End AMyPlayerController::OnPossess "));
}

void AMyPlayerController::BeginPlay()
{
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Begin AMyPlayerController::BeginPlay "));

	Super::BeginPlay();

	FString LocalRoleString = StaticEnum<ENetRole>()->GetDisplayNameTextByValue((int64)GetLocalRole()).ToString();

	FString RemoteRoleString = StaticEnum<ENetRole>()->GetDisplayNameTextByValue((int64)GetRemoteRole()).ToString();

	UKismetSystemLibrary::PrintString(GetWorld(), FString::Printf(TEXT("LocalRole: %s, RemoteRole: %s"), *LocalRoleString, *RemoteRoleString));

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("End AMyPlayerController::BeginPlay "));
}
