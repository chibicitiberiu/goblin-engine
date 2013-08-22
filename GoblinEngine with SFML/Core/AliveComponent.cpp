#include "AliveComponent.h"

namespace Goblin
{
	AliveComponent::AliveComponent(void)
	{
	}


	AliveComponent::~AliveComponent(void)
	{
	}

	void AliveComponent::setMaxHealth(float value)
	{
		this->maxHealth = value;
	}

	void AliveComponent::setHealth(float value)
	{
		this->health = value;
	}

	float AliveComponent::getMaxHealth() const
	{
		return this->maxHealth;
	}

	float AliveComponent::getHealth() const
	{
		return this->health;
	}
}