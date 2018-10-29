// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/TPQuestPlugin

#pragma once

#include "Object.h"
#include "ObjectiveBehavior.generated.h"

UENUM(BlueprintType)
enum class EObjectiveResult : uint8
{
	Succeed,
	InProgress,
	Failed
};

UCLASS(Blueprintable, BlueprintType)
class TPQUEST_API UObjectiveBehavior : public UObject
{
	GENERATED_BODY()

public:
	UObjectiveBehavior();

	UFUNCTION(BlueprintCallable, Category = Quest)
		void AddProgress(int32 Progress);

	UFUNCTION(BlueprintCallable, Category = Quest)
		float GetNormalizedProgress() const;

	virtual void Init() { ReceiveInit(); }

	// Called after Objective is completed and going to be removed from Quest
	virtual void Complete(const bool bSucceed) { ReceiveComplete(bSucceed); }

	virtual EObjectiveResult Execute(float DeltaTime, UQuest* Owner, UQuestComponent* QuestOwner) { return ReceiveExecute(DeltaTime, Owner, QuestOwner); }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
		FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
		FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
		int32 NeededProgress;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Quest)
		int32 CurrentProgress;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Init"))
		void ReceiveInit();

	// Called after Objective is completed and going to be removed from Quest
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Complete"))
		void ReceiveComplete(const bool bSucceed);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Execute"))
		EObjectiveResult ReceiveExecute(float DeltaTime, UQuest* Owner, UQuestComponent* QuestOwner);

};
