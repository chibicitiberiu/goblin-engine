#pragma once
#include "Component.h"

namespace Goblin
{
	class MovableComponent : public Component
	{
		// TODO: add movement stuff: speed, acceleration, decceleration

	public:
		MovableComponent(void);
		virtual ~MovableComponent(void);
	};
}