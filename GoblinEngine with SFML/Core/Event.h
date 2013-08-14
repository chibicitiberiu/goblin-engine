#pragma once
#include "IEventCallback.h"
#include "BasicEventCallback.h"
#include "ClassEventCallback.h"
#include <cassert>
#include <vector>

namespace Goblin
{
	template <class EventArgs>
	class Event
	{
	private:
		std::vector< IEventCallback<EventArgs>* >* callbacks;

	public:

		Event(void)
			: callbacks(new std::vector< IEventCallback<EventArgs>* >())
		{
		}

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

		virtual void addHandler(IEventCallback<EventArgs>* h)
		{
			callbacks->push_back(h);
		}
		
		virtual void addHandler(BasicEventCallback<EventArgs>::Function f)
		{
			callbacks->push_back(new BasicEventCallback<EventArgs>(f));
		}
		
		template <class AnyClass>
		virtual void addHandler(AnyClass* object, ClassEventCallback<AnyClass, EventArgs>::Function f)
		{
			callbacks->push_back(new ClassEventCallback<AnyClass, EventArgs>(object, f));
		}

		virtual Event& operator+= (IEventCallback<EventArgs>* h)
		{
			this->addHandler(h);
			return *this;
		}

		virtual void run()
		{
			assert(callbacks != NULL);

			for (auto it = callbacks->begin(); it != callbacks->end(); it++)
				if (*it != NULL)
					delete *it;
		}
	};

}