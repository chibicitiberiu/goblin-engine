#pragma once
#include "Build.h"
#include "Array2.h"
#include "GoblinObject.h"
#include "ISerializable.h"
#include "MapObject.h"
#include <vector>

namespace Goblin {

	class DLLEXPORT MapGrid : public GoblinObject /*, public ISerializable */
	{

	private:
		
		Array2<int>* terrain;	
		Array2<MapObject*>* objects;
		Array2<int>* heightMap;

		float gridCellWidth, gridCellHeight;

		void destroy();

	protected:

		virtual void fillObjectShape(Array2<int>* shape, size_t off_x, size_t off_y, MapObject* value);

	public:

		MapGrid(size_t width, size_t height);
		MapGrid(std::string file);

		/// Checks collisions, and returns true if the object can be added to the grid.
		bool canAddObject(MapObject* object);

		/// Adds object to the grid. Doesn't check collisions, so be extra careful!!!
		void addObject(MapObject* object);

		virtual ~MapGrid();
	};

}