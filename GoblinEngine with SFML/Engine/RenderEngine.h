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

		sf::Texture mapTexture;

		void renderMap();

		Vector2f toIsometric(Vector2f coord);
		Vector2f toCartesian(Vector2f coord);

	public:
		RenderEngine(Scene& scene, IResourceManager& resources);
		virtual ~RenderEngine();

		virtual void render(sf::RenderTarget& target);
	};

}