#include "DummyResourceManager.h"
#include <SFML/Graphics.hpp>

DummyResourceManager::DummyResourceManager(void)
{
	// Create a resource
	sf::Image* img = new sf::Image();
	img->create(100, 100);
		
	for (unsigned i = 0; i < 100; i++)
		for (unsigned j = 0; j < 100; j++)
			img->setPixel(j, i, sf::Color(i%256, j%256, (i+j)%256));

	// Add to dictionary
	data["img"] = img;
}


DummyResourceManager::~DummyResourceManager(void)
{
	delete (sf::Image*) data["img"];
}

void* DummyResourceManager::getResource(std::string key)
{
	if (data.count(key) != 0)
		return data[key];

	return NULL;
}

bool DummyResourceManager::isLoaded(std::string key)
{
	return (data.count(key) != 0);
}

void DummyResourceManager::loadResource(std::string key, std::string filename)
{
}