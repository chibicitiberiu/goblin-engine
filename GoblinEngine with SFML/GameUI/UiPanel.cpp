#include "UiPanel.h"
#include "../Core/Clamp.h"

namespace Goblin {

	UiPanel::UiPanel() : UiContainer()
	{
		this->setBackground(sf::Color::Transparent);
	}

	UiPanel::~UiPanel()
	{
	}

	bool UiPanel::handleEvent(const sf::Event& e)
	{
		return false;
	}


	void UiPanel::renderChildren(sf::RenderTarget& target, sf::FloatRect bounds)
	{
		// Render every child
		for (ChildrenIterator it = childrenBegin(); it != childrenEnd(); it++)
		{
			// Calculate new size & position
			sf::Vector2f size = this->calculateSize(**it, this->getActualSize());
			sf::Vector2f pos = this->calculatePosition(**it, size, this->getActualSize());

			(*it)->setActualSize(size);

			// Render
			(*it)->render(target, sf::FloatRect(bounds.left + pos.x, bounds.top + pos.y, size.x, size.y));
		}
	}

	sf::Vector2f UiPanel::calculatePosition(const UiElement& element, const sf::Vector2f& size, const sf::Vector2f& containerSize)
	{
		// Get values
		sf::Vector2f pos = element.getPosition();
		int align = element.getAlign();

		// Horizontal align
		if ( (align & UiAlignStretchHor) || (align & UiAlignCenter) )
			pos.x = 0.5f * (containerSize.x - size.x);

		else if (align & UiAlignLeft)
			pos.x = 0;

		else if (align & UiAlignRight)
			pos.x = containerSize.x - size.x;

		// Vertical align
		if ( (align & UiAlignStretchVert) || (align & UiAlignMiddle) )
			pos.y = 0.5f * (containerSize.y - size.y);

		else if (align & UiAlignTop)
			pos.y = 0;

		else if (align & UiAlignBottom)
			pos.y = containerSize.y - size.y;

		// Done
		return pos;
	}

	sf::Vector2f UiPanel::calculateSize(const UiElement& element, const sf::Vector2f& containerSize)
	{
		// Get values
		sf::Vector2f minSize = element.getMinSize();
		sf::Vector2f maxSize = element.getMaxSize();
		sf::Vector2f size = element.getSize();
		int align = element.getAlign();

		// Set value
		size.x = clamp(size.x, minSize.x, maxSize.x);
		size.y = clamp(size.y, minSize.y, maxSize.y);

		// Stretched horizontally?
		if (align & UiAlignStretchHor)
			size.x = clamp(containerSize.x, minSize.x, maxSize.x);

		// Stretched vertically?
		if (align & UiAlignStretchVert)
			size.y = clamp(containerSize.y, minSize.y, maxSize.y);

		// Done
		return size;
	}

	void UiPanel::render(sf::RenderTarget& target, sf::FloatRect bounds)
	{
		// Render every component
		this->renderChildren(target, bounds);
	}

	void UiPanel::addChild(UiElement* el)
	{
		UiContainer::addChild(el);

		std::sort(this->childrenBegin(), this->childrenEnd(), ZIndexComparator());
	}


}  // namespace Goblin