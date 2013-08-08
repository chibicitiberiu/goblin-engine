#pragma once
#include "UiElement.h"
#include "../Core/Build.h"

namespace Goblin {

	class DLLEXPORT UiTextBase: public Goblin::UiElement {

	private:
		sf::Font font;
		int textStyle;
		float textSizePt;
		std::string text;

	public:
		UiTextBase();
		virtual ~UiTextBase();

		// Render
		virtual void render(sf::RenderTarget& target, sf::FloatRect bounds);
		virtual void onTextChanged();

		// Setters
		virtual void setFont(sf::Font& value);
		virtual void setTextStyle(int value);
		virtual void setTextSize(float points);
		virtual void setTextSize(unsigned pixels);
		virtual void setText(const std::string& value);

		// Getters
		virtual const sf::Font& getFont() const;
		virtual int getTextStyle() const;
		virtual float getTextSize() const;
		virtual unsigned getTextSizePx() const;
		virtual std::string getText() const;


	};

} /* namespace Goblin */