// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateActor.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ARotateActor::ARotateActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;
	SetNetUpdateFrequency(3.0f);
	SetReplicateMovement(false);
}

// Called when the game starts or when spawned
void ARotateActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		AddActorLocalRotation(FRotator(0.0f, RotateSpeed * DeltaTime, 0.0f));

		ServerRotationYaw = GetActorRotation().Yaw;
	}
	else
	{
		ClientTimeSinceUpdate += DeltaTime;
		if(ClientTimeLastUpdate < KINDA_SMALL_NUMBER)
		{
			return;
		}

		float CalculateRotationYaw = ServerRotationYaw + RotateSpeed * ClientTimeSinceUpdate;
		float LerpAlpha = ClientTimeSinceUpdate / ClientTimeLastUpdate;
		float ClientNewRotationYaw = FMath::Lerp(ServerRotationYaw, CalculateRotationYaw, LerpAlpha);

		SetActorRotation(FRotator(0.0f, ClientNewRotationYaw, 0.0f));
	}
}

void ARotateActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ARotateActor, ServerRotationYaw);
}

void ARotateActor::OnRep_ServerRotationYaw()
{
	SetActorRotation(FRotator(0.0f, ServerRotationYaw, 0.0f));

	ClientTimeLastUpdate = ClientTimeSinceUpdate;
	ClientTimeSinceUpdate = 0.0f;
}

