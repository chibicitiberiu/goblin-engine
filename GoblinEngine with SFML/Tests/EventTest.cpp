#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Core/Event.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	class EventTest_EventArgs
	{
	public:
		bool* res[4];
	};

	class EventTest_CustomCallback : public Goblin::IEventCallback<EventTest_EventArgs>
	{
	public:
		virtual void run(const EventTest_EventArgs& args)
		{
			*args.res[0] = true;
		}
	};

	class EventTest_Class
	{
	public:
		void callback_function(const EventTest_EventArgs& args)
		{
			*args.res[1] = true;
		}
	};

	void EventTest_Callback1(const EventTest_EventArgs& args)
	{
		*args.res[2] = true;
	}

	void EventTest_Callback2(const EventTest_EventArgs& args)
	{
		*args.res[3] = true;
	}

	TEST_CLASS(EventTest)
	{
	public:
		
		TEST_METHOD(Event)
		{
			// Create object
			EventTest_Class obj;

			// Create event
			Goblin::Event<EventTest_EventArgs> e;
			e.addHandler(new EventTest_CustomCallback());
			e.addHandler(&obj, &EventTest_Class::callback_function);
			e.addHandler(EventTest_Callback1);
			e += new Goblin::BasicEventCallback<EventTest_EventArgs>(EventTest_Callback2);

			// Create event args
			bool res1[4] = {false, false, false, false};
			bool res2[4] = {false, false, false, false};
			EventTest_EventArgs args1, args2;

			for (int i = 0; i < 4; i++)
			{
				args1.res[i] = &res1[i];
				args2.res[i] = &res2[i];
			}

			// Run tests
			e.emit(args1);
			e(args2);

			// Check results
			for (int i = 0; i < 4; i++)
			{
				Assert::IsTrue(res1[i]);
				Assert::IsTrue(res2[i]);
			}
		}

	};
}