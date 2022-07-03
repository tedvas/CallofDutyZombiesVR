// Copyright Epic Games, Inc. All Rights Reserved.

#include "RestartEngine.h"
#include "RestartEngineStyle.h"
#include "RestartEngineCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"

static const FName RestartEngineTabName("RestartEngine");

#define LOCTEXT_NAMESPACE "FRestartEngineModule"

void FRestartEngineModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FRestartEngineStyle::Initialize();
	FRestartEngineStyle::ReloadTextures();

	FRestartEngineCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FRestartEngineCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FRestartEngineModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FRestartEngineModule::RegisterMenus));
}

void FRestartEngineModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FRestartEngineStyle::Shutdown();

	FRestartEngineCommands::Unregister();
}

void FRestartEngineModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	/*FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FRestartEngineModule::PluginButtonClicked()")),
							FText::FromString(TEXT("RestartEngine.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);*/

	FUnrealEdMisc::Get().RestartEditor(false);
}

void FRestartEngineModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FRestartEngineCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FRestartEngineCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRestartEngineModule, RestartEngine)