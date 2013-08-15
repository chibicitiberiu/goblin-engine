#include "GameController.h"
#include <cassert>
#include <SFML\Graphics.hpp>

namespace Goblin
{

	GameController::GameController(void)
	{
		this->players = new std::vector<Player*>();

		this->addPlayer(Player::NeutralPlayer, "Neutral", Color(192, 192, 192));
	}


	GameController::~GameController(void)
	{
		delete this->players;
	}

	void GameController::addPlayer(Player* player)
	{
		assert(this->players != NULL);
		assert(player != NULL);

		this->players->push_back(player);
	}

	void GameController::addPlayer(Player::PlayerKind kind, std::string name, Color color)
	{
		assert(this->players != NULL);

		Player* player = new Player(kind, name, color);

		this->players->push_back(player);
	}

	size_t GameController::getMapWidth() const
	{
		return (this->map == NULL) ? 0 : 100 /* todo */ ;
	}

	size_t GameController::getMapHeight() const
	{
		return (this->map == NULL) ? 0 : 100 /* todo */ ;
	}

	int GameController::getMapTerrain(size_t cell_x, size_t cell_y) const
	{
		// todo...
		return 0;
	}

	int GameController::getMapHeight(size_t cell_x, size_t cell_y) const
	{
		// todo...
		return 0;
	}

	MapObject* GameController::getMapObject(size_t cell_x, size_t cell_y) const
	{
		// todo...
		return NULL;
	}

	void GameController::loadMap(IMapProvider* mapProvider)
	{
		// todo...
	}
}