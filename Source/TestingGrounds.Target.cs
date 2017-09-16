// Copyright Javier Martinez 2017.

using UnrealBuildTool;
using System.Collections.Generic;

public class TestingGroundsTarget : TargetRules
{
	public TestingGroundsTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("TestingGrounds");
	}
}
