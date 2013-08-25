#pragma once
#include "Component.h"

namespace Goblin
{
	class MovableComponent : public Component
	{
		// TODO: add movement stuff: speed, acceleration, decceleration
	private:

		float angle;
		float speed, maxSpeed;
		float acceleration, deceleration;

	public:

		/// <summary>Default constructor.</summary>
		MovableComponent(void);

		/// <summary>Destructor.</summary>
		virtual ~MovableComponent(void);

	// Getters
		/// <summary>Gets the angle (direction).</summary>
		/// <returns>The angle.</returns>
		virtual float getAngle() const;

		/// <summary>Gets the current speed.</summary>
		/// <returns>The speed.</returns>
		virtual float getSpeed() const;

		/// <summary>Gets maximum speed.</summary>
		/// <returns>The maximum speed.</returns>
		virtual float getMaxSpeed() const;

		/// <summary>Gets the acceleration.</summary>
		/// <returns>The acceleration.</returns>
		virtual float getAcceleration() const;

		/// <summary>Gets the deceleration.</summary>
		/// <returns>The deceleration.</returns>
		virtual float getDeceleration() const;

	// Setters
		/// <summary>Sets the angle.</summary>
		/// <param name="value">The value.</param>
		virtual void setAngle(float value);

		/// <summary>Sets the speed.</summary>
		/// <param name="value">The value.</param>
		virtual void setSpeed(float value);

		/// <summary>Sets maximum speed.</summary>
		/// <param name="value">The value.</param>
		virtual void setMaxSpeed(float value);

		/// <summary>Sets the acceleration.</summary>
		/// <param name="value">The value.</param>
		virtual void setAcceleration(float value);

		/// <summary>Sets the deceleration.</summary>
		/// <param name="value">The value.</param>
		virtual void setDeceleration(float value);
	};
}