#pragma once
#include "UiContainer.h"
#include "../Core/RenderImage.h"
#include "../Core/Build.h"
#include <map>

namespace Goblin {

	class DLLEXPORT UiPanel: public UiContainer {

	private:

		void renderChildren(sf::RenderTarget& target, sf::FloatRect bounds);
	
		sf::Vector2f calculatePosition(const UiElement& element, const sf::Vector2f& size, const sf::Vector2f& containerSize);
		sf::Vector2f calculateSize(const UiElement& element, const sf::Vector2f& containerSize);

		class ZIndexComparator
		{
		public:
			bool operator() (UiElement* a, UiElement* b)
			{
				return a->getZIndex() < b->getZIndex();
			}
		};

	public:
		UiPanel();
		virtual ~UiPanel();

		virtual bool handleEvent(const sf::Event& e);
		virtual void render(sf::RenderTarget& target, sf::FloatRect bounds);

		virtual void addChild(UiElement* el);
	};

}  // namespace Goblin
