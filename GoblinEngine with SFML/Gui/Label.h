#pragma once
#include "widget.h"

namespace Goblin
{
	namespace Gui
	{
		class Label : public Widget
		{
		public:
			enum TextAlign {
				Left = 0x0,
				Center = 0x1,
				Right = 0x2,
				Top = 0x0,
				Middle = 0x10,
				Bottom = 0x20
			};

		private:
			sfg::Label::Ptr label;

		public:
			Label();
			Label(const sf::String& text);
			Label(sfg::Label::Ptr label);
			virtual ~Label();

			// Setters
			virtual void setText(const sf::String& value);
			virtual void setWrapping(bool value);
			virtual void setTextAlignment(const sf::Vector2f& value);
			virtual void setTextAlignment(float x, float y);
			virtual void setTextAlignment(int enumValue = Left | Top);

			// Getters
			virtual sf::String getText() const;
			virtual bool getWrapping(bool value) const;
			virtual sf::Vector2f getTextAlignment() const;
		};
	}
}

