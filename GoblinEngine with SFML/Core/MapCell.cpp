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

	GameObject& MapCell::getObject()
	{
		return *this->object;
	}

	void MapCell::setTerrainType(int value)
	{
		this->terrainType = value;
	}

	void MapCell::setHeight(float value)
	{
		this->height = value;
	}

	void MapCell::setObject(SmartPtr<GameObject> object)
	{
		this->object = object;
	}

	Object* MapCell::clone() const
	{
		return new MapCell(*this);
	}
}