// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/

#pragma once

#include "Engine/DataAsset.h"
#include "ObjectiveData.generated.h"

UCLASS(BlueprintType)
class TPQUEST_API UObjectiveData : public UDataAsset
{
	GENERATED_BODY()

public:
	UObjectiveData();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 CurrentProgress;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 NeededProgress;

};
