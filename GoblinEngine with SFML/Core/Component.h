#pragma once

#include "GoblinObject.h"
#include "ISerializable.h"

namespace Goblin
{

	class DLLEXPORT Component : public GoblinObject, public ISerializable
	{
	public:
		Component(void);
		virtual ~Component(void);
	};

}