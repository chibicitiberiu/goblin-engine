#pragma once

#include "Scene.h"

namespace Goblin
{
	/// <summary>Scene provider interface.</summary>
	class DLLEXPORT ISceneProvider
	{
	public:

		/// <summary>Gets the scene.</summary>
		/// <returns>The scene.</returns>
		virtual SmartPtr<Scene> getScene() = 0;
	};

}