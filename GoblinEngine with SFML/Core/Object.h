#pragma once

#include <vector>
#include "Build.h"

namespace Goblin
{
	/// <summary>A generic object.</summary>
	class DLLEXPORT Object
	{
	public:
		/// <summary>Destructor.</summary>
		virtual ~Object()
		{
		}

		/// <summary>Creates a clone of this object.</summary>
		/// <returns>The cloned object.</returns>
		virtual Object* clone() const = 0;
	};
}