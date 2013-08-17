#pragma once

#include "Object.h"
#include "ISerializable.h"

namespace Goblin
{
	/// <summary>A game object component. A component defines new behavior for game objects.</summary>
	class DLLEXPORT Component : public Object /*, public ISerializable */
	{
	public:

		/// <summary>Destructor.</summary>
		virtual ~Component(void)
		{
		}
	};

}