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
		
	}

	Vector2u GameController::getMapSize() const
	{
		throw EXCEPTION(NotImplementedException, "Not implemented.");
	}

	Vector2f GameController::getCellSize() const
	{
		throw EXCEPTION(NotImplementedException, "Not implemented.");
	}

	MapCell& GameController::getCell(Vector2u cell)
	{
		throw EXCEPTION(NotImplementedException, "Not implemented.");
	}

	MapCell& GameController::getCell(unsigned x, unsigned y)
	{
		throw EXCEPTION(NotImplementedException, "Not implemented.");
	}
		
	Vector2f GameController::cellToAbsolute(Vector2u cell)
	{
		throw EXCEPTION(NotImplementedException, "Not implemented.");
	}

	Vector2f GameController::cellToAbsolute(unsigned x, unsigned y)
	{
		throw EXCEPTION(NotImplementedException, "Not implemented.");
	}

	Vector2u GameController::absoluteToCell(Vector2f coord)
	{
		throw EXCEPTION(NotImplementedException, "Not implemented.");
	}

	Vector2u GameController::absoluteToCell(float x, float y)
	{
		throw EXCEPTION(NotImplementedException, "Not implemented.");
	}


	Object* GameController::clone() const
	{
		return new GameController(*this);
	}
}