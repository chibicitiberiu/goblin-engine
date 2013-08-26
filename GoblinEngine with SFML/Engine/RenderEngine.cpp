#include "RenderEngine.h"

namespace Goblin
{
	RenderEngine::RenderEngine(Scene& scene, IResourceManager& resources)
		: scene(scene), resources(resources)
	{
	}

	RenderEngine::~RenderEngine()
	{
	}

	void RenderEngine::render(sf::RenderTarget& target)
	{
		// Draw a circle
		sf::CircleShape circle(50.0f);
		circle.setFillColor(sf::Color::Green);
		circle.setPosition(100, 100);
		target.draw(circle);

		// Draw the image
		sf::Image* img = (sf::Image*) resources.getResource("img");

		if (img != NULL)
		{
			sf::Texture t;
			t.loadFromImage(*img);

			sf::Sprite s(t);
			s.setPosition(400, 400);

			target.draw(s);
		}
	}
}