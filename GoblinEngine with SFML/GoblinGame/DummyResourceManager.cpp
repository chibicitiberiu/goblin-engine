#include "DummyResourceManager.h"
#include <SFML/Graphics.hpp>

DummyResourceManager::DummyResourceManager(void)
{
	// Create a resource
	sf::Image* img1 = new sf::Image();
	sf::Image* img2 = new sf::Image();
	sf::Image* img3 = new sf::Image();
	img1->create(100, 100);
	img2->create(100, 100);
	img3->create(100, 100);
		
	for (unsigned i = 0; i < 100; i++)
		for (unsigned j = 0; j < 100; j++)
		{
			img1->setPixel(j, i, sf::Color(i%256, j%256, (i+j)%256));
			img2->setPixel(j, i, sf::Color(i%256, (i+j)%256, j%256));
			img3->setPixel(j, i, sf::Color((i+j)%256, i%256, j%256));
		}

	// Add to dictionary
	data["terrain0"] = img1;
	data["terrain1"] = img2;
	data["terrain2"] = img3;
}

DummyResourceManager::~DummyResourceManager(void)
{
	delete (sf::Image*) data["terrain0"];
	delete (sf::Image*) data["terrain1"];
	delete (sf::Image*) data["terrain2"];
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