// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/TPQuestPlugin

#pragma once

#include "AssetTypeActions_TPBase.h"
#include "TPQuestEditorModule.h"
#include "Quest.h"
#include "ObjectiveBehavior.h"
#include "QuestComponent.h"

class TPQUESTEDITOR_API FQuestFATA : public FAssetTypeActions_TPBase
{
public:
	FQuestFATA()
	{
		Name = FText::FromName(TEXT("Quest Blueprint"));
		Description = FText::FromName(TEXT("Quest Data Asset holds all information about quest and his objectives"));
		Color = FColor(255, 70, 70);
		SupportedClass = UQuest::StaticClass();
		Category = FTPQuestEditorModule::GetQuestCategory();
	}
};

class TPQUESTEDITOR_API FObjectiveBehaviorFATA : public FAssetTypeActions_TPBase
{
public:
	FObjectiveBehaviorFATA()
	{
		Name = FText::FromName(TEXT("Objective Behavior Blueprint"));
		Description = FText::FromName(TEXT("Quest Objective(Task) Behavior Blueprint"));
		Color = FColor(100, 150, 255);
		SupportedClass = UObjectiveBehavior::StaticClass();
		Category = FTPQuestEditorModule::GetQuestCategory();
	}
};

class TPQUESTEDITOR_API FQuestComponentFATA : public FAssetTypeActions_TPBase
{
public:
	FQuestComponentFATA()
	{
		Name = FText::FromName(TEXT("Quest Component"));
		Description = FText::FromName(TEXT("Quest Component runs objectives from Quest"));
		Color = FColor(125, 255, 125);
		SupportedClass = UQuestComponent::StaticClass();
		Category = FTPQuestEditorModule::GetQuestCategory();
	}
};
