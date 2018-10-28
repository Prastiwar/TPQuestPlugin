// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/

#pragma once

#include "Factories/Factory.h"
#include "QuestFactory.generated.h"

UCLASS()
class TPQUESTEDITOR_API UQuestFactory : public UFactory
{
	GENERATED_BODY()

public:
	UQuestFactory();

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;

};
