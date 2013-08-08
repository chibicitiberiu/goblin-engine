#pragma once
#include "Array2.h"
#include "GoblinObject.h"
#include "Serializable.h"
#include "Component.h"
#include <vector>
#include <cstdint>
#include "Build.h"

namespace Goblin
{
	class DLLEXPORT MapObject : public GoblinObject, public Serializable
	{
	private:
		std::vector<Component*>* components;

	public:
		MapObject(void);
		virtual ~MapObject(void);

		virtual Array2<int>* getShape() = 0;
	};

}