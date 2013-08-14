#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Core/ClassEventCallback.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(ClassEventCallbackTest)
	{
	private:

		class EventArgs {
		public:
			bool* result;
		};

		class TheClass {
		public:

			void callback_function (const EventArgs& args)
			{
				*args.result = true;
			}
		};

	public:
		
		TEST_METHOD(ClassEventCallback)
		{
			// Create callback
			TheClass object;
			Goblin::ClassEventCallback<TheClass, EventArgs> e(&object, &TheClass::callback_function);

			// Create event args
			EventArgs args;
			bool result;
			args.result = &result;

			// Test 1: run function
			result = false;
			e.run(args);
			Assert::IsTrue(result);

			// Test 2: functor
			result = false;
			e(args);
			Assert::IsTrue(result);
		}

	};
}