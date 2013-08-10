#pragma once
#include "../Core/Build.h"
#include "../Core/Player.h"
#include "../Core/MapGrid.h"
#include "../Core/IMapProvider.h"

#include <vector>

namespace Goblin
{
	class DLLEXPORT GameController
	{
	private:
		std::vector<Player*>* players;
		MapGrid* map;

	public:

		// Constructor, destructor
		GameController(void);
		virtual ~GameController(void);

		// Players
		virtual void addPlayer(Player* player);
		virtual void addPlayer(Player::PlayerKind kind, std::string name, Color color);

		// Game map
		virtual size_t getMapWidth() const;
		virtual size_t getMapHeight() const;
		virtual int getMapTerrain(size_t cell_x, size_t cell_y) const;
		virtual int getMapHeight(size_t cell_x, size_t cell_y) const;
		virtual MapObject* getMapObject(size_t cell_x, size_t cell_y) const;

		virtual void loadMap(IMapProvider* mapProvider);
	};

}