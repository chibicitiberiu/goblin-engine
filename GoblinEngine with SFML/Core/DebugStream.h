#pragma once
#include <sstream>
#include <vector>
#include <cassert>
#include <Windows.h>
#include "Build.h"
#include "IDebugHandler.h"


namespace Goblin {

	class DLLEXPORT DebugStream
	{
	private:
		std::vector<IDebugHandler*>* handlers;

	public:

		DebugStream()
		{
			handlers = new std::vector<IDebugHandler*>();
		}

		~DebugStream()
		{
			for (auto it = handlers->begin(); it != handlers->end(); it++)
				delete *it;

			delete handlers;
		}

		void addHandler(IDebugHandler* handler)
		{
			assert(handler != NULL);
			handlers->push_back(handler);
		}

		template <typename T>
		DebugStream& operator<< (const T& t)
		{
			std::stringstream str;
			str<<t;

			for (auto it = handlers->begin(); it != handlers->end(); it++)
			{
				(*it)->write(str.str());
			}

			// OutputDebugStringA(str.str().c_str());
			return *this;
		}

	};

	extern DLLEXPORT DebugStream debug;

}