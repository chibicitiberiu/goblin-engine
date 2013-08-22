#include "MapCell.h"

namespace Goblin
{
	MapCell::MapCell(void)
	{
	}


	MapCell::~MapCell(void)
	{
	}

	int MapCell::getTerrainType() const
	{
		return this->terrainType;
	}

	float MapCell::getHeight() const
	{
		return this->height;
	}

	void MapCell::setTerrainType(int value)
	{
		this->terrainType = value;
	}

	void MapCell::setHeight(float value)
	{
		this->height = value;
	}

	Object* MapCell::clone() const
	{
		return new MapCell(*this);
	}
}