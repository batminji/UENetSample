// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotateActor.generated.h"

UCLASS()
class UENETSAMPLE_API ARotateActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotateActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	void OnRep_ServerRotationYaw();

protected:
	UPROPERTY(ReplicatedUsing = OnRep_ServerRotationYaw)
	float ServerRotationYaw = 0.0f;

	float RotateSpeed = 60.0f;

	float ClientTimeSinceUpdate = 0.0f;			// 클라이언트에서 매 틱마다 회전한 시간 (서버에서 값을 받은 뒤로)

	float ClientTimeLastUpdate = 0.0f;			// 서버에서 이전에 값을 보내준 시간

};
