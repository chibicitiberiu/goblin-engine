#pragma once

#include "../Core/IResourceManager.h"
#include "../Core/Exception.h"
#include "../Core/Log.h"
#include <SFGUI/SFGUI.hpp>
#include <SFML/Audio.hpp>
#include<queue>
#include<map>
#include<fstream>

namespace Goblin
{
	class DLLEXPORT ResourceManager : public IResourceManager
	{
	public:

	private:

		/// <summary>Queue item.</summary>
		struct QueueItem {
			std::string key;
			std::string filename;
			int hints;

			QueueItem()
				: key(), filename(), hints(LoadHintsNone)
			{
			}

			QueueItem(std::string key, std::string filename, int hints)
				: key(key), filename(filename), hints(hints)
			{
			}
		};

		/// <summary>Resource item.</summary>
		struct ResourceItem {
			void* data;
			ResourceType type;

			ResourceItem()
				: data(NULL), type(ResourceTypeNone)
			{
			}

			ResourceItem(void* data, ResourceType type)
				: data(data), type(type)
			{
			}
		};

		// Constants
		static const char* resourceTypesFile;

		// Fields
		std::queue<QueueItem> queue;
		std::map<std::string, ResourceItem> resources;

		sf::Thread* thread;
		bool threadRunning;

		// Methods
		ResourceType getFileType(std::string fileName);

		void loadFilesThread();
		void* loadFile(std::string filename, ResourceType type);

		template <typename T>
		void* loadSfmlData(std::string filename)
		{
			T* data = new T();
			
			if (data->loadFromFile(filename))
				return data;

			else
			{
				delete data;
				return NULL;
			}
		}

	public:
		ResourceManager(void);

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
		virtual void loadResource(std::string key, std::string filename, int hints = LoadHintsNone);
		
		~ResourceManager(void);
	};

	const char* ResourceManager::resourceTypesFile= "Assets/ResourceFormats.cfg";
}

