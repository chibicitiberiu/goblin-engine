#include "DummySceneProvider.h"

DummySceneProvider::~DummySceneProvider(void)
{
}

Goblin::SmartPtr<Goblin::Scene> DummySceneProvider::getScene()
{
	// Create scene
	Goblin::Scene* scene = new Goblin::Scene(sf::Vector2u(100, 100), sf::Vector2f(100.0f, 100.0f));

	// Return
	return Goblin::SmartPtr<Goblin::Scene>(scene);
}