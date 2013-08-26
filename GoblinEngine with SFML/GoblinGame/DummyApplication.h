#pragma once
#include "../Engine/Application.h"
#include "../Engine/RenderEngine.h"
#include "DummySceneProvider.h"
#include "DummyResourceManager.h"

/// <summary>Dummy application.</summary>
/// <remarks>An application which will be used for testing purposes only.</remarks>
class DummyApplication : public Goblin::Application
{
private:
	DummySceneProvider sceneProvider;
	DummyResourceManager resources;
	Goblin::GameController game;
	Goblin::RenderEngine renderer;

public:
	DummyApplication(void);
	virtual ~DummyApplication(void);

	virtual void onRender(sf::Time&) override;
	virtual void onLogicUpdate(sf::Time&) override;
};

