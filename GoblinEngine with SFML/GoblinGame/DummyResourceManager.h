#pragma once
#include "../Core/IResourceManager.h"
#include <map>

class DummyResourceManager : public Goblin::IResourceManager
{
private:
	std::map<std::string, void*> data;

public:
	DummyResourceManager(void);
	virtual ~DummyResourceManager(void);

	/// <summary>Gets a resource.</summary>
	/// <param name="key">The resource key.</param>
	/// <returns>The resource.</returns>
	virtual void* getResource(std::string key);

	/// <summary>Gets type of resource.</summary>
	/// <param name="key">The resource key.</param>
	/// <returns>The type.</returns>
	virtual ResourceType getResourceType(std::string key);

	/// <summary>Query if the resource key is loaded.</summary>
	/// <param name="key">The resource key</param>
	/// <returns>true if the resource loaded, false if not.</returns>
	virtual bool isLoaded(std::string key);

	/// <summary>Loads a resource.</summary>
	/// <param name="key">The resource key.</param>
	/// <param name="filename">Filename of the resource file.</param>
	/// <param name="hints">Load hints</param>
	virtual void loadResource(std::string key, std::string filename, int hints = LoadHintsNone);
};

