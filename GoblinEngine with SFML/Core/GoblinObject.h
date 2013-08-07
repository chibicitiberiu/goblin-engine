#pragma once

#include <vector>
#include "Component.h"

namespace Goblin
{
	class GoblinType;

	class GoblinObject
	{
	private:
		const void* owner;

	public:
		GoblinObject();
		virtual ~GoblinObject();

		virtual GoblinObject* clone();

		virtual void setOwner(const void* owner);
		virtual const void* getOwner() const;
	};
}