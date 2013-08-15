#include "MapGrid.h"
#include "SmartPtr.h"

namespace Goblin
{
	MapGrid::MapGrid(size_t width, size_t height)
		: terrain(NULL), objects(NULL), gridCellWidth(1.0f), gridCellHeight(1.0f)
	{
		// Create terrain
		this->terrain = new Array2<int>(width, height);

		// Create object array
		this->objects = new Array2< SmartPtr<MapObject> >(width, height);
	}

	MapGrid::MapGrid(std::string file)
		: terrain(NULL), objects(NULL), gridCellWidth(1.0f), gridCellHeight(1.0f)
	{
	}

	MapGrid::~MapGrid(void)
	{
		this->destroy();
	}

	void MapGrid::destroy(void)
	{
		// Delete terrain
		if (this->terrain != NULL)
			delete this->terrain;

		// Delete objects
		if (this->objects != NULL)
			delete this->objects;
	}

	void MapGrid::fillObjectShape(Array2<int>* shape, size_t off_x, size_t off_y, MapObject* value)
	{
		for (size_t y = 0; y < shape->getHeight(); y++)
			for (size_t x = 0; x < shape->getWidth(); x++)
			{
				if (shape->get(x, y) != 0)
					this->objects->set(x + off_y, y + off_y, value);
			}
	}

	bool MapGrid::canAddObject(MapObject* object)
	{
		Array2<int>* shape = object->getShape();

		for (size_t y = 0; y < shape->getHeight(); y++)
			for (size_t x = 0; x < shape->getWidth(); x++)
			{
				size_t off_x = x /*+ object->getCellX()*/;
				size_t off_y = y /*+ object->getCellX()*/;

				if (shape->get(x, y) != 0 && this->objects->get(off_x, off_y) != NULL)
					return false;
			}

		return true;
	}

	void MapGrid::addObject(MapObject* object)
	{
		this->fillObjectShape(object->getShape(), 0 /*object->getCellX()*/, 0 /*object->getCellY()*/, object);
	}
}

