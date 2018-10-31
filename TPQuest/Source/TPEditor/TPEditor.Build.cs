// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TPEditor : ModuleRules
{
    public TPEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        MinFilesUsingPrecompiledHeaderOverride = 1;
        bFasterWithoutUnity = true;

        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        bEnforceIWYU = true;

        PublicDependencyModuleNames.AddRange(new string[]{
            "Core", "CoreUObject", "Engine", "AssetTools", "Slate", "ClassViewer", "UnrealEd", "Kismet", "KismetCompiler"
        });

        PrivateDependencyModuleNames.AddRange(new string[]{
            "CoreUObject", "Engine", "Projects", "AssetTools", "Slate", "SlateCore", "UnrealEd", "Kismet", "KismetCompiler"
        });

        PrivateIncludePathModuleNames.AddRange(new string[]{
            "TPEditor"
        });
    }
}
