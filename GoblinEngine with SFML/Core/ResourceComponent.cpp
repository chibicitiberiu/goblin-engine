#include "ResourceComponent.h"

namespace Goblin
{
	ResourceComponent::ResourceComponent(void)
		: resources(new std::map<int, int>())
	{
	}

	ResourceComponent::ResourceComponent(const ResourceComponent& rc)
		: resources(new std::map<int, int>(*rc.resources))
	{
	}

	ResourceComponent& ResourceComponent::operator= (const ResourceComponent& rc)
	{
		if (this != &rc)
		{
			delete resources;
			resources = new std::map<int, int>(*rc.resources);
		}

		return *this;
	}

	ResourceComponent::~ResourceComponent(void)
	{
		delete resources;
	}

	void ResourceComponent::setResource(int type, int amount)
	{
		(*resources)[type] = amount;	
	}

	int ResourceComponent::getResourceAmount(int type)
	{
		return (resources->count(type) == 0) ? 0 : (*resources)[type];
	}

	Object* ResourceComponent::clone() const
	{
		return new ResourceComponent(*this);
	}
}