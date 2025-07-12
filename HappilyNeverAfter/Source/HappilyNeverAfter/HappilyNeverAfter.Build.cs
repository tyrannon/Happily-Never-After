// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HappilyNeverAfter : ModuleRules
{
	public HappilyNeverAfter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"HappilyNeverAfter",
			"HappilyNeverAfter/Variant_Platforming",
			"HappilyNeverAfter/Variant_Combat",
			"HappilyNeverAfter/Variant_Combat/AI",
			"HappilyNeverAfter/Variant_SideScrolling",
			"HappilyNeverAfter/Variant_SideScrolling/Gameplay",
			"HappilyNeverAfter/Variant_SideScrolling/AI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
