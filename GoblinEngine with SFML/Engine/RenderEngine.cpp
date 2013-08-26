#include "RenderEngine.h"

namespace Goblin
{
	RenderEngine::RenderEngine()
	{
	}

	RenderEngine::~RenderEngine()
	{
	}

	void RenderEngine::render(sf::RenderTarget& target)
	{
		sf::CircleShape circle(50.0f);
		circle.setFillColor(sf::Color::Green);
		circle.setPosition(100, 100);
		target.draw(circle);
	}
}