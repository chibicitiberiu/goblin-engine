#pragma once
#include "Object.h"
#include "SmartPtr.h"
#include "Component.h"
#include "Exception.h"
#include "ActionClass.h"
#include <typeinfo>
#include <vector>

namespace Goblin
{
	class Player;

	class DLLEXPORT GameObject : public Object
	{
	public:
		typedef std::vector<SmartPtr<ActionClass>> ActionClassContainer;

	private:

		typedef std::vector<SmartPtr<Component>> ComponentContainer;
		
		ComponentContainer* components;
		ActionClassContainer* actions;
		Player* player;

	public:

	// Constructor, destructor
		/// <summary>Default constructor.</summary>
		GameObject(void);

		/// <summary>Copy constructor.</summary>
		/// <param name="other">The game object to copy.</param>
		GameObject(const GameObject& other);

		/// <summary>Destructor.</summary>
		virtual ~GameObject(void);

	// Components
		/// <summary>Adds a component to the game object.</summary>
		/// <param name="component">The component.</param>
		void addComponent(SmartPtr<Component> component);

		/// <summary>Query if this object has a component of specified type.</summary>
		/// <typeparam name="T">Component type to verify.</typeparam>
		/// <returns>True if object has such component, false otherwise.</returns>
		template <class T>
		bool hasComponent()
		{
			for (auto it = components->begin(); it != components->end(); it++)
				if (typeid(T) == typeid(**it))
					return true;

			return false;
		}

		/// <summary>Gets the component of specified type.</summary>
		/// <typeparam name="T">Component type.</typeparam>
		/// <returns>A reference to the component, or exception if no such component exists.</returns>
		/// <exception cref="NullReferenceException">Thrown if component not found.</exception>
		template <class T>
		T& getComponent()
		{
			for (auto it = components->begin(); it != components->end(); it++)
				if (typeid(T) == typeid(**it))
					return dynamic_cast<T&> (**it);

			throw EXCEPTION(NullReferenceException, "Component does not exist.");
		}

		/// <summary>Gets the component of specified type.</summary>
		/// <typeparam name="T">Component type.</typeparam>
		/// <returns>A pointer to the component, or NULL if no such component exists.</returns>
		template <class T>
		T* tryGetComponent()
		{
			for (auto it = components->begin(); it != components->end(); it++)
				if (typeid(T) == typeid(**it))
					return dynamic_cast<T*>(it->ptr());

			return NULL;
		}

		/// <summary>Removes the component of specified type.</summary>
		/// <typeparam name="T">Component type.</typeparam>
		template <class T>
		void removeComponent()
		{
			for (auto it = components->begin(); it != components->end(); it++)
				if (typeid(T) == typeid(**it))
				{
					components->erase(it);
					return;
				}
		}

	// Action classes
		
		/// <summary>Adds an action class.</summary>
		/// <param name="actionClass">The action class.</param>
		void addActionClass(SmartPtr<ActionClass> actionClass);

		/// <summary>Gets an iterator to the beginning of the action classes list.</summary>
		/// <returns>An iterator to the beginning of the action list.</returns>
		ActionClassContainer::iterator actionsBegin() const;

		/// <summary>Gets an iterator to the end of the action classes list.</summary>
		/// <returns>An iterator to the position after the last action class.</returns>
		ActionClassContainer::iterator actionsEnd() const;

	// Player
		/// <summary>Gets the owner player.</summary>
		/// <returns>The player.</returns>
		virtual Player* getPlayer() const;

		/// <summary>Sets the owner player.</summary>
		/// <param name="value">The player.</param>
		virtual void setPlayer(Player* value);

	// Object
		/// <summary>Creates a clone of this object.</summary>
		/// <returns>The cloned object.</returns>
		virtual Object* clone() const;
	};
}