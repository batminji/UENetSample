// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyWidgetBase.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"
#include "Animation/WidgetAnimation.h"
#include "LobbyPlayerController.h"
#include "LobbyGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void ULobbyWidgetBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
	if (StartButton)
	{
		StartButton->OnClicked.AddDynamic(this, &ULobbyWidgetBase::OnStartButtonClicked);
	}
	if (SendButton)
	{
		SendButton->OnClicked.AddDynamic(this, &ULobbyWidgetBase::OnSendButtonClicked);
	}
	if (InputText)
	{
		InputText->OnTextCommitted.AddDynamic(this, &ULobbyWidgetBase::OnInputTextCommitted);
		InputText->OnTextChanged.AddDynamic(this, &ULobbyWidgetBase::OnInputTextChanged);
	}

}

void ULobbyWidgetBase::OnStartButtonClicked()
{
	ALobbyGameModeBase* LobbyGameMode = Cast<ALobbyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (LobbyGameMode)
	{
		LobbyGameMode->StartGame();
	}
}

void ULobbyWidgetBase::OnSendButtonClicked()
{
	ALobbyPlayerController* LobbyPlayerController = Cast<ALobbyPlayerController>(GetOwningPlayer());
	if (LobbyPlayerController)
	{
		LobbyPlayerController->C2S_SendMessage(InputText->GetText());
		InputText->SetText(FText::GetEmpty());
	}
}

void ULobbyWidgetBase::OnInputTextCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
	ALobbyPlayerController* LobbyPlayerController = Cast<ALobbyPlayerController>(GetOwningPlayer());
	if(!LobbyPlayerController)
	{
		return;
	}

	switch (CommitMethod)
	{
	case ETextCommit::OnEnter:
	{
		LobbyPlayerController->C2S_SendMessage(Text);
		InputText->SetText(FText::GetEmpty());
	}
	break;
	case ETextCommit::OnCleared:
	{
		InputText->SetUserFocus(LobbyPlayerController);
	}
	break;
	}
}

void ULobbyWidgetBase::OnInputTextChanged(const FText& Text)
{
}

void ULobbyWidgetBase::UpdateLeftTime(const int32 InLeftTime)
{
	FString LeftTimeString = FString::Printf(TEXT("%d 초"), InLeftTime);
	LeftTime->SetText(FText::FromString(LeftTimeString));
}

void ULobbyWidgetBase::UpdateConnectionCount(const int32 InConnectionCount)
{
	FString ConnectionCountString = FString::Printf(TEXT("%d 명"), InConnectionCount);
	ConnectionCount->SetText(FText::FromString(ConnectionCountString));
}

void ULobbyWidgetBase::ShowStartButton()
{
	if(ShowButtonAnimation)
	{
		StartButton->SetVisibility(ESlateVisibility::Visible);
		PlayAnimation(ShowButtonAnimation);
	}
}

void ULobbyWidgetBase::AddChatMessage(const FText& InMessage)
{
	if(ChatBox)
	{
		UTextBlock* NewMessage = NewObject<UTextBlock>(ChatBox);
		if(NewMessage)
		{
			NewMessage->SetText(InMessage);
			ChatBox->AddChild(NewMessage);
			ChatBox->ScrollToEnd();
		}
	}
}
