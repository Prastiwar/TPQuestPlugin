// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/TPQuestPlugin

#pragma once

#include "Factories/BlueprintFactory.h"
#include "TPQuestBlueprintFactory.generated.h"

UCLASS()
class TPQUESTEDITOR_API UTPQuestBlueprintFactory : public UBlueprintFactory
{
	GENERATED_BODY()
public:
	UTPQuestBlueprintFactory();

	virtual bool ConfigureProperties() override;
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	
protected:
	FText TitleText;
};