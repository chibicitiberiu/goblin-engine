#pragma once
#include "Object.h"
#include "SmartPtr.h"
#include <SFML\Graphics.hpp>

using sf::Vector2f;

namespace Goblin
{
	class GameObject;

	/// <summary>An action which is being performed by a game object.</summary>
	/// <remarks>This class defines the logic behind the action, as opposed to
	/// ActionClass, which holds information about the action.</remarks>
	class DLLEXPORT Action : public Object
	{
	public:

		/// <summary>Sets the game object linked to this action.</summary>
		/// <param name="obj">The game object.</param>
		/// <remarks>This function sets the game object which is linked to this action.
		/// The state of the game object may change until the action is executed.</remarks>
		virtual void setObject(SmartPtr<GameObject> obj) = 0;

		/// <summary>Executed just before the action starts.</summary>
		/// <remarks>This function can be overriden to perform initializing when the state 
		/// of the game object is required.</remarks>
		virtual void onActionStarted()
		{
		}

		/// <summary>Updates the logic of the current action.</summary>
		/// <param name="elapsed">The elapsed time since the last tick.</param>
		virtual void tick(const sf::Time& elapsed) = 0;

		/// <summary>Query if this action is finished.</summary>
		/// <remarks>An action could finish when a certain condition has been met,
		/// for example if a certain time has passed.</remarks>
		/// <returns>True if finished, false if not.</returns>
		virtual bool isFinished() = 0;

		/// <summary>Each action happens in a specific location. The object will first
		/// move to this location, before beginning the action.</summary>
		/// <returns>The action location.</returns>
		virtual Vector2f getActionLocation() = 0;

		/// <summary>Gets the estimated time remaining of the current action.</summary>
		/// <returns>A pointer to a time structure, or NULL if not available.</returns>
		/// <remarks>This function can be used to return how much time the action has remaining. 
		/// Alternatively, the progress can be used, or both. If not available, returns
		/// NULL. </remarks>
		virtual SmartPtr<sf::Time> getEta()
		{
			return SmartPtr<sf::Time>();
		}

		/// <summary>Gets the progress of the current action.</summary>
		/// <returns>A value between 0 and 1 indicating the progress. If outside this range,
		/// this means that progress is not available.</returns>
		/// <remarks>This function can be used to get a value indicating how much of the action
		/// is done. If the value is outside the range [0, 1], this means that progress is not
		/// available. </remarks>
		virtual float getProgress()
		{
			return -1.0f;
		}

		/// <summary>Destructor.</summary>
		virtual ~Action()
		{
		}
	};
}