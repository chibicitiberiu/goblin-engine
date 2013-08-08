#include <string>
#include <typeinfo>
#include "GoblinObject.h"
#pragma once

namespace Goblin
{

	class DLLEXPORT GoblinType
	{

	private:
		size_t id;
		GoblinObject* instance;
		const type_info& info;

	public:

		// Constructor
		GoblinType(size_t id, const type_info& info, GoblinObject* instance);
		virtual ~GoblinType();

		// Getters
		size_t getId() const;
		const type_info& getInfo() const;
		GoblinObject* getInstance();
	};

}