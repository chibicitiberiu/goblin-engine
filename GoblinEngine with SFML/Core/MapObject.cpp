#include "MapObject.h"

namespace Goblin
{

	MapObject::MapObject(void)
	{
		this->components = new std::vector<Component*>();
	}


	MapObject::~MapObject(void)
	{
		delete this->components;
	}

}