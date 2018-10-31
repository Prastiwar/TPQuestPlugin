// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/

#pragma once

#include "Factories/BlueprintFactory.h"
#include "TPBlueprintFactory.generated.h"

UCLASS(Abstract)
class TPEDITOR_API UTPBlueprintFactory : public UBlueprintFactory
{
	GENERATED_BODY()
public:
	UTPBlueprintFactory();

	virtual FText GetDisplayName() const override;

	virtual bool ConfigureProperties() override;

	virtual UObject* FactoryCreateNew(
		UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;

protected:
	FText TitleText;

};
