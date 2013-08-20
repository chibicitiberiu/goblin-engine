#include "GameController.h"
#include "../Core/MapEntityComponent.h"
#include "../Core/Clamp.h"
#include <SFML/Graphics.hpp>
#include <cassert>
#include <algorithm>

namespace Goblin
{
	GameController::GameController(unsigned width, unsigned height) 
	{
		cellSize = Vector2f(1.0f, 1.0f);
		mapSize = Vector2u(width, height);
		map = new MapType(width, height);
		initialize();
	}

	GameController::GameController(IMapProvider& mapProvider)
	{
		cellSize = mapProvider.getCellSize();
		mapSize = mapProvider.getSize();
		map = new MapType(mapSize.x, mapSize.y);
		initialize();
	}

	void GameController::initialize()
	{	
		// Create containers
		players = new PlayersContainer();
		objects = new ObjectsContainer();
		selectedObjects = new SelectedObjectsContainer();
	}

	GameController::~GameController(void)
	{
		delete players;
		delete objects;
		delete selectedObjects;
		delete map;
	}

	unsigned GameController::toObjectIndex(Vector2u pos)
	{
		return pos.x + pos.y * mapSize.x;
	}

	void GameController::addPlayer(SmartPtr<Player> player)
	{
		this->players->push_back(player);
	}

	void GameController::addPlayer(Player::PlayerKind kind, std::string name, Color color)
	{
		Player* player = new Player(kind, name, color);
		this->players->push_back(SmartPtr<Player>(player));
	}

	Vector2u GameController::getMapSize() const
	{
		return Vector2u(map->getWidth(), map->getHeight());
	}

	Vector2f GameController::getCellSize() const
	{
		return this->cellSize;
	}

	MapCell& GameController::getCell(Vector2u cell)
	{
		return map->get(cell.x, cell.y);
	}

	MapCell& GameController::getCell(unsigned x, unsigned y)
	{
		return map->get(x, y);
	}
		
	Vector2f GameController::cellToAbsolute(Vector2u cell)
	{
		float xx = static_cast<float>(cell.x) * cellSize.x;
		float yy = static_cast<float>(cell.y) * cellSize.y;
		return Vector2f(xx, yy);
	}

	Vector2f GameController::cellToAbsolute(unsigned x, unsigned y)
	{
		float xx = static_cast<float>(x) * cellSize.x;
		float yy = static_cast<float>(y) * cellSize.y;
		return Vector2f(xx, yy);
	}

	Vector2u GameController::absoluteToCell(Vector2f coord)
	{
		unsigned xx = static_cast<unsigned> (coord.x / cellSize.x);
		unsigned yy = static_cast<unsigned> (coord.y / cellSize.y);
		return Vector2u(xx, yy);
	}

	Vector2u GameController::absoluteToCell(float x, float y)
	{
		unsigned xx = static_cast<unsigned> (x / cellSize.x);
		unsigned yy = static_cast<unsigned> (y / cellSize.y);
		return Vector2u(xx, yy);
	}

	void GameController::select(bool add_to_selection, FloatRect area_absolute)
	{
		// Get corresponding eclls
		Vector2u topLeft = absoluteToCell(area_absolute.left, area_absolute.top);
		Vector2u size = absoluteToCell(area_absolute.width, area_absolute.height);

		// Clear selection?
		if (!add_to_selection)
			selectedObjects->clear();

		// Add objects to selection
		Vector2u v;
		for (v.y = topLeft.y; v.y <= topLeft.y + size.y; v.y++)
			for (v.x = topLeft.x; v.x <= topLeft.x + size.x; v.x++)
			{
				// Convert position to index
				unsigned i = toObjectIndex(v);

				// For each object in this cell
				for (auto it = objects->lower_bound(i); it != objects->upper_bound(i); it++)
				{
					// Get absolute position
					MapEntityComponent* mec = it->second->tryGetComponent<MapEntityComponent>();

					if (mec != NULL)
					{
						Vector2f pos = mec->getAbsolutePosition();
					
						// If inside selection and not already selected
						if (area_absolute.contains(pos) && (std::count(selectedObjects->begin(), selectedObjects->end(), it->second) == 0))
						{
							// Select
							selectedObjects->push_back(it->second);
						}
					}
				}
			}
	}

	void GameController::move(Vector2f dest)
	{
	}

	void GameController::tick(sf::Time elapsed)
	{
	}

	Object* GameController::clone() const
	{
		return new GameController(*this);
	}
}