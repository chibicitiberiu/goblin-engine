#include "GoblinTypeFactory.h"
#include <cassert>

namespace Goblin
{

	/// <summary>
	/// Initializes a new instance of the <see cref="GoblinTypeFactory"/> class.
	/// </summary>
	GoblinTypeFactory::GoblinTypeFactory(void)
		: next_id(0)
	{
		this->types = new std::vector<GoblinType>();
		this->registerDefaultTypes();
		this->registerTypes();
	}

	/// <summary>
	/// Finalizes an instance of the <see cref="GoblinTypeFactory"/> class.
	/// </summary>
	GoblinTypeFactory::~GoblinTypeFactory(void)
	{
		if (this->types != NULL)
			delete this->types;
	}
	
	/// <summary>
	/// Registers a type derived from <see cref="GoblinObject"/>.
	/// </summary>
	/// <param name="instance">An object instance.</param>
	void GoblinTypeFactory::registerType(GoblinObject* instance)
	{
		assert(this->types != NULL);
		assert(instance != NULL);

		this->types->push_back(GoblinType(next_id++, typeid(*instance), instance));
	}

	/// <summary>
	/// Registers all the types derived from <see cref="GoblinObject"/> which
	/// are implemented in the Goblin engine.
	/// </summary>
	void GoblinTypeFactory::registerDefaultTypes()
	{
		/** TODO **/
	}

	/// <summary>
	/// Registers all the types derived from <see cref="GoblinObject"/>,
	/// should be overriden by any project which uses the Goblin engine,
	/// and derives from GoblinObject.
	/// </summary>
	void GoblinTypeFactory::registerTypes()
	{
	}

	/// <summary>Gets type identifier.</summary>
	/// <param name="obj">An object.</param>
	/// <returns>The type identifier, -1 if not found.</returns>
	const size_t GoblinTypeFactory::getTypeId(const GoblinObject* obj)
	{
		for (size_t i = 0; i < types->size(); i++)
			if (typeid(obj) == types->at(i).getInfo())
				return i;

		return (size_t)-1;
	}

	/// <summary>Creates an instance of specified type.</summary>
	/// <param name="type">The type.</param>
	/// <returns>The new instance of specified type, or NULL if type not found.</returns>
	GoblinObject* GoblinTypeFactory::createInstance(const type_info& type)
	{		
		for (size_t i = 0; i < types->size(); i++)
			if (type == types->at(i).getInfo())
			{
				return types->at(i).getInstance()->clone();
			}

		return NULL;
	}

	/// <summary>Creates an instance of specified type.</summary>
	/// <param name="type_id">Identifier for the type.</param>
	/// <returns>The new instance of specified type, or NULL if type not found.</returns>
	GoblinObject* GoblinTypeFactory::createInstance(size_t type_id)
	{
		if (type_id >= this->types->size())
			return NULL;

		return types->at(type_id).getInstance()->clone();
	}

}