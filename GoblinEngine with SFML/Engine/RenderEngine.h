#pragma once
#include "../Core/Build.h"
#include <SFML/Graphics.hpp>

namespace Goblin
{
	class DLLEXPORT RenderEngine
	{
	public:
		RenderEngine();
		virtual ~RenderEngine();

		virtual void render(sf::RenderTarget& target);
	};

}