#pragma once
#include "Object.h"
#include "Action.h"
#include <map>

namespace Goblin
{
	class DLLEXPORT ActionClass : public Object
	{
	public:

		enum TargetType
		{
			None,
			Position,
			Enemy,
			GameObject
		};

		/// <summary>Gets the action's icon.</summary>
		/// <returns>The icon.</returns>
		virtual SmartPtr<sf::Image> getIcon() = 0;

		/// <summary>Gets the name of the action.</summary>
		/// <returns>The name.</returns>
		virtual std::string getName() = 0;

		/// <summary>Gets a brief description of the action.</summary>
		/// <returns>The description.</returns>
		virtual std::string getDescription() = 0;

		/// <summary>Gets the cost of the action.</summary>
		/// <param name="resourceType">Type of the resource.</param>
		/// <returns>The cost.</returns>
		virtual float getResourceCost(int resourceType) = 0;

		/// <summary>Determines if action requires a target.</summary>
		/// <returns>The target type.</returns>
		/// <remarks>Some actions require a target object. For example, an 'attack'
		/// action would require a target enemy.</remarks>
		virtual TargetType targetType() = 0;

		/// <summary>Determine if we can create an action.</summary>
		/// <param name="object">The game object.</param>
		/// <remarks>This is used to determine whether the action should be displayed
		/// in the action list.</remarks>
		/// <returns>True if we can create an action, false if not.</returns>
		virtual bool canCreateAction(Goblin::GameObject* object, const GameController* ctrl) = 0;

		/// <summary>Creates an action of this class.</summary>
		/// <param name="object">The game object.</param>
		/// <returns>The created action.</returns>
		virtual SmartPtr<Action> createAction(Goblin::GameObject* object, const GameController* ctrl) = 0;
		
		/// <summary>Destructor.</summary>
		virtual ~ActionClass(void)
		{
		}
	};
}