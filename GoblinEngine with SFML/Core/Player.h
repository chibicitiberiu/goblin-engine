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
		PlayerId id;

		// Player's name
		std::string name;

		// Player's color
		Color color;

		// Player's total resources
		typedef std::map<int, float> ResourceDictionary;
		ResourceDictionary resources;
		
	public:
		// List of selected objects. Each object must be unique.
		typedef std::vector<SmartPtr<GameObject> > SelectedObjectsContainer;
		SelectedObjectsContainer* selectedObjects;

		Player(PlayerId id, std::string name="Player", Color color=Color());
		virtual ~Player();

		void setColor(Color value);
		void setName(const std::string& value);

		Color getColor() const;
		std::string getName() const;

		virtual Object* clone() const override;
	};

}