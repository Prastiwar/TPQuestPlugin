// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/TPQuestPlugin

#include "Quest.h"
#include "ObjectiveBehavior.h"

UQuest::UQuest()
{
}

void UQuest::Begin()
{
	ReceiveBegin();
	InitObjectives();
}

void UQuest::Complete(const bool bSucceeded)
{
	ReceiveComplete(bSucceeded);
	bIsCompleted = true;
}

void UQuest::InitObjectives()
{
	Objectives.Empty();
	for (TSubclassOf<UObjectiveBehavior> ObjectiveClass : ObjectiveClasses)
	{
		UObjectiveBehavior* Objective = ObjectiveClass->GetDefaultObject<UObjectiveBehavior>();
		Objective->Init();
		Objectives.Add(Objective);
	}
}
