#pragma once
#include "ieventcallback.h"

namespace Goblin
{
	/// <summary>Callback using global functions.</summary>
	/// <typeparam name="EventArgs">Event arguments class.</typeparam>
	template <class EventArgs>
	class BasicEventCallback : public IEventCallback<EventArgs>
	{
	public:
		/// <summary>Defines a pointer to a global function, which takes an EventArgs constant reference.</summary>
		typedef void (*Function) (const EventArgs& args);

	private:
		Function func;

	public:

		/// <summary>Constructor.</summary>
		/// <param name="f">The global function.</param>
		BasicEventCallback(Function f) 
			: func(f)
		{
		}

		/// <summary>Destructor.</summary>
		virtual ~BasicEventCallback(void)
		{
		}

		/// <summary>Performs callback, by calling the global function.</summary>
		/// <param name="args">Event arguments.</param>
		virtual void run(const EventArgs& args)
		{
			if (func != NULL)
				(*func)(args);
		}
	};

}