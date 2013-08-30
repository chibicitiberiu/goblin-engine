#pragma once
#include "../Core/Build.h"
#include "../Core/Scene.h"
#include "../Core/IResourceManager.h"
#include <SFML/Graphics.hpp>

using sf::Color;

namespace Goblin
{
	class DLLEXPORT RenderEngine
	{
	private:

		// Static stuff
		static const unsigned _mapTextureSize = 512;

		// Scene to draw
		Scene& _scene;

		// The player
		Player::PlayerId _player;
		FloatRect _viewport;

		// The map
		bool _mapNeedsRendering;
		Array2<sf::Texture>* _mapTextures;

		// Resources
		IResourceManager& _resources;

		/// <summary>Converts from cartesian to isometric coordinates.</summary>
		/// <param name="coord">The coordinates.</param>
		/// <returns>Isometric coordinates.</returns>
		static Vector2f iso(Vector2f coord);

		/// <summary>Converts from isometric to cartesian coordinates.</summary>
		/// <param name="coord">The coordinates.</param>
		/// <returns>Cartesian coordinates.</returns>
		static Vector2f cart(Vector2f coord);

		/// <summary>Gets the texture name for this type of terrain.</summary>
		/// <param name="terrain">The terrain type.</param>
		/// <returns>The texture name.</returns>
		static std::string getTextureName(int terrain);

		/// <summary>Gets pixel of cartesian map.</summary>
		/// <param name="x">The x coordinate.</param>
		/// <param name="y">The y coordinate.</param>
		/// <returns>The pixel.</returns>
		Color getCartMapPixel(float x, float y);

		/// <summary>Gets pixel of isometric map.</summary>
		/// <param name="x">The x coordinate.</param>
		/// <param name="y">The y coordinate.</param>
		/// <returns>The pixel.</returns>
		/// <remarks>This converts the isometric position to a cartesian position,
		/// and returns the corresponding pixel of the isometric map.</remarks>
		Color getIsoMapPixel(unsigned x, unsigned y);

		/// <summary>Renders a map cell.</summary>
		/// <param name="x">The x coordinate.</param>
		/// <param name="y">The y coordinate.</param>
		/// <remarks>Note that this reffers to a texture cell, and not
		/// a game map cell.</remarks>
		void renderMapCell(unsigned x, unsigned y);

		/// <summary>Renders a map area.</summary>
		/// <param name="left">The left coordinate.</param>
		/// <param name="top">The top coordinate.</param>
		/// <param name="right">The right coordinate.</param>
		/// <param name="bottom">The bottom coordinate.</param>
		/// <remarks>The ranges reffer to texture cell coordinates, and not
		/// a game map cell.</remarks>
		void renderMapArea(unsigned left, unsigned top, unsigned right, unsigned bottom);

	public:
		RenderEngine(IResourceManager& resources, Scene& scene, Player::PlayerId player);
		virtual ~RenderEngine();

		virtual void render(sf::RenderTarget& target);
	};

}