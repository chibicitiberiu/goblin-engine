#pragma once
#include <set>
#include <SFML\Graphics.hpp>
#include "UiPanel.h"
#include "../Core/Build.h"

namespace Goblin {

	class DLLEXPORT WindowManager {

	protected:
		UiPanel root;
		sf::Texture texture;
		int dpi;

	public:

		WindowManager();
		virtual ~WindowManager();

		virtual bool handleEvent(const sf::Event& e);
		virtual void render(sf::RenderTarget& target);
		virtual UiPanel& getRoot();
	};

}  // namespace Glass