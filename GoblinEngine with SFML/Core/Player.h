#pragma once

#include <string>
#include <map>
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include "Array2.h"

using sf::Color;
using sf::FloatRect;

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

		// Array of visible-to-player and explored areas
		Array2<float>* _visible;
		Array2<float>* _explored;

	public:
	// Constructor
		/// <summary>Constructor.</summary>
		/// <param name="id">The player's unique identifier.</param>
		/// <param name="name">(Optional) the player's name.</param>
		/// <param name="color">(Optional) the player's color.</param>
		Player(PlayerId id, std::string name="Player", Color color=Color());
		
		/// <summary>Destructor.</summary>
		virtual ~Player();

		/// <summary>Creates map of visible and explored cells.</summary>
		/// <param name="map_width">Width of the map.</param>
		/// <param name="map_height">Height of the map.</param>
		virtual void createVisibleExplored(size_t map_width, size_t map_height);

	// Setters
		/// <summary>Sets player's color.</summary>
		/// <param name="value">The color.</param>
		virtual void setColor(const Color& value);

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

		/// <summary>Gets the map of explored cells.</summary>
		/// <returns>The map of explored cells.</returns>
		virtual Array2<float>& explored();

		/// <summary>Query if this object has an 'explored' map.</summary>
		/// <returns>True if it has, false if not.</returns>
		virtual bool hasExploredMap() const;

		/// <summary>Gets the map of cells visible to the player.</summary>
		/// <returns>The map of visible cells.</returns>
		virtual Array2<float>& visible();

		/// <summary>Query if this object has visible map.</summary>
		/// <returns>True if it has visible map, false if not.</returns>
		virtual bool hasVisibleMap() const;

	// Object
		/// <summary>Creates a clone of this object.</summary>
		/// <returns>The cloned object.</returns>
		virtual Object* clone() const override;
	};

}