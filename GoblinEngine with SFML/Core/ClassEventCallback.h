#pragma once
#include "IEventCallback.h"

namespace Goblin
{
	/// <summary>Callback using class member function.</summary>
	/// <typeparam name="AnyClass">Class which has function.</typeparam>
	/// <typeparam name="EventArgs">Event arguments class.</typeparam>
	template <class AnyClass, class EventArgs>
	class ClassEventCallback : public IEventCallback<EventArgs>
	{
	public:
		/// <summary>Defines a pointer to a class member function.</summary>
		typedef void (AnyClass::*Function) (const EventArgs& args);

	private:

		AnyClass* obj;
		Function func;

	public:

		/// <summary>Constructor.</summary>
		/// <param name="object">The object which will be used as 'this' parameter.</param>
		/// <param name="f">The class member function.</param>
		ClassEventCallback(AnyClass* object, Function f)
			: obj(object), func(f)
		{
		}

		/// <summary>Destructor.</summary>
		virtual ~ClassEventCallback(void)
		{
		}

		/// <summary>Performs callback, by calling the class member function</summary>
		/// <param name="args">Event arguments.</param>
		virtual void run(const EventArgs& args)
		{
			if (obj != NULL && func != NULL)
				(*obj.*func) (args);
		}
	};

}