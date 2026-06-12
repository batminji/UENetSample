// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Kismet/KismetSystemLibrary.h"

void AMyHUD::BeginPlay()
{
	Super::BeginPlay();

	FString LocalRoleString = StaticEnum<ENetRole>()->GetDisplayNameTextByValue((int64)GetLocalRole()).ToString();

	FString RemoteRoleString = StaticEnum<ENetRole>()->GetDisplayNameTextByValue((int64)GetRemoteRole()).ToString();

	UKismetSystemLibrary::PrintString(GetWorld(), FString::Printf(TEXT("Pawn LocalRole: %s, RemoteRole: %s"), *LocalRoleString, *RemoteRoleString));
}