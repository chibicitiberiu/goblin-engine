#pragma once

#include "Object.h"
#include "ISerializable.h"

namespace Goblin
{

	class DLLEXPORT Component : public Object /*, public ISerializable */
	{
	public:
		virtual ~Component(void)
		{
		}
	};

}