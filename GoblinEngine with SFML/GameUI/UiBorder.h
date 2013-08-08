#pragma once

#include "UiElement.h"
#include "../Core/Build.h"

namespace Goblin {

	class DLLEXPORT UiBorder: public UiElement {
	public:
		UiBorder();
		virtual ~UiBorder();

		virtual bool handleEvent(const sf::Event& e);
		virtual void render(sf::RenderTarget& target, sf::FloatRect bounds);
	};

}