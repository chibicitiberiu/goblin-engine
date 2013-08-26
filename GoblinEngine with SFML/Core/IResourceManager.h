#pragma once

#include "Build.h"
#include <string>

namespace Goblin
{
	/// <summary>Manager for resources.</summary>
	/// <remarks>This class is an interface.</remarks>
	class DLLEXPORT IResourceManager
	{
	public:

		/// <summary>Gets a resource.</summary>
		/// <param name="key">The resource key.</param>
		/// <returns>The resource.</returns>
		virtual void* getResource(std::string key) = 0;

		/// <summary>Query if the resource key is loaded.</summary>
		/// <param name="key">The resource key</param>
		/// <returns>true if the resource loaded, false if not.</returns>
		virtual bool isLoaded(std::string key) = 0;

		/// <summary>Loads a resource.</summary>
		/// <param name="key">The resource key.</param>
		/// <param name="filename">Filename of the resource file.</param>
		virtual void loadResource(std::string key, std::string filename) = 0;
	};
}

