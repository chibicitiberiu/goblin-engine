#include "MapEntityComponent.h"

namespace Goblin
{

	MapEntityComponent::MapEntityComponent(void)
		: absolutePosition(0, 0), gridPosition(0, 0)
	{
	}


	MapEntityComponent::~MapEntityComponent(void)
	{
	}

// Getters
	Vector2f MapEntityComponent::getAbsolutePosition() const
	{
		return this->absolutePosition;
	}

	Vector2u MapEntityComponent::getGridPosition() const
	{
		return this->gridPosition;
	}

	const Array2<int>& MapEntityComponent::getGridShape()
	{
		return *this->gridShape;
	}

// Setters
	void MapEntityComponent::setGridPosition(Vector2u value)
	{
		this->gridPosition = value;
	}

	void MapEntityComponent::setGridPosition(unsigned x, unsigned y)
	{
		this->gridPosition.x = x;
		this->gridPosition.y = y;
	}

	void MapEntityComponent::setAbsolutePosition(Vector2f value)
	{
		this->absolutePosition = value;
	}

	void MapEntityComponent::setAbsolutePosition(float x, float y)
	{
		this->absolutePosition.x = x;
		this->absolutePosition.y = y;
	}

	void MapEntityComponent::setGridShape(SmartPtr<Array2<int> > shape)
	{
		this->gridShape = shape;
	}

	Object* MapEntityComponent::clone() const
	{
		return new MapEntityComponent(*this);
	}
}