#include "UiElement.h"

namespace Goblin {

/*************************
 *  Constructors         *
 *************************/

UiElement::UiElement()
{
	// Layout
	this->align = (UiAlign) (UiAlignCenter | UiAlignMiddle);
	this->max_size = sf::Vector2f(10000, 10000);
	this->z_index = 0;

	// Parenting
	this->parent = NULL;
	this->parent_data = NULL;

	// Misc
	this->enabled = true;
	//this->needsRedraw = true;
}

UiElement::~UiElement()
{
}

/*************************
 *  Events               *
 *************************/
void UiElement::onLayoutChanged()
{
	//this->setNeedsRedraw(true);
}

void UiElement::onAppearanceChanged()
{
	//this->setNeedsRedraw(true);
}

void UiElement::onEnabledChanged()
{
	//this->setNeedsRedraw(true);
}


/*************************
 *  Setters: layout      *
 *************************/
void UiElement::setPosition(const sf::Vector2f& value)
{
	this->position = value;
	this->onLayoutChanged();
}

void UiElement::setPosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
	this->onLayoutChanged();
}

void UiElement::setX(float value)
{
	this->position.x = value;
	this->onLayoutChanged();
}

void UiElement::setY(float value)
{
	this->position.y = value;
	this->onLayoutChanged();
}

void UiElement::setSize(const sf::Vector2f& value)
{
	this->size = value;
	this->onLayoutChanged();
}

void UiElement::setSize(float w, float h)
{
	this->size.x = w;
	this->size.y = h;
	this->onLayoutChanged();
}

void UiElement::setWidth(float value)
{
	this->size.x = value;
	this->onLayoutChanged();
}

void UiElement::setHeight(float value)
{
	this->size.y = value;
	this->onLayoutChanged();
}

void UiElement::setMaxSize(const sf::Vector2f& value)
{
	this->max_size = value;
	this->onLayoutChanged();
}

void UiElement::setMaxSize(float w, float h)
{
	this->max_size.x = w;
	this->max_size.y = h;
	this->onLayoutChanged();
}

void UiElement::setMaxWidth(float value)
{
	this->max_size.x = value;
	this->onLayoutChanged();
}

void UiElement::setMaxHeight(float value)
{
	this->max_size.y = value;
	this->onLayoutChanged();
}

void UiElement::setMinSize(const sf::Vector2f& value)
{
	this->min_size = value;
	this->onLayoutChanged();
}

void UiElement::setMinSize(float w, float h)
{
	this->min_size.x = w;
	this->min_size.y = h;
	this->onLayoutChanged();
}

void UiElement::setMinWidth(float value)
{
	this->min_size.x = value;
	this->onLayoutChanged();
}

void UiElement::setMinHeight(float value)
{
	this->min_size.y = value;
	this->onLayoutChanged();
}

void UiElement::setZIndex(int value)
{
	this->z_index = value;
	this->onLayoutChanged();
}

void UiElement::setAlign(int value)
{
	this->align = value;
	this->onLayoutChanged();
}

void UiElement::setActualSize(const sf::Vector2f& value)
{
	this->actual_size = value;
}

void UiElement::setActualSize(float w, float h)
{
	this->actual_size.x = w;
	this->actual_size.y = h;
}

void UiElement::setActualWidth(float value)
{
	this->actual_size.x = value;
}

void UiElement::setActualHeight(float value)
{
	this->actual_size.y = value;
}


/*************************
 *  Setters: Appearance  *
 *************************/
void UiElement::setBackground(const sf::Color& value)
{
	this->back = value;
	this->onAppearanceChanged();
}

void UiElement::setForeground(const sf::Color& value)
{
	this->fore = value;
	this->onAppearanceChanged();
}
/*************************
 *  Setters: Parenting   *
 *************************/
void UiElement::setParent(UiElement* el)
{
	this->parent = el;

	// Need draw?
	//if (el != NULL && this->getNeedsRedraw())
	//	this->parent->setNeedsRedraw(true);
}

void UiElement::setParentData(void* value)
{
	this->parent_data = value;
}

/*************************
 *  Setters: Other       *
 *************************/
void UiElement::setEnabled(bool value)
{
	this->enabled = value;
	this->onEnabledChanged();
}

void UiElement::setDpi(int value)
{
	this->dpi = value;
}

//void UiElement::setNeedsRedraw(bool value)
//{
//	this->needsRedraw = value;
//
//	if (this->hasParent() && value)
//		this->getParent()->setNeedsRedraw(true);
//}


/*************************
 *  Getters: Layout      *
 *************************/
sf::Vector2f UiElement::getPosition() const
{
	return this->position;
}

float UiElement::getX() const
{
	return this->position.x;
}

float UiElement::getY() const
{
	return this->position.y;
}

sf::Vector2f UiElement::getSize() const
{
	return this->size;
}

float UiElement::getWidth() const
{
	return this->size.x;
}

float UiElement::getHeight() const
{
	return this->size.y;
}

sf::Vector2f UiElement::getMaxSize() const
{
	return this->max_size;
}

float UiElement::getMaxWidth() const
{
	return this->max_size.x;
}

float UiElement::getMaxHeight() const
{
	return this->max_size.y;
}

sf::Vector2f UiElement::getMinSize() const
{
	return this->min_size;
}

float UiElement::getMinWidth() const
{
	return this->min_size.x;
}

float UiElement::getMinHeight() const
{
	return this->min_size.y;
}

sf::Vector2f UiElement::getActualSize() const
{
	return this->actual_size;
}

float UiElement::getActualWidth() const
{
	return this->actual_size.x;
}

float UiElement::getActualHeight() const
{
	return this->actual_size.y;
}

int UiElement::getAlign() const
{
	return this->align;
}

int UiElement::getZIndex() const
{
	return this->z_index;
}

/*************************
 *  Getters: Appearance  *
 *************************/
sf::Color UiElement::getBackground() const
{
	return this->back;
}

sf::Color UiElement::getForeground() const
{
	return this->fore;
}

/*************************
 *  Getters: Parenting   *
 *************************/
bool UiElement::hasParent() const
{
	return (this->parent != NULL);
}

UiElement* UiElement::getParent() const
{
	return this->parent;
}

void* UiElement::getParentData() const
{
	return this->parent_data;
}

/*************************
 *  Getters: Other       *
 *************************/
bool UiElement::getEnabled() const
{
	return this->enabled;
}

int UiElement::getDpi() const
{
	return this->dpi;
}

//bool UiElement::getNeedsRedraw() const
//{
//	return this->needsRedraw;
//}

}