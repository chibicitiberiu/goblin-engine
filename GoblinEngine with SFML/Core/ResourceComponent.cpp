#include "ResourceComponent.h"

namespace Goblin
{
	ResourceComponent::ResourceComponent(void)
		: resources(new std::map<int, float>())
	{
	}

	ResourceComponent::ResourceComponent(const ResourceComponent& rc)
		: resources(new std::map<int, float>(*rc.resources))
	{
	}

	ResourceComponent& ResourceComponent::operator= (const ResourceComponent& rc)
	{
		if (this != &rc)
		{
			delete resources;
			resources = new std::map<int, float>(*rc.resources);
		}

		return *this;
	}

	ResourceComponent::~ResourceComponent(void)
	{
		delete resources;
	}

	void ResourceComponent::setResource(int type, float amount)
	{
		(*resources)[type] = amount;	
	}

	float ResourceComponent::getResourceAmount(int type)
	{
		return (resources->count(type) == 0) ? 0 : (*resources)[type];
	}

	Object* ResourceComponent::clone() const
	{
		return new ResourceComponent(*this);
	}
}