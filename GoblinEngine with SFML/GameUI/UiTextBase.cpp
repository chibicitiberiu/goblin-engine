#include "UiTextBase.h"

namespace Goblin {

	UiTextBase::UiTextBase(void)
		: font(), textStyle(0), textSizePt(9.0f), text()
	{
	}


	UiTextBase::~UiTextBase(void)
	{
	}

	// Setters
	void UiTextBase::setFont(sf::Font& value)
	{
		this->font = value;
		this->onTextChanged();
	}

	void UiTextBase::setTextStyle(int value)
	{
		this->textStyle = value;
		this->onTextChanged();
	}

	void UiTextBase::setTextSize(float points)
	{
		this->textSizePt = points;
		this->onTextChanged();
	}

	void UiTextBase::setTextSize(unsigned pixels)
	{
		this->textSizePt = static_cast<float> (pixels * this->getDpi()) / 72.0f;
		this->onTextChanged();
	}

	void UiTextBase::setText(const std::string& value)
	{
		this->text = value;
		this->onTextChanged();
	}


	// Getters
	const sf::Font& UiTextBase::getFont() const
	{
		return this->font;
	}

	int UiTextBase::getTextStyle() const
	{
		return this->textStyle;
	}

	float UiTextBase::getTextSize() const
	{
		return this->textSizePt;
	}

	unsigned UiTextBase::getTextSizePx() const
	{
		return static_cast<unsigned> (this->textSizePt * 72.0f / static_cast<float>(this->getDpi()));
	}
	
	std::string UiTextBase::getText() const
	{
		return this->text;
	}

	// Render
	void UiTextBase::render(sf::RenderTarget& target, sf::FloatRect bounds)
	{
		sf::Text t(this->text, this->font, this->getTextSizePx());
		t.setColor(this->getForeground());
		t.setPosition(bounds.left, bounds.top);
		t.setStyle(this->getTextStyle());
		target.draw(t);
	}

	// Text changed
	void UiTextBase::onTextChanged()
	{
		sf::Text t(this->text, this->font, this->getTextSizePx());
		sf::FloatRect bounds = t.getGlobalBounds();
		this->setSize(bounds.width, bounds.height);
	}
}