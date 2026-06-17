// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyWidgetBase.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"

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
}

void ULobbyWidgetBase::UpdateConnectionCount(const int32 InConnectionCount)
{
}
