// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/TPQuestPlugin

#pragma once

#include "Factories/Factory.h"
#include "TPQuestFactory.generated.h"

UCLASS()
class TPQUESTEDITOR_API UTPQuestFactory : public UFactory
{
	GENERATED_BODY()

public:
	UTPQuestFactory()
	{
		bCreateNew = true;
		bEditAfterNew = true;
	}

	virtual FText GetDisplayName() const override 
	{
		FText Text = Super::GetDisplayName();
		return Text.IsEmpty()
			? FText::FromName(TEXT("TPQuest Asset"))
			: Text;
	}

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override
	{
		return NewObject<UObject>(InParent, InClass, InName, Flags);
	}
};
