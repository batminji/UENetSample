// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyWidgetBase.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"
#include "Animation/WidgetAnimation.h"

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
}

void ULobbyWidgetBase::OnSendButtonClicked()
{
	
}

void ULobbyWidgetBase::OnInputTextCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
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
