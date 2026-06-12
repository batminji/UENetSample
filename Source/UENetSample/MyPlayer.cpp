// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	FString LocalRoleString = StaticEnum<ENetRole>()->GetDisplayNameTextByValue((int64)GetLocalRole()).ToString();

	FString RemoteRoleString = StaticEnum<ENetRole>()->GetDisplayNameTextByValue((int64)GetRemoteRole()).ToString();

	UKismetSystemLibrary::PrintString(GetWorld(), FString::Printf(TEXT("Pawn LocalRole: %s, RemoteRole: %s"), *LocalRoleString, *RemoteRoleString));
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

