#pragma once
#include "Build.h"
#include <string>

namespace Goblin
{
	class DLLEXPORT IDebugHandler
	{
	public:
		virtual void write(std::string info) = 0;
	};
}