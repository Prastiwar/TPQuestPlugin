// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/TPQuestPlugin

#pragma once

#include "Object.h"
#include "ObjectiveBehavior.generated.h"

UCLASS(Blueprintable, BlueprintType)
class TPQUEST_API UObjectiveBehavior : public UObject
{
	GENERATED_BODY()

public:
	UObjectiveBehavior();

	UFUNCTION(BlueprintCallable)
		void AddProgress(int32 Progress);

	UFUNCTION(BlueprintCallable)
		bool IsCompleted() const;

	UFUNCTION(BlueprintCallable)
		float GetNormalizedProgress() const;

	void Tick(float DeltaTime, UQuestComponent* QuestOwner);

	virtual void Init() { ReceiveInit(); }

	// Called after Objective is completed and going to be removed from Quest
	virtual void Complete() { ReceiveComplete(); }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 NeededProgress;

	UPROPERTY(BlueprintReadOnly)
		int32 CurrentProgress;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Init"))
		void ReceiveInit();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Execute"))
		void ReceiveExecute(float DeltaTime, UQuestComponent* QuestOwner);

	// Called after Objective is completed and going to be removed from Quest
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Complete"))
		void ReceiveComplete();

	virtual void Execute(float DeltaTime, UQuestComponent* QuestOwner) { ReceiveExecute(DeltaTime, QuestOwner); }

};
