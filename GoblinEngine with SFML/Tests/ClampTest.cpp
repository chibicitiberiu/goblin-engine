#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Core/Clamp.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(ClampTest)
	{
	public:
		
		TEST_METHOD(Clamp)
		{
			Assert::AreEqual((int)10, Goblin::clamp((int)10, (int)0, (int)100));
			Assert::AreEqual((int)0, Goblin::clamp((int)-10, (int)0, (int)100));
			Assert::AreEqual((int)100, Goblin::clamp((int)110, (int)0, (int)100));
			Assert::AreEqual('c', Goblin::clamp('a', 'c', 'z'));
			Assert::AreEqual('d', Goblin::clamp('z', 'a', 'd'));
			Assert::AreEqual((unsigned)5, Goblin::clamp((unsigned)-1, (unsigned)0, (unsigned)5));
		}

	};
}