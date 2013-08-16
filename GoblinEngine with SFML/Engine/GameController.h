#pragma once
#include "../Core/Array2.h"
#include "../Core/Build.h"
#include "../Core/Player.h"
#include "../Core/IMapProvider.h"
#include "../Core/SmartPtr.h"
#include "../Core/GameObject.h"
#include <vector>
#include <map>

using sf::Vector2u;

namespace Goblin
{
	class DLLEXPORT GameController : public Object
	{
	private:
		std::vector< SmartPtr<Player> >* players;
		SmartPtr<Array2< SmartPtr<GameObject> > > objects;
		SmartPtr<Array2<int> > terrain;
		
	public:

		// Constructor, destructor
		GameController(void);
		virtual ~GameController(void);

		// Players
		virtual void addPlayer(SmartPtr<Player> player);
		virtual void addPlayer(Player::PlayerKind kind, std::string name, Color color);

		// Game map
		virtual void loadMap(IMapProvider& mapProvider);

		//virtual Vector2u getMapSize() const;
		//virtual int getMapTerrain(size_t cell_x, size_t cell_y) const;
		//virtual int getMapHeight(size_t cell_x, size_t cell_y) const;

		
		// Object
		virtual Object* clone() const;
	};

}