#include "GTypeFactory.h"
#include "MapEntityComponent.h"
#include "GameObject.h"
#include <cassert>

namespace Goblin
{
	GTypeFactory::GTypeFactory(void)
		: next_id(0)
	{
		this->types = new std::vector<GType>();
		this->registerDefaultTypes();
		this->registerTypes();
	}

	GTypeFactory::~GTypeFactory(void)
	{
		if (this->types != NULL)
			delete this->types;
	}
	
	void GTypeFactory::registerType(SmartPtr<Object> instance)
	{
		assert(this->types != NULL);
		assert(instance.ptr() != NULL);

		this->types->push_back(GType(next_id++, typeid(*instance.ptr()), instance));
	}

	void GTypeFactory::registerDefaultTypes()
	{
		/** TODO **/
		registerType(Goblin::SmartPtr<Object>(new GameObject()));
		registerType(Goblin::SmartPtr<Object>(new MapEntityComponent()));
	}

	void GTypeFactory::registerTypes()
	{
	}

	const size_t GTypeFactory::getTypeId(const Object& obj)
	{
		for (size_t i = 0; i < types->size(); i++)
			if (typeid(obj) == types->at(i).getInfo())
				return i;

		return (size_t)-1;
	}

	SmartPtr<Object> GTypeFactory::createInstance(const type_info& type)
	{		
		for (size_t i = 0; i < types->size(); i++)
			if (type == types->at(i).getInfo())
			{
				return SmartPtr<Object> (types->at(i).getInstance().clone());
			}

		return SmartPtr<Object>();
	}

	SmartPtr<Object> GTypeFactory::createInstance(size_t type_id)
	{
		if (type_id >= this->types->size())
			return SmartPtr<Object>();

		return SmartPtr<Object>(types->at(type_id).getInstance().clone());
	}

}