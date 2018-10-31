// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TPEditorModule.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleRegistry.h"

DEFINE_LOG_CATEGORY(TPEditorLog);

void FTPEditorModule::StartupModule()
{
	if (TPPluginName.IsEmpty())
	{
		return;
	}

	TSharedPtr<IPlugin> TPPlugin = IPluginManager::Get().FindPlugin(TPPluginName);
	if (!TPPlugin)
	{
		UE_LOG(TPEditorLog, Error, TEXT("Plugin not found: %s"), *TPPluginName)
		return;
	}

	const FString ContentDir = TPPlugin->GetBaseDir();
	StyleSet = MakeShareable(new FSlateStyleSet(TPStyleName));
	StyleSet->SetContentRoot(ContentDir);

	RegisterAllAssetTypeActions();
	SetAllClassThumbs();

	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet);
}

void FTPEditorModule::ShutdownModule()
{
	if (StyleSet)
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(StyleSet->GetStyleSetName());
	}
}

EAssetTypeCategories::Type FTPEditorModule::GetTypeCategory()
{
	return TypeCategory == EAssetTypeCategories::Misc ? RegisterTypeCategory() : TypeCategory;
}

EAssetTypeCategories::Type FTPEditorModule::RegisterTypeCategory()
{
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>(TEXT("AssetTools")).Get();
	TypeCategory = AssetTools.RegisterAdvancedAssetCategory(FName(*(TPPluginName + "Category")), FText::FromString(TPPluginName));
	return TypeCategory;
}

void FTPEditorModule::SetClassThumb(FString Name)
{
	const FVector2D IconSize = FVector2D(128.f, 128.f);
	const TCHAR* IconExt = TEXT(".png");
	const FString IconPath = TEXT("Resources/") + Name;

	FSlateImageBrush* Brush = new FSlateImageBrush(StyleSet->RootToContentDir(IconPath, IconExt), IconSize);
	if (Brush)
	{
		const FString ClassThumb = "ClassThumbnail.";
		StyleSet->Set(FName(*(ClassThumb + Name)), Brush);
	}
}

IMPLEMENT_MODULE(FTPEditorModule, TPEditor)
