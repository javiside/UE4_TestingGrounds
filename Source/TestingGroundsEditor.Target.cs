// Copyright Javier Martinez 2017.

using UnrealBuildTool;
using System.Collections.Generic;

public class TestingGroundsEditorTarget : TargetRules
{
	public TestingGroundsEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("TestingGrounds");
	}
}
