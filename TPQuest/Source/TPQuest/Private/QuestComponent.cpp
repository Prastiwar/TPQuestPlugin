// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/TPQuestPlugin

#include "QuestComponent.h"
#include "QuestData.h"
#include "ObjectiveBehavior.h"

UQuestComponent::UQuestComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UQuestComponent::BeginPlay()
{
	Super::BeginPlay();
	for (auto ObjectiveClass : Quest->ObjectiveClasses)
	{
		UObjectiveBehavior* Objective = ObjectiveClass->GetDefaultObject<UObjectiveBehavior>();
		Objective->Init();
		Quest->Objectives.Add(Objective);
	}
}

void UQuestComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	for (int32 Index = Quest->Objectives.Num() - 1; Index >= 0; Index--)
	{
		Quest->Objectives[Index]->Tick(DeltaTime, this);
	}
}

void UQuestComponent::CompleteObjective(class UObjectiveBehavior* Objective)
{
	Objective->Complete();
	Quest->Objectives.RemoveSingle(Objective);
}
