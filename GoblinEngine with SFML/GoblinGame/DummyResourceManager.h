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

	virtual void* getResource(std::string key);

	virtual bool isLoaded(std::string key);

	virtual void loadResource(std::string key, std::string filename);
};

