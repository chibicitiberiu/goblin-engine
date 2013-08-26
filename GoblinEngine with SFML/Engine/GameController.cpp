#include "GameController.h"
#include "../Core/MapEntityComponent.h"
#include "../Core/Clamp.h"
#include <SFML/Graphics.hpp>
#include <cassert>
#include <algorithm>

namespace Goblin
{
	GameController::GameController(ISceneProvider& sceneProvider) 
		: _scene(sceneProvider.getScene())
	{
	}

	GameController::~GameController(void)
	{
	}

	//unsigned GameController::toObjectIndex(Vector2u pos)
	//{
	//	return pos.x + pos.y * mapSize.x;
	//}

	Scene& GameController::scene()
	{
		return *_scene;
	}

	Player::PlayerId GameController::addPlayer(std::string name, Color color)
	{
		// Get player id
		Player::PlayerId id = static_cast<Player::PlayerId>(_scene->players().size());

		// Create player
		SmartPtr<Player> player = new Player(id, name, color);

		// Add player to player list
		_scene->players().push_back(player);

		// Return id
		return id;
	}

/*	void GameController::select(Player::PlayerId pid, bool add_to_selection, FloatRect area_absolute)
	{
		// Get corresponding eclls
		Vector2u topLeft = absoluteToCell(area_absolute.left, area_absolute.top);
		Vector2u size = absoluteToCell(area_absolute.width, area_absolute.height);

		// Clear selection?
		if (!add_to_selection)
			players->at(pid)->selectedObjects->clear();

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
						if (area_absolute.contains(pos) && (std::count(players->at(pid)->selectedObjects->begin(), players->at(pid)->selectedObjects->end(), it->second) == 0))
						{
							// Select
							players->at(pid)->selectedObjects->push_back(it->second);
						}
					}
				}
			}
	}

	void GameController::move(Player::PlayerId pid, Vector2f dest)
	{
	}

	void GameController::addAction(SmartPtr<GameObject> object, SmartPtr<Action> action)
	{
		// Create queue item structure
		ActionQueueItem item;
		item.object = object;
		item.action = action;

		// Find previous item in queue
		for (auto it = actionQueue->begin(); it != actionQueue->end(); it++)
		{
			if (it->object == object)
				item.dependsOn = it->action;
		}

		// Enqueue
		actionQueue->push_back(item);
	}


	void GameController::actionsTick(const sf::Time& elapsed)
	{
		// Perform actions
		for (auto it = actionQueue->begin(); it != actionQueue->end(); it++)
		{
			// Doesn't have dependencies (means that it is first in queue)
			if (it->dependsOn.ptr() == NULL)
				it->action->tick(elapsed);

			// Finished?
			if (it->action->isFinished())
			{
				// Delete action
				SmartPtr<Action> action = it->action;
				it = actionQueue->erase(it);

				// Find actions that depend on it
				for (auto it2 = it; it2 != actionQueue->end(); it2++)
					if (it2->dependsOn == action)
					{
						// Remove dependency
						it2->dependsOn = SmartPtr<Action>();

						// Tell action it is about to start
						it2->action->onActionStarted();
					}
			}
		}
	}*/

	void GameController::tick(const sf::Time& elapsed)
	{
		// actionsTick(elapsed);
	}

	Object* GameController::clone() const
	{
		return new GameController(*this);
	}
}