#pragma once

#include "Build.h"
#include "MapObject.h"

namespace Goblin
{

	class DLLEXPORT IMapProvider
	{
	public:

		virtual size_t getWidth() = 0;
		virtual size_t getHeight() = 0;
		virtual int getMapTerrain(size_t cell_x, size_t cell_y) = 0;
		virtual int getMapHeight(size_t cell_x, size_t cell_y) = 0;
		virtual size_t getObjectCount() = 0;
		virtual MapObject* getObject(size_t index) = 0;
	};

}