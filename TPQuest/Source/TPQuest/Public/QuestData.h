// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/

#pragma once

#include "Engine/DataAsset.h"
#include "ObjectiveBehavior.h"
#include "QuestData.generated.h"

UCLASS(BlueprintType)
class TPQUEST_API UQuestData : public UDataAsset
{
	GENERATED_BODY()

public:
	UQuestData();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<TSubclassOf<UObjectiveBehavior>> ObjectiveClasses;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		TArray<UObjectiveBehavior*> Objectives;

};
