#include "GameController.h"
#include <cassert>
#include <SFML\Graphics.hpp>

namespace Goblin
{

	GameController::GameController(void)
	{
		this->players = new std::vector< SmartPtr<Player> >();
		
		this->addPlayer(Player::NeutralPlayer, "Neutral", Color(192, 192, 192));
	}


	GameController::~GameController(void)
	{
		delete this->players;
	}

	void GameController::addPlayer(SmartPtr<Player> player)
	{
		assert(this->players != NULL);
		assert(player != NULL);

		this->players->push_back(player);
	}

	void GameController::addPlayer(Player::PlayerKind kind, std::string name, Color color)
	{
		assert(this->players != NULL);

		Player* player = new Player(kind, name, color);
		this->players->push_back(SmartPtr<Player>(player));
	}

	void GameController::loadMap(IMapProvider& mapProvider)
	{
		Vector2u size = mapProvider.getSize();
		this->objects = SmartPtr<Array2<SmartPtr<GameObject>>>(new Array2<SmartPtr<GameObject>>(size.x, size.y));
		this->terrain = SmartPtr<Array2<int>>(new Array2<int>(size.x, size.y));
	}
}