#pragma once
#include <sstream>
#include <Windows.h>

namespace Goblin {

class DebugStream
{
public:

	template <typename T>
	DebugStream& operator<< (const T& t)
	{
		std::stringstream str;
		str<<t;

		OutputDebugStringA(str.str().c_str());
		return *this;
	}

};

extern DebugStream debug;

}