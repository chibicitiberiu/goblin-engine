#include "Player.h"

namespace Goblin 
{
	Player::Player(Player::PlayerId id, std::string name, Color color)
		: id(id), name(name), color(color)
	{
	}

	Player::~Player()
	{
	}

	void Player::setColor(Color value)
	{
		this->color = value;
	}

	void Player::setName(const std::string& value)
	{
		this->name = value;
	}


	Color Player::getColor() const
	{
		return this->color;
	}

	std::string Player::getName() const
	{
		return this->name;
	}

	Object* Player::clone() const
	{
		return new Player(*this);
	}

}