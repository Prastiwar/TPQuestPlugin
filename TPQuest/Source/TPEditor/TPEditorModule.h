// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"
#include "IAssetTools.h"
#include "AssetToolsModule.h"
#include "AssetTypeCategories.h"
#include "Styling/SlateStyle.h"

DECLARE_LOG_CATEGORY_EXTERN(TPEditorLog, Log, All);

class TPEDITOR_API FTPEditorModule : public IModuleInterface
{

public:
	// IModuleInterface implementation
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	////////////////////////////////////

protected:
	FName TPStyleName;
	FString TPPluginName;
	TSharedPtr<FSlateStyleSet> StyleSet;
	EAssetTypeCategories::Type TypeCategory = EAssetTypeCategories::Misc;

	virtual void RegisterAllAssetTypeActions() {}
	virtual void SetAllClassThumbs() {}

	EAssetTypeCategories::Type GetTypeCategory();
	EAssetTypeCategories::Type RegisterTypeCategory();

	// Set Class Thumbnail - Name is name of icon AND name of class
	void SetClassThumb(FString Name);
	
	template<class ObjectType>
	void RegisterAssetTypeActions(ObjectType* InObject)
	{
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
		TSharedRef<IAssetTypeActions> ATA = MakeShareable(InObject);
		AssetTools.RegisterAssetTypeActions(ATA);
	}

};
