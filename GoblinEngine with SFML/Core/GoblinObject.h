#pragma once

#include <vector>
#include "Build.h"

namespace Goblin
{
	class DLLEXPORT GoblinObject
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