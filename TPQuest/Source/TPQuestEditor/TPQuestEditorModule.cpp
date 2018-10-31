// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TPQuestEditorModule.h"
#include "AssetTypeActions.h"

FTPQuestEditorModule::FTPQuestEditorModule()
{
	TPPluginName = TEXT("TPQuest");
	TPStyleName = TEXT("TPQuestStyle");
}

void FTPQuestEditorModule::RegisterAllAssetTypeActions()
{
	RegisterAssetTypeActions(new FQuestFATA);
	RegisterAssetTypeActions(new FObjectiveBehaviorFATA);
	RegisterAssetTypeActions(new FQuestComponentFATA);
}

void FTPQuestEditorModule::SetAllClassThumbs()
{
	SetClassThumb(TEXT("Quest"));
	SetClassThumb(TEXT("ObjectiveBehavior"));
	SetClassThumb(TEXT("QuestComponent"));
}

IMPLEMENT_MODULE(FTPQuestEditorModule, TPQuestEditor)
