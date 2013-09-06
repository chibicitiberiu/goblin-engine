#include "ResourceManager.h"

namespace Goblin
{
	ResourceManager::ResourceManager(void)
		: thread(NULL), threadRunning(false)
	{
	}

	void* ResourceManager::getResource(std::string key)
	{
		if (this->resources.count(key) == 0)
			return NULL;
	
		return this->resources.at(key).data;
	}

	ResourceManager::ResourceType ResourceManager::getResourceType(std::string key)
	{
		if (this->resources.count(key) == 0)
			return ResourceTypeNone;
	
		return this->resources.at(key).type;
	}

	bool ResourceManager::isLoaded(std::string key)
	{
		return this->resources.count(key) != 0;
	}

	void ResourceManager::loadResource(std::string key, std::string filename, int hints)
	{
		this->queue.push(QueueItem(key, filename, hints));

		if (!threadRunning)
		{
			if (thread != NULL)
				delete thread;

			thread = new sf::Thread(&ResourceManager::loadFilesThread, this);
			thread->launch();
		}
	}

	void ResourceManager::loadFilesThread()
	{
		threadRunning = true;

		for(; !queue.empty(); queue.pop())
		{
			QueueItem& resource = queue.front();

			// Check if key already exists
			if (isLoaded(resource.key))
			{
				debug<<Goblin::log<<"Error: Resource "<<resource.key<<" ("<<resource.filename<<") already exists.\n";
				continue;
			}
			
			// Get file type
			ResourceType type = getFileType(resource.filename);

			if (type == ResourceTypeImage && (resource.hints & LoadHintsImageAsTexture))
				type = ResourceTypeTexture;

			// Load file
			void* data = this->loadFile(resource.filename, type);

			// Add to dictionary
			if (data == NULL)
				debug<<Goblin::log<<"Error: Failed to load resource "<<resource.filename<<" of type "<<(int)type<<".\n";
				
			else
				resources.insert(std::make_pair(resource.key, ResourceItem(data, type)));
		}

		threadRunning = false;
	}

	ResourceManager::ResourceType ResourceManager::getFileType(std::string fileName)
	{
		std::string extension = fileName.substr(fileName.find_last_of("."));

		std::ifstream fin(resourceTypesFile);
	
		if(!fin)
		{
			debug<<Goblin::log<<"Error: Resource file "<<resourceTypesFile<<" not found!\n";
			return ResourceTypeNone;
		}

		std::string formatType;
		int resourceTypeIndex;

		while( fin >> formatType >> resourceTypeIndex )
		{
			if( formatType == extension )
			{
				fin.close();
				return (ResourceType)resourceTypeIndex;
			}
		}

		return ResourceTypeNone;
	}

	void* ResourceManager::loadFile(std::string filename, ResourceManager::ResourceType type)
	{
		switch (type)
		{
		case ResourceTypeImage:
			return loadSfmlData<sf::Image>(filename);

		case ResourceTypeTexture:
			return loadSfmlData<sf::Texture>(filename);

		case ResourceTypeSound:
			return loadSfmlData<sf::SoundBuffer>(filename);

		default:
			return NULL;
		}
	}

	ResourceManager::~ResourceManager(void)
	{
		if (thread != NULL)
			delete thread;

		for (auto it = resources.begin(); it != resources.end(); it++)
		{
			switch (it->second.type)
			{
				case ResourceTypeImage:
					delete (sf::Image*)it->second.data;

				case ResourceTypeTexture:
					delete (sf::Texture*)it->second.data;

				case ResourceTypeSound:
					delete (sf::SoundBuffer*)it->second.data;
			}
		}
	}




}