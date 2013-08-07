#pragma once
#include <algorithm>

namespace Goblin {

	template <typename A, typename B, typename C>
	A clamp (A value, B minimum, C maximum)
	{
		return std::min( std::max(value, minimum) , maximum);
	}

}  // namespace Goblin