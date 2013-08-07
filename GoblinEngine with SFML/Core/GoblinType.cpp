#include "GoblinType.h"
#include <cassert>

namespace Goblin
{
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="id">The type id.</param>
	/// <param name="info">The typeid information of the type.</param>
	/// <param name="instance">An instance of type.</param>
	GoblinType::GoblinType(size_t id, const type_info& info, GoblinObject* instance)
		: id(id), info(info), instance(instance)
	{
		assert(this->instance != NULL);

		if (this->instance->getOwner() == NULL)
			this->instance->setOwner(this);
	}

	/// <summary>
	/// Destructor
	/// </summary>
	GoblinType::~GoblinType(void)
	{
		if (this->instance != NULL && this->instance->getOwner() == this)
			delete this->instance;
	}

	/// <summary>
	/// Gets the registered type id.
	/// </summary>
	size_t GoblinType::getId() const
	{
		return this->id;
	}

	/// <summary>
	/// Gets the type info.
	/// </summary>
	const type_info& GoblinType::getInfo() const
	{
		return this->info;
	}

	/// <summary>
	/// Gets a default instance of this type.
	/// </summary>
	GoblinObject* GoblinType::getInstance()
	{
		return this->instance;
	}
}