#pragma once
#include "Build.h"

namespace Goblin
{
	/// <summary>Event callback interface.</summary>
	/// <typeparam name="EventArgs">Event arguments class.</typeparam>
	template <class EventArgs>
	class IEventCallback
	{
	public:

		/// <summary>Destructor.</summary>
		virtual ~IEventCallback() 
		{
		}

		/// <summary>Performs callback, with specified event arguments.</summary>
		/// <param name="args">Event arguments.</param>
		virtual void run(const EventArgs& args) = 0;
		
		/// <summary>Performs callback, with specified event arguments.</summary>
		/// <param name="args">Event arguments.</param>
		void operator() (const EventArgs& args)
		{
			run(args);
		}
	};
}