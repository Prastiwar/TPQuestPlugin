// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/TPQuestPlugin

#pragma once

#include "AssetTypeActions_Base.h"
#include "ObjectiveBehavior.h"
#include "TPQuestEditor.h"

class TPQUESTEDITOR_API FObjectiveBehaviorFATA : public FAssetTypeActions_Base
{

public:
    virtual FText GetName() const override { return FText::FromName(TEXT("Objective Behavior Blueprint")); }
    virtual uint32 GetCategories() override { return FTPQuestEditorModule::GetQuestCategory(); }
    virtual FColor GetTypeColor() const override { return FColor(100, 150, 255); }
    virtual FText GetAssetDescription(const FAssetData &AssetData) const override { return FText::FromName(TEXT("Quest Objective(Task) Behavior Blueprint")); }
    virtual UClass* GetSupportedClass() const override { return UObjectiveBehavior::StaticClass(); }

};
