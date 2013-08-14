#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Core/BasicEventCallback.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	class BasicEventCallbackTest_EventArgs
	{
	public:
		bool* result;
	};

	void BasicEventCallbackTest_callback_function(const BasicEventCallbackTest_EventArgs& args)
	{
		*args.result = true;
	}

	TEST_CLASS(BasicEventCallbackTest)
	{
	public:
		
		TEST_METHOD(BasicEventCallback)
		{
			// Set up callback
			Goblin::BasicEventCallback<BasicEventCallbackTest_EventArgs> e(BasicEventCallbackTest_callback_function);
			
			// Set up event args
			BasicEventCallbackTest_EventArgs args;
			bool data;
			args.result = &data;

			// Test 1: run function
			data = false;
			e.run(args);
			Assert::IsTrue(data);

			// Test 2: functor
			data = false;
			e(args);
			Assert::IsTrue(data);
		}

	};
}