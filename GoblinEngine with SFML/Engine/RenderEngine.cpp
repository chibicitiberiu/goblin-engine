#include "RenderEngine.h"
#include "../Core/Log.h"
#include <sstream>

namespace Goblin
{
	RenderEngine::RenderEngine(IResourceManager& resources, Scene& scene, Player::PlayerId player)
		: _scene(scene), 
		  _player(player),
		  _viewport(0, 0, 1000, 1000),
		  _mapNeedsRendering(true),
		  _mapTextures(NULL),
		  _resources(resources)
	{
		float w = ceilf((scene.getSizeAbsolute().x * 2) / static_cast<float>(_mapTextureSize));
		float h = ceilf(scene.getSizeAbsolute().y / static_cast<float>(_mapTextureSize));

		_mapTextures = new Array2<sf::Texture>(static_cast<unsigned>(w), static_cast<unsigned>(h));
	}

	RenderEngine::~RenderEngine()
	{
		delete _mapTextures;
	}

	Vector2f RenderEngine::iso(Vector2f coord)
	{
		return Vector2f(coord.x - coord.y, (coord.x + coord.y) / 2.0f);
	}

	Vector2f RenderEngine::cart(Vector2f coord)
	{
		return Vector2f((2.0f * coord.y + coord.x) / 2.0f, (2.0f * coord.y - coord.x) / 2.0f);
	}

	std::string RenderEngine::getTextureName(int terrain)
	{
		char buffer[13];
		sprintf_s(buffer, 13, "terrain%d", terrain);
		return std::string(buffer);
	}

	Color RenderEngine::getCartMapPixel(float x, float y)
	{
		// Cache the last image
		static unsigned last_cell_x = 0, last_cell_y = 0;
		static sf::Image* lastImage = NULL;

		// Get map size
		Vector2f size = _scene.getSizeAbsolute();
		Vector2u cells = _scene.getSizeCells();
		Vector2f cellsize(size.x / static_cast<float>(cells.x), size.y / static_cast<float>(cells.y));

		// Calculate cell
		unsigned cell_x = static_cast<unsigned>(x / cellsize.x);
		unsigned cell_y = static_cast<unsigned>(y / cellsize.y);

		// If cached image is not good, or there is no cached image, get image
		if (lastImage == NULL || cell_x != last_cell_x || cell_y != last_cell_y)
		{
			MapCell& cell = _scene.map().get(cell_x, cell_y);
			std::string texname = getTextureName(cell.getTerrainType());
			lastImage = (sf::Image*)_resources.getResource(texname);

			// Still no image? Fail gracefully.
			if (lastImage == NULL)
			{
				debug<<Goblin::log<<"Failed to get texture '"<<texname<<"'!\n";
				return Color();
			}
		}

		// Save cell number
		last_cell_x = cell_x;
		last_cell_y = cell_y;

		// Got everything we need, so now we can get the pixel
		unsigned px = static_cast<unsigned>(x - static_cast<float>(cell_x) * cellsize.x);
		unsigned py = static_cast<unsigned>(y - static_cast<float>(cell_y) * cellsize.y);
		return lastImage->getPixel(px, py);
	}

	Color RenderEngine::getIsoMapPixel(unsigned x, unsigned y)
	{
		Vector2f size = _scene.getSizeAbsolute();

		// We need to transpose the x coordinate. Isometric width = 2 * cartesian width
		float xx = static_cast<float>(x) - size.x;
		float yy = static_cast<float>(y);

		// Get cartesian coordinates
		Vector2f c = cart(Vector2f(xx, yy));

		// Get cartesian map pixel
		if (0 <= c.x && c.x < size.x && y <= c.y && c.y < size.y)
			return getCartMapPixel(c.x, c.y);
		
		return Color();
	}

	void RenderEngine::renderMapCell(unsigned cell_x, unsigned cell_y)
	{
		// Create image
		sf::Image img;
		img.create(_mapTextureSize, _mapTextureSize);

		// Render every pixel
		for (unsigned y = 0; y < _mapTextureSize; y++)
		{
			for (unsigned x = 0; x < _mapTextureSize; x++)
			{
				Color c = getIsoMapPixel(cell_x * _mapTextureSize + x, cell_y * _mapTextureSize + y);
				img.setPixel(x, y, c);
			}
		}

		// Create texture
		sf::Texture texture;
		texture.loadFromImage(img);

		// Place texture
		_mapTextures->set(cell_x, cell_y, texture);
	}

	void RenderEngine::renderMapArea(unsigned left, unsigned top, unsigned right, unsigned bottom)
	{
		for (unsigned y = top; y < bottom; y++)
			for (unsigned x = left; x < right; x++)
				renderMapCell(x, y);
	}

	void RenderEngine::render(sf::RenderTarget& target)
	{
		if (_mapNeedsRendering)
		{
			sf::Clock clock;

			renderMapArea(0, 0, _mapTextures->getWidth(), _mapTextures->getHeight());
			_mapNeedsRendering = false;

			debug<<Goblin::log<<"Rendering map took: "<<clock.getElapsedTime().asMilliseconds()<<" ms.\n";
		}

		for (unsigned y = 0; y < _mapTextures->getHeight(); y++)
			for (unsigned x = 0; x < _mapTextures->getWidth(); x++)
			{
				sf::Sprite spr(_mapTextures->get(x, y));
				spr.setPosition(static_cast<float>(x * _mapTextureSize) - _viewport.left, static_cast<float>(y * _mapTextureSize) - _viewport.top);
				target.draw(spr);
			}

		// Todo: draw only visible cells
	}
}