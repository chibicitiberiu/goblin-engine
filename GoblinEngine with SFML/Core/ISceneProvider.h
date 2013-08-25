#pragma once

#include "Scene.h"

namespace Goblin
{
	class DLLEXPORT ISceneProvider
	{
	public:
		virtual SmartPtr<Scene> getScene() = 0;
	};

}