#include "DummyApplication.h"


DummyApplication::DummyApplication(void)
	: game(sceneProvider), renderer(resources, game.scene(), 0)
{
}


DummyApplication::~DummyApplication(void)
{
}

void DummyApplication::onRender(sf::Time& t)
{
	renderer.render(mainWindow);

	Application::onRender(t);
}

void DummyApplication::onLogicUpdate(sf::Time& t)
{
	game.tick(t);

	Application::onLogicUpdate(t);
}