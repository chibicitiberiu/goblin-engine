#include "GameObject.h"

namespace Goblin
{
	GameObject::GameObject(void)
		: components(new ComponentContainer()), 
		  actions(new ActionClassContainer())
	{
	}

	GameObject::GameObject(const GameObject& other)
		: components(new ComponentContainer(*other.components)),
		  actions(new ActionClassContainer(*other.actions))
	{
	}

	GameObject::~GameObject(void)
	{
		delete components;
		delete actions;
	}

	void GameObject::addActionClass(SmartPtr<ActionClass> actionClass)
	{
		this->actions->push_back(actionClass);
	}

	GameObject::ActionClassContainer::iterator GameObject::actionsBegin() const
	{
		return actions->begin();
	}

	GameObject::ActionClassContainer::iterator GameObject::actionsEnd() const
	{
		return actions->end();
	}

	Object* GameObject::clone() const
	{
		return new GameObject(*this);
	}
}