#pragma once

#include <vector>

namespace Goblin
{
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