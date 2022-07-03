// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "RestartEngineStyle.h"

class FRestartEngineCommands : public TCommands<FRestartEngineCommands>
{
public:

	FRestartEngineCommands()
		: TCommands<FRestartEngineCommands>(TEXT("RestartEngine"), NSLOCTEXT("Contexts", "RestartEngine", "RestartEngine Plugin"), NAME_None, FRestartEngineStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
