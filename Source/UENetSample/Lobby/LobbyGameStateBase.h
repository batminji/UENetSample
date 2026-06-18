// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "LobbyGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class UENETSAMPLE_API ALobbyGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	ALobbyGameStateBase();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void Tick(float DeltaSeconds) override;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated)
	int32 LeftTime = 180;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated)
	int32 ConnectionCount = 0;
};
