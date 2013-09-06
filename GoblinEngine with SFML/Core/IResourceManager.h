#pragma once

#include "Build.h"
#include <string>

namespace Goblin
{
	/// <summary>Interface for resources manager.</summary>
	class DLLEXPORT IResourceManager
	{
	public:

		enum LoadHints {
			LoadHintsNone = 0,
			LoadHintsImageAsTexture = 0x1
		};

		enum ResourceType 
		{ 
			ResourceTypeNone,
			ResourceTypeImage,
			ResourceTypeTexture,
			ResourceTypeSound
		};

		/// <summary>Gets a resource.</summary>
		/// <param name="key">The resource key.</param>
		/// <returns>The resource.</returns>
		virtual void* getResource(std::string key) = 0;

		/// <summary>Gets type of resource.</summary>
		/// <param name="key">The resource key.</param>
		/// <returns>The type.</returns>
		virtual ResourceType getResourceType(std::string key) = 0;

		/// <summary>Query if the resource key is loaded.</summary>
		/// <param name="key">The resource key</param>
		/// <returns>true if the resource loaded, false if not.</returns>
		virtual bool isLoaded(std::string key) = 0;

		/// <summary>Loads a resource.</summary>
		/// <param name="key">The resource key.</param>
		/// <param name="filename">Filename of the resource file.</param>
		/// <param name="hints">Load hints</param>
		virtual void loadResource(std::string key, std::string filename, int hints = LoadHintsNone) = 0;
	};
}

