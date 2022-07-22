// Copyright Epic Games, Inc. All Rights Reserved.

#include "RestartEngineCommands.h"

#define LOCTEXT_NAMESPACE "FRestartEngineModule"

void FRestartEngineCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "RestartEngine", "Restart Unreal Engine", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
