#pragma once
#include <vector>
#include <map>
#include <list>
#include "Player.h"
#include "Array2.h"
#include "MapCell.h"

using sf::Vector2u;

namespace Goblin
{
	class Scene : public Object
	{
		// Player list
	public:
		typedef std::vector<SmartPtr<Player>> PlayersContainer;

	private:
		PlayersContainer* _players;

		// Game map
	public:
		typedef Array2<MapCell> Map;

	private:
		Map* _map;
		Vector2u _sizeCells;
		Vector2f _sizeAbsolute;

		// Game objects
	public:
		typedef std::vector<SmartPtr<GameObject>> ObjectContainer;
		typedef std::multimap<unsigned, GameObject*> ObjectPlacementContainer;

	private:
		ObjectContainer* _objects;
		ObjectPlacementContainer* _objectsPlacement;

		// Action queue
	public:
		struct ActionQueueItem {
			GameObject* object;
			SmartPtr<Action> action;
			Action* dependsOn;
		};
		typedef std::list<ActionQueueItem> ActionQueue;

	private:
		ActionQueue* _actionQueue;


	public:
	// Constructor
		/// <summary>Constructor.</summary>
		/// <param name="sizeCells">The size cells.</param>
		/// <param name="sizeAbsolute">The size absolute.</param>		
		Scene(Vector2u sizeCells, Vector2f sizeAbsolute);

		/// <summary>Destructor./</summary>
		virtual ~Scene(void);

	// Getters
		/// <summary>Gets the absolute size of the map.</summary>
		/// <returns>The absolute size.</returns>
		virtual Vector2f getSizeAbsolute() const;

		/// <summary>Gets the size in cells .</summary>
		/// <returns>The size in cells.</returns>
		virtual Vector2u getSizeCells() const;

		/// <summary>Gets the map container.</summary>
		/// <returns>The map container.</returns>
		/// <remarks>Holds a bidimensional array of all the cells on the map.</remarks>
		virtual Map& map();

		/// <summary>Gets the players container.</summary>
		/// <returns>Players container.</returns>
		/// <remarks>Holds a list of all the players.</remarks>
		virtual PlayersContainer& players();

		/// <summary>Gets the game objects container.</summary>
		/// <returns>Game objects container.</returns>
		/// <remarks>Holds a list of all the objects in the game.</remarks>
		virtual ObjectContainer& objects();

		/// <summary>Gets the objects placement container.</summary>
		/// <returns>Objects placement container.</returns>
		/// <remarks>Holds a multimap which associates every game object
		/// with it's position on the map.</remarks>
		virtual ObjectPlacementContainer& objectsPlacement();

		/// <summary>Gets the action queue.</summary>
		/// <returns>Action queue.</returns>
		/// <remarks>The action queue holds a list with all the queued
		/// actions (e.g. 'move', or 'attack').</remarks>
		virtual ActionQueue& actionQueue();

	// Conversions
		/// <summary>Converts a cell position to an absolute position.</summary>
		/// <param name="cell">The cell position.</param>
		/// <returns>Absolute position.</returns>
		virtual Vector2f toAbsolute(Vector2u cell) const;

		/// <summary>Converts a cell position to an absolute position.</summary>
		/// <param name="x">The cell column.</param>
		/// <param name="y">The cell row.</param>
		/// <returns>Absolute position.</returns>
		virtual Vector2f toAbsolute(unsigned x, unsigned y) const;

		/// <summary>Converts an absolute position to a cell position.</summary>
		/// <param name="absolute">The absolute position.</param>
		/// <returns>Cell position.</returns>
		virtual Vector2u toCell(Vector2f absolute) const;

		/// <summary>Converts an absolute position to a cell position.</summary>
		/// <param name="x">The absolute x coordinate.</param>
		/// <param name="y">The absolute y coordinate.</param>
		/// <returns>Cell position.</returns>
		virtual Vector2u toCell(float x, float y) const;
	};

}