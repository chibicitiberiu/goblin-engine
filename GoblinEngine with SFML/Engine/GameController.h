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
#include <list>

using sf::Vector2u;
using sf::FloatRect;
typedef sf::Rect<unsigned> UIntRect;

namespace Goblin
{
	class DLLEXPORT GameController : public Object
	{
	private:

		// List of players in current game.
		typedef std::vector<SmartPtr<Player> > PlayersContainer;
		PlayersContainer* players;
		
		// Game map. A bidimensional array.
		typedef Array2<MapCell> MapType;
		MapType* map;

		// Object map. To each cell can correspond one or more objects, so we use a multi-dictionary.
		typedef std::multimap<unsigned, SmartPtr<GameObject> > ObjectsContainer;
		ObjectsContainer* objects;
		
		unsigned toObjectIndex(Vector2u pos);

		// Action queue
		struct ActionQueueItem {
			SmartPtr<GameObject> object;
			SmartPtr<Action> action;
			SmartPtr<Action> dependsOn;
		};

		typedef std::list<ActionQueueItem> ActionQueueContainer;
		ActionQueueContainer* actionQueue;

		// Absolute size of one cell
		Vector2u mapSize;
		Vector2f cellSize;

		void initialize();

	public:

		// Constructor, destructor
		GameController(unsigned width, unsigned height);
		GameController(IMapProvider& mapProvider);
		virtual ~GameController(void);

		// Players
		virtual Player::PlayerId addPlayer(std::string name, Color color);

		virtual Vector2u getMapSize() const;
		virtual Vector2f getCellSize() const;
		virtual MapCell& getCell(Vector2u cell);
		virtual MapCell& getCell(unsigned x, unsigned y);
		
		virtual Vector2f cellToAbsolute(Vector2u cell);
		virtual Vector2f cellToAbsolute(unsigned x, unsigned y);
		virtual Vector2u absoluteToCell(Vector2f coord);
		virtual Vector2u absoluteToCell(float x, float y);

		// Actions
		virtual void actionsTick(const sf::Time& elapsed);
		virtual void addAction(SmartPtr<GameObject> object, SmartPtr<Action> action);

		// Interactions
		virtual void select(Player::PlayerId, bool add_to_selection, FloatRect area_absolute);
		virtual void move(Player::PlayerId, Vector2f dest);

		virtual void tick(const sf::Time& elapsed);

		// Object
		virtual Object* clone() const;
	};

}