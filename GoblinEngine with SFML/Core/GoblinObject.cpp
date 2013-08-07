#include "GoblinObject.h"
#include <fstream>

namespace Goblin
{
	GoblinObject::GoblinObject() 
		: owner(NULL)
	{
	}

	GoblinObject::~GoblinObject() 
	{
	}

	GoblinObject* GoblinObject::clone()
	{
		return new GoblinObject(*this);
	}
	
	void GoblinObject::setOwner(const void* owner)
	{
		this->owner = owner;
	}

	const void* GoblinObject::getOwner() const
	{
		return owner;
	}

}