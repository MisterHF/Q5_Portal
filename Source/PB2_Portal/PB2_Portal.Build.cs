// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PB2_Portal : ModuleRules
{
	public PB2_Portal(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
