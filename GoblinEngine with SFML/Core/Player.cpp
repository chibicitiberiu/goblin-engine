#include "Player.h"

namespace Goblin 
{
	Player::Player(Player::PlayerId id, std::string name, Color color)
		: _id(id),
		  _name(name), 
		  _color(color),
		  _resources(new ResourceDictionary()),
		  _selectedObjects(new SelectedObjectsContainer()),
		  _explored(NULL), _visible(NULL)
	{
	}

	Player::~Player()
	{
		delete _resources;
		delete _selectedObjects;

		if (_explored != NULL)
			delete _explored;

		if (_visible != NULL)
			delete _visible;
	}

	void Player::createVisibleExplored(size_t map_width, size_t map_height)
	{
		// Create explored map
		if (_explored != NULL)
			delete _explored;

		_explored = new Array2<float>(map_width, map_height);

		// Create visible map
		if (_visible != NULL)
			delete _visible;

		_visible = new Array2<float>(map_width, map_height);
	}

	void Player::setColor(const Color& value)
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

	Array2<float>& Player::explored()
	{
		if (_explored == NULL)
			throw NullReferenceException("Explored map not created!");

		return *_explored;
	}

	bool Player::hasExploredMap() const
	{
		return (_explored != NULL);
	}

	Array2<float>& Player::visible()
	{
		if (_visible == NULL)
			throw NullReferenceException("Visible map not created!");

		return *_visible;
	}

	bool Player::hasVisibleMap() const
	{
		return (_visible != NULL);
	}
	
	Object* Player::clone() const
	{
		return new Player(*this);
	}

}