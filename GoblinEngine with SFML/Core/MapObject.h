#pragma once
#include "Array2.h"
#include "GoblinObject.h"
#include "ISerializable.h"
#include "Player.h"
#include "Component.h"
#include <vector>
#include <cstdint>
#include "Build.h"

namespace Goblin
{
	class DLLEXPORT MapObject : public GoblinObject/*, public ISerializable*/
	{
	private:
		std::vector<Component*>* components;
		Player* player;

	public:
		MapObject(void);
		virtual ~MapObject(void);

		virtual Array2<int>* getShape() = 0;
	};

}