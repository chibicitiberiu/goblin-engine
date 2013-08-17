#pragma once
#include "../Core/Array2.h"
#include "../Core/Build.h"
#include "../Core/Player.h"
#include "../Core/IMapProvider.h"
#include "../Core/SmartPtr.h"
#include "../Core/GameObject.h"
#include "../Core/MapCell.h"
#include <vector>
#include <map>

using sf::Vector2u;

namespace Goblin
{
	class DLLEXPORT GameController : public Object
	{
	private:
		std::vector< SmartPtr<Player> >* players;
		SmartPtr<Array2< MapCell > > map;
		
	public:

		// Constructor, destructor
		GameController(void);
		virtual ~GameController(void);

		// Players
		virtual void addPlayer(SmartPtr<Player> player);
		virtual void addPlayer(Player::PlayerKind kind, std::string name, Color color);

		// Game map
		virtual void loadMap(IMapProvider& mapProvider);

		virtual Vector2u getMapSize() const;
		virtual Vector2f getCellSize() const;
		virtual MapCell& getCell(Vector2u cell);
		virtual MapCell& getCell(unsigned x, unsigned y);
		
		virtual Vector2f cellToAbsolute(Vector2u cell);
		virtual Vector2f cellToAbsolute(unsigned x, unsigned y);
		virtual Vector2u absoluteToCell(Vector2f coord);
		virtual Vector2u absoluteToCell(float x, float y);

		// Object
		virtual Object* clone() const;
	};

}