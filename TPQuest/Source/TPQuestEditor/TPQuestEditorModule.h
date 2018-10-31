// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "TPEditor/TPEditorModule.h"

class TPQUESTEDITOR_API FTPQuestEditorModule : public FTPEditorModule
{

public:
	FTPQuestEditorModule();

	static EAssetTypeCategories::Type GetQuestCategory()
	{
		FTPQuestEditorModule& ThisModule = FModuleManager::LoadModuleChecked<FTPQuestEditorModule>(TEXT("TPQuestEditor"));
		return ThisModule.GetTypeCategory();
	}

protected:
	virtual void RegisterAllAssetTypeActions() override;
	virtual void SetAllClassThumbs() override;

};
