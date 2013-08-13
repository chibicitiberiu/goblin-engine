#include "Widget.h"

namespace Goblin
{
	namespace Gui
	{
		/***********************************
		 * Constructors, destructor        *
		 ***********************************/
		Widget::Widget()
		{
		}

		Widget::Widget(sfg::Widget::Ptr w)
			: widget(w)
		{
		}


		Widget::~Widget(void)
		{
		}

		/***********************************
		 * Getters                         *
		 ***********************************/
		sfg::Widget::Ptr Widget::getWidgetPtr() const
		{
			return this->widget;
		}
		
		sf::Vector2f Widget::getPosition() const
		{
			sf::FloatRect area = widget->GetAllocation();
			return sf::Vector2f(area.left, area.top);
		}

		sf::Vector2f Widget::getSize() const
		{
			sf::FloatRect area = widget->GetAllocation();
			return sf::Vector2f(area.width, area.height);
		}

		sf::Vector2f Widget::getMinSize() const
		{
			return widget->GetRequisition();
		}

		bool Widget::isVisible() const
		{
			return widget->IsLocallyVisible();
		}


		/***********************************
		 * Setters                         *
		 ***********************************/
		void Widget::setPosition(const sf::Vector2f& value)
		{
			sf::FloatRect area = widget->GetAllocation();
			area.left = value.x;
			area.top = value.y;

			widget->SetAllocation(area);
		}

		void Widget::setPosition(float x, float y)
		{
			sf::FloatRect area = widget->GetAllocation();
			area.left = x;
			area.top = y;

			widget->SetAllocation(area);
		}

		void Widget::setSize(const sf::Vector2f& value)
		{
			sf::FloatRect area = widget->GetAllocation();
			area.width = value.x;
			area.height = value.y;

			widget->SetAllocation(area);
		}
;
		void Widget::setSize(float x, float y)
		{
			sf::FloatRect area = widget->GetAllocation();
			area.width = x;
			area.height = y;

			widget->SetAllocation(area);
		}

		void Widget::setMinSize(const sf::Vector2f& value)
		{
			widget->SetRequisition(value);
		}

		void Widget::setMinSize(float x, float y)
		{
			widget->SetRequisition(sf::Vector2f(x, y));
		}
		
		void Widget::setIsVisible(bool value)
		{
			widget->Show(value);
		}

		void Widget::setWidget(sfg::Widget::Ptr widget)
		{
			this->widget = widget;
		}
	}
}