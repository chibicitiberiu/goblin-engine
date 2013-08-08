#pragma once
#include <sstream>
#include <Windows.h>
#include "Build.h"

namespace Goblin {

	class DLLEXPORT DebugStream
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

	extern DLLEXPORT DebugStream debug;

}