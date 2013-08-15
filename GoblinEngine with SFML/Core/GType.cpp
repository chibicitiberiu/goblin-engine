#include "GType.h"
#include <cassert>

namespace Goblin
{
	GType::GType(size_t id, const type_info& info, SmartPtr<Object> instance)
		: id(id), info(info), instance(new SmartPtr<Object>(instance))
	{
		assert(instance.ptr() != NULL);
	}

	GType::~GType(void)
	{
		delete instance;
	}

	size_t GType::getId() const
	{
		return this->id;
	}

	const type_info& GType::getInfo() const
	{
		return this->info;
	}

	const Object& GType::getInstance()
	{
		return *(*this->instance);
	}
}