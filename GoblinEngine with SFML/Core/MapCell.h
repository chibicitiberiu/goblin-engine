#pragma once
#include <SFML\Graphics.hpp>
#include "Object.h"
#include "SmartPtr.h"
#include "GameObject.h"

using sf::Vector2f;

namespace Goblin
{
	class MapCell : public Object
	{
	private:
		int terrainType;
		float height;
		SmartPtr<GameObject> object;

	public:
	// Constructors
		/// <summary>Default constructor.</summary>
		MapCell(void);
		
		/// <summary>Destructor.</summary>
		virtual ~MapCell(void);

	// Getters
		/// <summary>Gets the terrain type.</summary>
		/// <returns>The terrain type.</returns>
		virtual int getTerrainType() const;

		/// <summary>Gets the height.</summary>
		/// <returns>The height.</returns>
		virtual float getHeight() const;

		/// <summary>Gets the object contained.</summary>
		/// <returns>The object.</returns>
		virtual GameObject& getObject();

	// Setters
		/// <summary>Sets terrain type.</summary>
		/// <param name="value">The value.</param>
		virtual void setTerrainType(int value);

		/// <summary>Sets height.</summary>
		/// <param name="value">The value.</param>
		virtual void setHeight(float value);

		/// <summary>Sets the game object contained.</summary>
		/// <param name="object">The object.</param>
		virtual void setObject(SmartPtr<GameObject> object);

	// Object
		/// <summary>Creates a clone of this object.</summary>
		/// <returns>The cloned object.</returns>
		virtual Object* clone() const;
	};
}