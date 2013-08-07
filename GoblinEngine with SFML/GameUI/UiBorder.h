#pragma once

#include "UiElement.h"

namespace Goblin {

class UiBorder: public UiElement {
public:
	UiBorder();
	virtual ~UiBorder();

	virtual bool handleEvent(const sf::Event& e);
	virtual void render(sf::RenderTarget& target, sf::FloatRect bounds);
};

}