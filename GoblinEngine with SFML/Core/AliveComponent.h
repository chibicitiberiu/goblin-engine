#pragma once
#include "Component.h"

namespace Goblin
{

	class AliveComponent : public Component
	{
	private:
		float maxHealth;
		float health;

	public:
		AliveComponent(void);
		virtual ~AliveComponent(void);

		virtual void setMaxHealth(float value);
		virtual void setHealth(float value);

		virtual float getMaxHealth() const;
		virtual float getHealth() const;
	};

}