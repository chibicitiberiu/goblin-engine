#pragma once
#include "Component.h"
#include "Array2.h"
#include "SmartPtr.h"
#include <SFML\Graphics.hpp>

using sf::Vector2f;
using sf::Vector2u;

namespace Goblin
{
	/// <summary>Map entity component. Defines behavior for positioning the object on the map.</summary>
	class DLLEXPORT MapEntityComponent : public Component
	{
	private:
		Vector2u gridPosition;
		Vector2f absolutePosition;
		SmartPtr<Array2<int> > gridShape;

	public:
	// Constructor, destructor
		/// <summary>Default constructor.</summary>
		MapEntityComponent(void);

		/// <summary>Destructor.</summary>
		virtual ~MapEntityComponent(void);
	
	// Getters
		/// <summary>Gets the absolute position of the object.</summary>
		/// <returns>The absolute position.</returns>
		virtual Vector2f getAbsolutePosition() const;

		/// <summary>Gets the grid position of the object.</summary>
		/// <returns>The grid position.</returns>
		virtual Vector2u getGridPosition() const;

		/// <summary>Gets the grid shape of the object.</summary>
		/// <returns>The grid shape.</returns>
		virtual const Array2<int>& getGridShape();

	// Setters
		/// <summary>Sets the grid position of the object.</summary>
		/// <param name="value">The new position.</param>
		virtual void setGridPosition(Vector2u value);

		/// <summary>Sets the grid position of the object.</summary>
		/// <param name="x">The x coordinate.</param>
		/// <param name="y">The y coordinate.</param>
		virtual void setGridPosition(unsigned x, unsigned y);

		/// <summary>Sets the absolute position of the object.</summary>
		/// <param name="value">The new position.</param>
		virtual void setAbsolutePosition(Vector2f value);

		/// <summary>Sets the absolute position of the object.</summary>
		/// <param name="x">The x coordinate.</param>
		/// <param name="y">The y coordinate.</param>
		virtual void setAbsolutePosition(float x, float y);

		/// <summary>Sets the grid shape of the object.</summary>
		/// <param name="shape">The shape.</param>
		virtual void setGridShape(SmartPtr<Array2<int> > shape);

	// Object base class
		/// <summary>Creates a clone of this object.</summary>
		/// <returns>The cloned object.</returns>
		virtual Object* clone() const;
	};
}