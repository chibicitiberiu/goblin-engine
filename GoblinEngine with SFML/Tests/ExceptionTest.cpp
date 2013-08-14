#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Core/Exception.h"
#include "../Core/GoblinType.h"
#include "../Engine/Application.h"
#include "../Gui/ConsoleWindow.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(ExceptionTest)
	{
	public:
		
		TEST_METHOD(ExceptionMessageConstructor)
		{
			const std::string msg ("Hello world!");
			Goblin::Exception ex(msg);

			Assert::AreEqual(msg, ex.getMessage());
		}

		TEST_METHOD(ExceptionMessageFileConstructor)
		{
			const std::string msg ("Hello!");
			const std::string file (__FILE__);
			const unsigned int line = __LINE__ + 1;
			Goblin::Exception ex = EXCEPTION(Goblin::Exception, "Hello");

			Assert::AreEqual(msg, ex.getMessage());
			Assert::AreEqual(file, ex.getSourceFile());
			Assert::AreEqual(line, ex.getLine());
		}

		TEST_METHOD(ExceptionCopyConstructor)
		{
			const std::string msg ("Hello world!");
			Goblin::Exception ex1(msg);
			Goblin::Exception ex(ex1);
			
			Assert::AreEqual(msg, ex.getMessage());
		}

	};
}