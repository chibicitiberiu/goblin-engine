#pragma once
#include "IEventCallback.h"

namespace Goblin
{
	template <class AnyClass, class EventArgs>
	class ClassEventCallback : public IEventCallback<EventArgs>
	{
	public:
		typedef void (*AnyClass::Function) (const EventArgs& args);

	private:

		AnyClass* obj;
		Function func;

	public:

		ClassEventCallback(AnyClass* object, Function f)
			: obj(object), func(f)
		{
		}

		virtual ~ClassEventCallback(void)
		{
		}

		virtual void run(const EventArgs& args)
		{
			(*obj.*func) (args);
		}
	};

}