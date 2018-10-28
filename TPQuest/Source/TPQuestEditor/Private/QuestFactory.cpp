// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/TPQuestPlugin

#include "QuestFactory.h"
#include "TPQuestEditor.h"
#include "QuestData.h"

UQuestFactory::UQuestFactory()
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UQuestData::StaticClass();
}

UObject* UQuestFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UQuestData>(InParent, InClass, InName, Flags);
}
