#pragma once
#include "ieventcallback.h"

namespace Goblin
{
	template <class EventArgs>
	class DLLEXPORT BasicEventCallback : public IEventCallback<EventArgs>
	{
	public:
		typedef void (*Function) (const EventArgs& args);

	private:
		Function func;

	public:

		BasicEventCallback(Function f) 
			: func(f)
		{
		}

		virtual ~BasicEventCallback(void)
		{
		}

		virtual void run(const EventArgs& args)
		{
			(*func)(args);
		}
	};

}