#pragma once

#include "Build.h"
#include "GameObject.h"
#include <SFML/Graphics.hpp>

using sf::Vector2u;
using sf::Vector2f;

namespace Goblin
{

	class DLLEXPORT IMapProvider
	{
	public:

		virtual Vector2u getSize() = 0;
		virtual Vector2f getCellSize() = 0;
		virtual int getMapTerrain(size_t cell_x, size_t cell_y) = 0;
		virtual int getMapHeight(size_t cell_x, size_t cell_y) = 0;
		virtual size_t getObjectCount() = 0;
		virtual SmartPtr<GameObject> getObject(size_t index) = 0;
	};

}