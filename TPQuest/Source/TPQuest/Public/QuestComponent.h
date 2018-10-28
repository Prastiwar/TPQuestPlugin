// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/

#pragma once

#include "Components/ActorComponent.h"
#include "QuestComponent.generated.h"

UCLASS(Blueprintable, BlueprintType)
class TPQUEST_API UQuestComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UQuestComponent();

	UFUNCTION(BlueprintCallable)
		void CompleteObjective(class UObjectiveBehavior* Objective);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class UQuestData* Quest;

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
