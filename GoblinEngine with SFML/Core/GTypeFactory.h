#pragma once
#include <vector>
#include "GType.h"

namespace Goblin
{

	class DLLEXPORT GTypeFactory
	{
	private:
		std::vector<GType>* types;
		size_t next_id;

		/// <summary>
		/// Registers all the types derived from <see cref="Object"/> which
		/// are implemented in the Goblin engine.
		/// </summary>
		void registerDefaultTypes();

	protected:

		/// <summary>Registers a data type.</summary>
		/// <param name="instance">An object instance of data type.</param>
		void registerType(SmartPtr<Object> instance);
		
		/// <summary>Should be overriden by games using this engine to register their own classes.
		/// The registration mechanism allows objects to be deserialized.</summary>
		virtual void registerTypes();

	public:

		/// <summary>Default constructor.</summary>
		GTypeFactory();

		/// <summary>Destructor.</summary>
		virtual ~GTypeFactory(void);

		/// <summary>Gets type identifier of object.</summary>
		/// <param name="obj">The object.</param>
		/// <returns>The type identifier. If not found, -1 is returned.</returns>
		const size_t getTypeId(const Object& obj);

		/// <summary>Creates an instance of specified type.</summary>
		/// <param name="type">The type.</param>
		/// <returns>A pointer to an instance of specified type, or NULL if type is not 
		/// registered.</returns>
		SmartPtr<Object> createInstance(const type_info& type);

		/// <summary>Creates an instance of specified type.</summary>
		/// <param name="type">The type.</param>
		/// <returns>A pointer to an instance of specified type, or NULL if type is not 
		/// registered.</returns>
		SmartPtr<Object> createInstance(size_t type_id);
	};

}