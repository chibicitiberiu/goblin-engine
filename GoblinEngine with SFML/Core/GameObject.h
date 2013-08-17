#pragma once
#include "Object.h"
#include "SmartPtr.h"
#include "Component.h"
#include "Exception.h"
#include <typeinfo>
#include <vector>

namespace Goblin
{
	class DLLEXPORT GameObject : public Object
	{
	private:
		std::vector<SmartPtr<Component> >* components;

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
					return *it;

			throw EXCEPTION(NullReferenceException, "Component does not exist.");
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

	// Object
		/// <summary>Creates a clone of this object.</summary>
		/// <returns>The cloned object.</returns>
		virtual Object* clone() const;
	};
}