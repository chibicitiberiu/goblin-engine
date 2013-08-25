#include "MovableComponent.h"

namespace Goblin
{
	MovableComponent::MovableComponent(void)
		: angle(0.0f), speed(0.0f), maxSpeed(1.0f), acceleration(1.0f), deceleration(1.0f)
	{
	}


	MovableComponent::~MovableComponent(void)
	{
	}

	float MovableComponent::getAngle() const
	{
		return this->angle;
	}

	float MovableComponent::getSpeed() const
	{
		return this->speed;
	}

	float MovableComponent::getMaxSpeed() const
	{
		return this->maxSpeed;
	}

	float MovableComponent::getAcceleration() const
	{
		return this->acceleration;
	}

	float MovableComponent::getDeceleration() const
	{
		return this->deceleration;
	}

	void MovableComponent::setAngle(float value)
	{
		this->angle = value;
	}

	void MovableComponent::setSpeed(float value)
	{
		this->speed = value;
	}

	void MovableComponent::setMaxSpeed(float value)
	{
		this->maxSpeed = value;
	}

	void MovableComponent::setAcceleration(float value)
	{
		this->acceleration = value;
	}

	void MovableComponent::setDeceleration(float value)
	{
		this->deceleration = value;
	}

}