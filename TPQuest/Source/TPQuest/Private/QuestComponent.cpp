// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/TPQuestPlugin

#include "QuestComponent.h"
#include "ObjectiveBehavior.h"

UQuestComponent::UQuestComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UQuestComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UQuestComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	for (int32 QuestIndex = Quests.Num() - 1; QuestIndex >= 0; QuestIndex--)
	{
		bool bQuestCompleted = true;

		for (int32 ObjectiveIndex = Quests[QuestIndex]->Objectives.Num() - 1; ObjectiveIndex >= 0; ObjectiveIndex--)
		{
			EObjectiveResult Result = Quests[QuestIndex]->Objectives[ObjectiveIndex]->Execute(DeltaTime, Quests[QuestIndex], this);
			if (Result == EObjectiveResult::InProgress)
			{
				bQuestCompleted = false;
			}
			else
			{
				Quests[QuestIndex]->Objectives[ObjectiveIndex]->Complete(Result == EObjectiveResult::Succeed);
				Quests[QuestIndex]->Objectives.RemoveAtSwap(ObjectiveIndex);
			}
		}

		if (bQuestCompleted && !Quests[QuestIndex]->IsCompleted())
		{
			Quests[QuestIndex]->Complete(true);
			Quests.RemoveAtSwap(QuestIndex);
		}
	}
}

void UQuestComponent::AddQuest(UQuest* Quest)
{
	Quest->Begin();
	Quests.Add(Quest);
}
