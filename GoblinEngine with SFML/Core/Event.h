#pragma once
#include "IEventCallback.h"
#include "BasicEventCallback.h"
#include "ClassEventCallback.h"
#include <cassert>
#include <vector>

namespace Goblin
{
	/// <summary>Defines an event.</summary>
	/// <typeparam name="EventArgs">Event arguments class.</typeparam>
	template <class EventArgs>
	class Event
	{
	private:
		std::vector< IEventCallback<EventArgs>* >* callbacks;

	public:

		/// <summary>Default constructor.</summary>
		Event(void)
			: callbacks(new std::vector< IEventCallback<EventArgs>* >())
		{
		}

		/// <summary>Destructor.</summary>
		virtual ~Event(void)
		{
			if (callbacks != NULL)
			{
				for (auto it = callbacks->begin(); it != callbacks->end(); it++)
					if (*it != NULL)
						delete *it;

				delete callbacks;
			}
		}

		/// <summary>Registers an event handler.</summary>
		/// <param name="h">The callback.</param>
		void addHandler(IEventCallback<EventArgs>* h)
		{
			callbacks->push_back(h);
		}

		/// <summary>Registers an event handler.</summary>
		/// <param name="f">A global function.</param>
		void addHandler(typename BasicEventCallback<EventArgs>::Function f)
		{
			callbacks->push_back(new BasicEventCallback<EventArgs>(f));
		}

		/// <summary>Registers an event handler.</summary>
		/// <typeparam name="AnyClass">Type of any class.</typeparam>
		/// <param name="object">The object which will be used as 'this' argument.</param>
		/// <param name="f">The class member function.</param>
		template <class AnyClass>
		void addHandler(AnyClass* object, typename ClassEventCallback<AnyClass, EventArgs>::Function f)
		{
			callbacks->push_back(new ClassEventCallback<AnyClass, EventArgs>(object, f));
		}

		/// <summary>Registers an event handler.</summary>
		/// <param name="h">The callback.</param>
		/// <returns>Reference to this.</returns>
		Event& operator+= (IEventCallback<EventArgs>* h)
		{
			this->addHandler(h);
			return *this;
		}

		/// <summary>Emits the event.</summary>
		/// <param name="args">The event arguments.</param>
		virtual void emit(const EventArgs& args = EventArgs())
		{
			assert(callbacks != NULL);

			for (auto it = callbacks->begin(); it != callbacks->end(); it++)
				if (*it != NULL)
					(*it)->run(args);
		}

		/// <summary>Emits the event.</summary>
		/// <param name="args">The event arguments.</param>
		virtual void operator() (const EventArgs& args = EventArgs())
		{
			this->emit(args);
		}
	};

}