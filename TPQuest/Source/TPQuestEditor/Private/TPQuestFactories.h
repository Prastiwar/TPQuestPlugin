// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/TPQuestPlugin

#pragma once

#include "Quest.h"
#include "ObjectiveBehavior.h"
#include "QuestComponent.h"
#include "TPBlueprintFactory.h"
#include "TPQuestFactories.generated.h"

UCLASS()
class TPQUESTEDITOR_API UQuestFactory : public UTPBlueprintFactory
{
	GENERATED_BODY()

public:
	UQuestFactory()
	{
		TitleText = FText::FromName(TEXT("Pick Quest Class"));
		SupportedClass = UQuest::StaticClass();
	}
};

UCLASS()
class TPQUESTEDITOR_API UObjectiveFactory : public UTPBlueprintFactory
{
	GENERATED_BODY()

public:
	UObjectiveFactory()
	{
		TitleText = FText::FromName(TEXT("Pick Objective Behavior Class"));
		SupportedClass = UObjectiveBehavior::StaticClass();
	}
};

UCLASS()
class TPQUESTEDITOR_API UQuestComponentFactory : public UTPBlueprintFactory
{
	GENERATED_BODY()

public:
	UQuestComponentFactory()
	{
		TitleText = FText::FromName(TEXT("Pick Quest Component Class"));
		SupportedClass = UQuestComponent::StaticClass();
	}
};