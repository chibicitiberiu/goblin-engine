#pragma once
#include "../Core/Build.h"
#include "../Core/Scene.h"
#include "../Core/IResourceManager.h"
#include <SFML/Graphics.hpp>

namespace Goblin
{
	class DLLEXPORT RenderEngine
	{
	private:
		Scene& scene;
		IResourceManager& resources;

	public:
		RenderEngine(Scene& scene, IResourceManager& resources);
		virtual ~RenderEngine();

		virtual void render(sf::RenderTarget& target);
	};

}