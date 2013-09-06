#pragma once
#include "Component.h"

namespace Goblin
{
	class DLLEXPORT DrawableComponent : public Component
	{
	public:
		DrawableComponent(void);
		virtual ~DrawableComponent(void);

		virtual std::string getResourceName();
	};

}