#include "GameObject.h"

namespace Goblin
{
	GameObject::GameObject(void)
		: components(new std::vector<SmartPtr<Component> >())
	{
	}

	GameObject::GameObject(const GameObject& other)
		: components(new std::vector<SmartPtr<Component> >(*other.components))
	{
	}

	GameObject::~GameObject(void)
	{
		if (components != NULL)
			delete components;
	}

	Object* GameObject::clone() const
	{
		return new GameObject(*this);
	}
}