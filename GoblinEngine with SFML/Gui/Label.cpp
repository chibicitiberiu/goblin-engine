#include "Label.h"

namespace Goblin
{
	namespace Gui
	{	
		/***********************************
		 * Constructors, destructor        *
		 ***********************************/
		Label::Label(void)
		{
			label = sfg::Label::Create();
			this->setWidget(label);
		}
		
		Label::Label(const sf::String& text)
		{
			label = sfg::Label::Create(text);
			this->setWidget(label);
		}

		Label::Label(sfg::Label::Ptr label)
			: label(label)
		{
		}

		Label::~Label(void)
		{
		}

		/***********************************
		 * Setters                         *
		 ***********************************/
		void Label::setText(const sf::String& value)
		{
			label->SetText(value);
		}
		
		void Label::setWrapping(bool value)
		{
			label->SetLineWrap(value);
		}

		void Label::setTextAlignment(const sf::Vector2f& value)
		{
			label->SetAlignment(value);
		}

		void Label::setTextAlignment(float x, float y)
		{
			label->SetAlignment(sf::Vector2f(x, y));
		}

		void Label::setTextAlignment(int enumValue)
		{
			float x = 0.0f, y = 0.0f;

			if (enumValue & Label::Center)
				x = 0.5f;

			if (enumValue & Label::Right)
				x = 1.0f;

			if (enumValue & Label::Middle)
				y = 0.5f;

			if (enumValue & Label::Bottom)
				y = 1.0f;

			this->setTextAlignment(x, y);
		}

		/***********************************
		 * Getters                         *
		 ***********************************/
		sf::String Label::getText() const
		{
			return label->GetText();
		}
		
		bool Label::getWrapping(bool value) const
		{
			return label->GetLineWrap();
		}

		sf::Vector2f Label::getTextAlignment() const
		{
			return label->GetAlignment();
		}
	}
}