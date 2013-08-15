#pragma once
#include "Array2.h"
#include "Object.h"
#include "ISerializable.h"
#include "Player.h"
#include "Component.h"
#include <vector>
#include <cstdint>
#include "Build.h"

namespace Goblin
{
	class DLLEXPORT MapObject : public Object/*, public ISerializable*/
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