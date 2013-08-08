#pragma once
#include <vector>
#include "GoblinType.h"

namespace Goblin
{

	class DLLEXPORT GoblinTypeFactory
	{
	private:
		std::vector<GoblinType>* types;
		size_t next_id;
		void registerDefaultTypes();

	protected:

		void registerType(GoblinObject* instance);
		virtual void registerTypes();

	public:
		GoblinTypeFactory();
		virtual ~GoblinTypeFactory(void);

		const size_t getTypeId(const GoblinObject* obj);
		GoblinObject* createInstance(const type_info& type);
		GoblinObject* createInstance(size_t type_id);
	};

}