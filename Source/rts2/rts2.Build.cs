// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class rts2 : ModuleRules
{
	public rts2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "AIModule" });
	}
}
