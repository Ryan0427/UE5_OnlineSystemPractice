// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Menu.generated.h"

/**
 * 
 */
UCLASS()
class MUULTIPLAYERSESSIONSSTEAM_API UMenu : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void MenuSetup(int32 NumberOfPublicConnections = 4, FString TypeOfMatch = FString(TEXT("FreeForAll")));

protected:

	virtual bool Initialize() override;
	virtual void NativeDestruct() override;

	//
	//Callbacks for the custom delegates on the MultiplayerSessionsSubsystem.
	//
	UFUNCTION()
	void OnCreateSession(bool bWasSuccessful);

private:


	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;


	UPROPERTY(meta = (BindWidget))
	UButton* JoinButton;

	UFUNCTION()
	void HostButtonClicked();

	UFUNCTION()
	void JoinButtonClicked();

	void MenuTearDown();


	//The subsystem designed to handle all online session functionality
	class UMultiplayerSessionSubsystem* MultiplayerSessionsSubsystem;

	int32 NumPublicConnections{ 4 };
	FString MatchType{ TEXT("FreeForAll") };
};
