#pragma once
#include "Widget.h"

namespace Goblin
{
	namespace Gui
	{
		class DLLEXPORT IContainer
		{
		public:
			virtual ~IContainer() { }
			virtual void addChild(const Widget& child) = 0;
		};
	}
}