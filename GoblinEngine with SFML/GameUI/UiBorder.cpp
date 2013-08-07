#include "UiBorder.h"

namespace Goblin {

	UiBorder::UiBorder() : UiElement()
	{
	}

	UiBorder::~UiBorder()
	{
	}

	bool UiBorder::handleEvent(const sf::Event& e)
	{
		return false;
	}

	void UiBorder::render(sf::RenderTarget& target, sf::FloatRect bounds)
	{
		if (this->getActualWidth() > 1 && this->getActualHeight() > 1)
		{
			sf::RectangleShape rect(this->getActualSize());
			rect.setOutlineColor(this->getBackground());
			rect.setOutlineThickness(1.0f);
			rect.setFillColor(this->getForeground());
			rect.setPosition(bounds.left, bounds.top);

			target.draw(rect);
		}
	}

}  // namespace Glass