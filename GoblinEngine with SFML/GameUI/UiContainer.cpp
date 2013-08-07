#include "UiContainer.h"
#include <cassert>

namespace Goblin {

UiContainer::UiContainer() : UiElement()
{
}

UiContainer::~UiContainer()
{
	for (ChildrenIterator it = childrenBegin(); it != childrenEnd(); it++)
		delete *it;
}

// Children getters
UiContainer::ChildrenIterator UiContainer::childrenBegin()
{
	return this->children.begin();
}

UiContainer::ChildrenIterator UiContainer::childrenEnd()
{
	return this->children.end();
}

size_t UiContainer::childrenCount()
{
	return this->children.size();
}

UiElement* UiContainer::child(size_t index)
{
	return this->children[index];
}

void UiContainer::addChild(UiElement* el)
{
	// Safety check
	assert (el != NULL);

	// Add
	el->setParent(this);
	el->setDpi(this->getDpi());
	this->children.push_back(el);
}

void UiContainer::removeChild(ChildrenIterator it)
{
	delete *it;
	this->children.erase(it);
}

void UiContainer::removeChild(size_t index)
{
	this->removeChild(this->childrenBegin() + index);
}

/*************************
 *  Events               *
 *************************/
void UiContainer::onLayoutChanged()
{
	UiElement::onLayoutChanged();

	//for (ChildrenIterator it = this->childrenBegin(); it != this->childrenEnd(); it++)
	//	(*it)->setNeedsRedraw(true);
}

void UiContainer::onAppearanceChanged()
{
	UiElement::onAppearanceChanged();

	//for (ChildrenIterator it = this->childrenBegin(); it != this->childrenEnd(); it++)
	//	(*it)->setNeedsRedraw(true);
}

void UiContainer::onEnabledChanged()
{
	UiElement::onEnabledChanged();

	//for (ChildrenIterator it = this->childrenBegin(); it != this->childrenEnd(); it++)
	//	(*it)->setNeedsRedraw(true);
}

}  // namespace Goblin