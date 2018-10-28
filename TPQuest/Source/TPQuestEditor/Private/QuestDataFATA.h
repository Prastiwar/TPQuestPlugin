// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/

#pragma once

#include "AssetTypeActions_Base.h"
#include "QuestData.h"
#include "TPQuestEditor.h"

class TPQUESTEDITOR_API FQuestDataFATA : public FAssetTypeActions_Base
{

public:
    virtual FText GetName() const override { return FText::FromName(TEXT("Quest Data Asset")); }
    virtual uint32 GetCategories() override { return FTPQuestEditorModule::GetQuestCategory(); }
    virtual FColor GetTypeColor() const override { return FColor(255, 70, 70); }
    virtual FText GetAssetDescription(const FAssetData &AssetData) const override { return FText::FromName(TEXT("Quest Data Asset holds all information about quest and his objectives")); }
    virtual UClass* GetSupportedClass() const override { return UQuestData::StaticClass(); }

};
