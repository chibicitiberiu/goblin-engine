#include "Player.h"

namespace Goblin 
{
	Player::Player()
		: color(), kind(HumanPlayer), name("Player")
	{
	}

	Player::Player(PlayerKind kind, std::string name, Color color)
		: color(color), kind(kind), name(name)
	{
	}

	Player::~Player()
	{
	}

	void Player::setColor(Color value)
	{
		this->color = value;
	}

	void Player::setPlayerKind(PlayerKind value)
	{
		this->kind = value;
	}

	void Player::setName(const std::string& value)
	{
		this->name = value;
	}


	Color Player::getColor() const
	{
		return this->color;
	}

	Player::PlayerKind Player::getPlayerKind() const
	{
		return this->kind;
	}

	std::string Player::getName() const
	{
		return this->name;
	}

}