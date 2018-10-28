// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/

#include "ObjectiveFactory.h"
#include "TPQuestEditor.h"
#include "KismetCompilerModule.h"
#include "KismetEditorUtilities.h"
#include "Editor/UnrealEd/Public/Kismet2/SClassPickerDialog.h"
#include "ObjectiveBehavior.h"

UObjectiveFactory::UObjectiveFactory()
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UObjectiveBehavior::StaticClass();
}

bool UObjectiveFactory::ConfigureProperties()
{
	ParentClass = nullptr;

	TSharedPtr<FObjectiveBehaviorFilterViewer> Filter = MakeShareable<FObjectiveBehaviorFilterViewer>(new FObjectiveBehaviorFilterViewer);
	Filter->DisallowedClassFlags = CLASS_Abstract | CLASS_Deprecated;
	Filter->AllowedChildrenOfClasses.Add(UObjectiveBehavior::StaticClass());
	
	FClassViewerInitializationOptions Options;
	Options.Mode = EClassViewerMode::ClassPicker;
	Options.ClassFilter = Filter;

	const FText TitleText = FText::FromName(TEXT("Pick Objective Behavior Class"));
	UClass* ChosenClass = nullptr;

	const bool bPressedOk = SClassPickerDialog::PickClass(TitleText, Options, ChosenClass, UObjectiveBehavior::StaticClass());
	if (bPressedOk)
	{
		ParentClass = ChosenClass;
	}
	return bPressedOk;
}

UObject* UObjectiveFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	if (ParentClass && FKismetEditorUtilities::CanCreateBlueprintOfClass(ParentClass))
	{
		UClass* BlueprintClass = nullptr;
		UClass* BlueprintGeneratedClass = nullptr;
		IKismetCompilerInterface& KismetCompilerModule = FModuleManager::LoadModuleChecked<IKismetCompilerInterface>("KismetCompiler");
		KismetCompilerModule.GetBlueprintTypesForClass(ParentClass, BlueprintClass, BlueprintGeneratedClass);
		return FKismetEditorUtilities::CreateBlueprint(ParentClass, InParent, Name, BPTYPE_Normal, BlueprintClass, BlueprintGeneratedClass, CallingContext);
	}
	return nullptr;
}
