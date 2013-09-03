#include "DummySceneProvider.h"

DummySceneProvider::~DummySceneProvider(void)
{
}

Goblin::SmartPtr<Goblin::Scene> DummySceneProvider::getScene()
{
	// Create scene
	Goblin::Scene* scene = new Goblin::Scene(sf::Vector2u(10, 10), sf::Vector2f(1000.0f, 1000.0f));

	for (unsigned y = 0; y < 10; y++)
		for (unsigned x = 0; x < 10; x++)
		{
			scene->map().get(x, y).setTerrainType(rand() % 3);
		}

	// Return
	return Goblin::SmartPtr<Goblin::Scene>(scene);
}