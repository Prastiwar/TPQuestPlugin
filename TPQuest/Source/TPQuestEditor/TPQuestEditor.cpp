// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TPQuestEditor.h"
#include "IPluginManager.h"
#include "ObjectiveBehaviorFATA.h"
#include "QuestDataFATA.h"

#define LOCTEXT_NAMESPACE "FTPQuestEditorModule"

void FTPQuestEditorModule::StartupModule()
{
	RegisterAssetTypeActions(new FObjectiveBehaviorFATA);
	RegisterAssetTypeActions(new FQuestDataFATA);

	FString ContentDir = IPluginManager::Get().FindPlugin("TPQuest")->GetBaseDir();
	StyleSet = MakeShareable(new FSlateStyleSet("TPQuestStyle"));

	//The image we wish to load is located inside the Resources folder inside the Base Directory
	//so let's set the content dir to the base dir and manually switch to the Resources folder:
	StyleSet->SetContentRoot(ContentDir);

	SetClassThumb(TEXT("QuestData"));
	SetClassThumb(TEXT("ObjectiveBehavior"));
	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet);
}

void FTPQuestEditorModule::ShutdownModule()
{
	if (StyleSet)
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(StyleSet->GetStyleSetName());
	}
}

void FTPQuestEditorModule::SetClassThumb(FString Name)
{
	const FVector2D IconSize = FVector2D(128.f, 128.f);
	const TCHAR* IconExt = TEXT(".png");
	const FString IconPath = TEXT("Resources/") + Name;

	FSlateImageBrush* Brush =  new FSlateImageBrush(StyleSet->RootToContentDir(IconPath, IconExt), IconSize);
	if (Brush)
	{
		const FString ClassThumb = "ClassThumbnail.";
		StyleSet->Set(FName(*(ClassThumb + Name)), Brush);
	}
}

IMPLEMENT_MODULE(FTPQuestEditorModule, TPQuestEditor)

#undef LOCTEXT_NAMESPACE
