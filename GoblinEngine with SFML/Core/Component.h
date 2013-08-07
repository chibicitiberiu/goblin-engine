#pragma once

#include "GoblinObject.h"
#include "Serializable.h"

namespace Goblin
{

	class Component : public GoblinObject, public Serializable
	{
	public:
		Component(void);
		virtual ~Component(void);
	};

}