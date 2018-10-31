// Authored by Tomasz Piowczyk. MIT License. Repository: https://github.com/Prastiwar/

#pragma once

#include "AssetTypeActions_Base.h"
#include "AssetTypeCategories.h"

class FAssetTypeActions_TPBase : public FAssetTypeActions_Base
{
public:
	FAssetTypeActions_TPBase()
	{
		Name = FText::FromName(TEXT("TP Asset"));
		Description = FText::FromName(TEXT("TP Asset"));
		Color = FColor(255, 255, 255);
		Category = EAssetTypeCategories::Misc;
	}

	virtual FText GetName() const override { return Name; }
	virtual FText GetAssetDescription(const FAssetData &AssetData) const override { return Description; }
    virtual uint32 GetCategories() override { return Category; }
    virtual FColor GetTypeColor() const override { return Color; }
    virtual UClass* GetSupportedClass() const override { return SupportedClass; }

protected:
	FText Name;
	FText Description;
	FColor Color;
	UClass* SupportedClass;
	uint32 Category;

};
