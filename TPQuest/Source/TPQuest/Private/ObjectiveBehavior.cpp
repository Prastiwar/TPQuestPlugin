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

bool UObjectiveBehavior::IsCompleted() const
{
	return CurrentProgress >= NeededProgress;
}

float UObjectiveBehavior::GetNormalizedProgress() const
{
	return (float)CurrentProgress / (float)NeededProgress;
}

void UObjectiveBehavior::Tick(float DeltaTime, UQuestComponent* QuestOwner)
{
	Execute(DeltaTime, QuestOwner);
	if (IsCompleted())
	{
		Complete();
		QuestOwner->CompleteObjective(this);
	}
}
