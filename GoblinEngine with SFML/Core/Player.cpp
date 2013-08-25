#include "Player.h"

namespace Goblin 
{
	Player::Player(Player::PlayerId id, std::string name, Color color)
		: _id(id),
		  _name(name), 
		  _color(color),
		  _resources(new ResourceDictionary()),
		  _selectedObjects(new SelectedObjectsContainer())
	{
	}

	Player::~Player()
	{
		delete _resources;
		delete _selectedObjects;
	}

	void Player::setColor(Color value)
	{
		this->_color = value;
	}

	void Player::setName(const std::string& value)
	{
		this->_name = value;
	}

	Player::PlayerId Player::getId() const
	{
		return this->_id;
	}

	Color Player::getColor() const
	{
		return this->_color;
	}

	std::string Player::getName() const
	{
		return this->_name;
	}

	Player::ResourceDictionary& Player::resources()
	{
		return *this->_resources;
	}

	Player::SelectedObjectsContainer& Player::selectedObjects()
	{
		return *this->_selectedObjects;
	}
	
	Object* Player::clone() const
	{
		return new Player(*this);
	}

}