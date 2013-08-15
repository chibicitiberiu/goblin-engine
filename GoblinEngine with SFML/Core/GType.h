#include <string>
#include <typeinfo>
#include "Object.h"
#include "SmartPtr.h"
#pragma once

namespace Goblin
{

	class DLLEXPORT GType
	{

	private:
		size_t id;
		SmartPtr<Object>* instance;
		const type_info& info;

	public:

	// Constructor
		/// <summary>
		/// Constructor
		/// </summary>
		/// <param name="id">The type id.</param>
		/// <param name="info">The typeid information of the type.</param>
		/// <param name="instance">A smart pointer to an instance of type.</param>
		GType(size_t id, const type_info& info, SmartPtr<Object> instance);

		/// <summary>
		/// Destructor
		/// </summary>
		virtual ~GType();

	// Getters
		/// <summary>
		/// Gets the registered type id.
		/// </summary>
		size_t getId() const;

		/// <summary>
		/// Gets the type info.
		/// </summary>
		const type_info& getInfo() const;
		
		/// <summary>
		/// Gets a default instance of this type.
		/// </summary>
		const Object& getInstance();
	};

}