// Copyright Epic Games, Inc. All Rights Reserved.

#include "RestartEngineStyle.h"
#include "RestartEngine.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FRestartEngineStyle::StyleInstance = nullptr;

void FRestartEngineStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FRestartEngineStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FRestartEngineStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("RestartEngineStyle"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon128x128(128.0f, 128.0f);

TSharedRef< FSlateStyleSet > FRestartEngineStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("RestartEngineStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("RestartEngine")->GetBaseDir() / TEXT("Resources"));

	Style->Set("RestartEngine.PluginAction", new IMAGE_BRUSH(TEXT("Icon128"), Icon128x128));
	return Style;
}

void FRestartEngineStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FRestartEngineStyle::Get()
{
	return *StyleInstance;
}
