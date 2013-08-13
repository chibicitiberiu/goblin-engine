#pragma once
#include <SFGUI/SFGUI.hpp>
#include "../Core/Build.h"

namespace Goblin
{
	namespace Gui
	{
		class DLLEXPORT Widget
		{
		private:
			sfg::Widget::Ptr widget;

		protected:
			Widget();
			virtual void setWidget(sfg::Widget::Ptr widget);

		public:
			Widget(sfg::Widget::Ptr w);
			~Widget(void);
			
			// Setters
			virtual void setPosition(const sf::Vector2f& value);
			virtual void setPosition(float x, float y);
			virtual void setSize(const sf::Vector2f& value);
			virtual void setSize(float x, float y);
			virtual void setMinSize(const sf::Vector2f& value);
			virtual void setMinSize(float x, float y);
			virtual void setIsVisible(bool value);

			// Getters
			virtual sf::Vector2f getPosition() const;
			virtual sf::Vector2f getSize() const;
			virtual sf::Vector2f getMinSize() const;
			virtual sfg::Widget::Ptr getWidgetPtr() const;
			virtual bool isVisible() const;
		};
	}
}


