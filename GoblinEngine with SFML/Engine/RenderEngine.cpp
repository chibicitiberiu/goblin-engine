#include "RenderEngine.h"
#include "../Core/Log.h"
#include <sstream>

namespace Goblin
{
	RenderEngine::RenderEngine(Scene& scene, IResourceManager& resources)
		: scene(scene), resources(resources)
	{
		renderMap();
	}

	RenderEngine::~RenderEngine()
	{
	}

	Vector2f RenderEngine::toIsometric(Vector2f coord)
	{
		return Vector2f(coord.x - coord.y, (coord.x + coord.y) / 2.0f);
	}

	Vector2f RenderEngine::toCartesian(Vector2f coord)
	{
		return Vector2f((2.0f * coord.y + coord.x) / 2.0f, (2.0f * coord.y - coord.x) / 2.0f);
	}

	void RenderEngine::renderMap()
	{
		char buffer[13];
		sf::Image mapImage;
		Vector2f mapsize = scene.getSizeAbsolute();
		Vector2u mapcells = scene.getSizeCells();

		// Create image
		mapImage.create(mapsize.x, mapsize.y);

		// Render every cell
		for (unsigned row = 0; row < mapcells.y; row++)
			for (unsigned col = 0; col < mapcells.x; col++)
			{
				// Get cell
				MapCell& cell = scene.map().get(col, row);
				Vector2f pos = scene.toAbsolute(col, row);

				// Get terrain texture
				sprintf_s(buffer, 13, "texture%d", cell.getTerrainType());
				sf::Image* img = (sf::Image*) resources.getResource(buffer);

				if (img == NULL)
				{
					debug<<Goblin::log<<"Resource '"<<buffer<<"' not found!\n";
					continue;
				}

				// Copy pixels
				mapImage.copy(*img, pos.x, pos.y);
			}

		// Now we need to create an image in isometric view
		Vector2f isoSize(mapsize.x * 2, mapsize.y);

		sf::Image isoImage;
		isoImage.create(isoSize.x, isoSize.y);

		for (unsigned y = 0; y < isoSize.y; y++)
			for (unsigned x = 0; x < isoSize.x; x++)
			{
				Vector2f isocoord(x - mapsize.x, y);
				Vector2f cartcoord = toCartesian(isocoord);

				if (0 <= cartcoord.x && cartcoord.x < mapsize.x && 0 <= cartcoord.y && cartcoord.y < mapsize.y)
				{
					sf::Color& pixel = mapImage.getPixel(cartcoord.x, cartcoord.y);
					isoImage.setPixel(x, y, pixel);
				}
			}

		// Create texture
		this->mapTexture.loadFromImage(isoImage);
	}

	void RenderEngine::render(sf::RenderTarget& target)
	{
		sf::Sprite mapSprite(mapTexture);

		target.draw(mapSprite);
	}
}