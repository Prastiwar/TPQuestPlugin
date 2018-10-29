// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/TPQuestPlugin

#include "ObjectiveBehavior.h"
#include "QuestComponent.h"

UObjectiveBehavior::UObjectiveBehavior()
{
	CurrentProgress = 0;
	NeededProgress = 1;
}

void UObjectiveBehavior::AddProgress(int32 Progress)
{
	CurrentProgress += Progress;
}

float UObjectiveBehavior::GetNormalizedProgress() const
{
	return (float)CurrentProgress / (float)NeededProgress;
}
