// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/TPQuestPlugin

#include "QuestData.h"

UQuestData::UQuestData()
{
}

void UQuestData::InitObjectives()
{
	Objectives.Empty();
	for (TSubclassOf<UObjectiveBehavior> ObjectiveClass : ObjectiveClasses)
	{
		UObjectiveBehavior* Objective = ObjectiveClass->GetDefaultObject<UObjectiveBehavior>();
		Objective->Init();
		Objectives.Add(Objective);
	}
}
