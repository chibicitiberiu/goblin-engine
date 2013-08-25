#pragma once

#include <string>
#include <map>
#include <SFML\Graphics.hpp>
#include "GameObject.h"

using sf::Color;

namespace Goblin
{
	class DLLEXPORT Player : public Object
	{
	public:
		typedef int PlayerId;

	private:

		// Player's id
		PlayerId _id;

		// Player's name
		std::string _name;

		// Player's color
		Color _color;

		// Player's total resources
	public:
		typedef std::map<int, float> ResourceDictionary;
	
	private:
		ResourceDictionary* _resources;
		
		// List of selected objects. Each object must be unique.
	public:
		typedef std::vector<SmartPtr<GameObject> > SelectedObjectsContainer;
	
	private:
		SelectedObjectsContainer* _selectedObjects;

	public:
	// Constructor
		/// <summary>Constructor.</summary>
		/// <param name="id">The player's unique identifier.</param>
		/// <param name="name">(Optional) the player's name.</param>
		/// <param name="color">(Optional) the player's color.</param>
		Player(PlayerId id, std::string name="Player", Color color=Color());
		
		/// <summary>Destructor.</summary>
		virtual ~Player();

	// Setters
		/// <summary>Sets player's color.</summary>
		/// <param name="value">The color.</param>
		virtual void setColor(Color value);

		/// <summary>Sets player's name.</summary>
		/// <param name="value">The name.</param>
		virtual void setName(const std::string& value);

	// Getters
		/// <summary>Gets the player's unique identifier.</summary>
		/// <returns>The identifier.</returns>
		virtual PlayerId getId() const;

		/// <summary>Gets the player's color.</summary>
		/// <returns>The color.</returns>
		virtual Color getColor() const;

		/// <summary>Gets the player's name.</summary>
		/// <returns>The name.</returns>
		virtual std::string getName() const;

		/// <summary>Gets the resources dictionary.</summary>
		/// <returns>Resource dictionary.</returns>
		virtual ResourceDictionary& resources();

		/// <summary>Gets the selected objects.</summary>
		/// <returns>Selected objects.</returns>
		virtual SelectedObjectsContainer& selectedObjects();

	// Object
		/// <summary>Creates a clone of this object.</summary>
		/// <returns>The cloned object.</returns>
		virtual Object* clone() const override;
	};

}