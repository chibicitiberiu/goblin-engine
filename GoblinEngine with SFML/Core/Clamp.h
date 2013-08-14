#pragma once
#include <algorithm>

namespace Goblin {

	/// <summary>Limits the given value between a minimum and maximum.</summary>
	/// <param name="value">The value to be clamped.</param>
	/// <param name="minimum">The minimum.</param>
	/// <param name="maximum">The maximum.</param>
	/// <returns>
	/// If value is less than minimum, minimum is returned. 
	/// If value is above maximum, maximum is returned.
	/// If value is between minimum and maximum, value is returned.
	/// </returns>
	template <typename A, typename B, typename C>
	A clamp (A value, B minimum, C maximum)
	{
		return std::min( std::max(value, minimum) , maximum);
	}

}  // namespace Goblin