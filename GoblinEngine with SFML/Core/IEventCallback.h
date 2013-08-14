#pragma once
#include "Build.h"

namespace Goblin
{
	template <class EventArgs>
	class DLLEXPORT IEventCallback
	{
	public:

		virtual ~IEventCallback() 
		{
		}

		virtual void run(const EventArgs& args) = 0;
		
		void operator() (const EventArgs& args)
		{
			run(args);
		}
	};
}