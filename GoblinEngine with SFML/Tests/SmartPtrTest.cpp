#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Core/SmartPtr.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(SmartPtrTest)
	{
	public:
		
		TEST_METHOD(SmartPtr)
		{
			int* num = new int(10);
			Goblin::SmartPtr<int> ptr(num);

			Assert::AreEqual(num, ptr.ptr());
			Assert::AreEqual(num, ptr());
			Assert::AreEqual(*num, *ptr);
			Assert::AreEqual((unsigned)1, ptr.refs());

			{
				Goblin::SmartPtr<int> ptr2(ptr);
				Assert::AreEqual(num, ptr2.ptr());
				Assert::AreEqual(num, ptr2());
				Assert::AreEqual(*num, *ptr2);
				Assert::AreEqual((unsigned)2, ptr.refs());
				Assert::AreEqual((unsigned)2, ptr2.refs());

				Assert::IsTrue(ptr == ptr2);
				Assert::IsFalse(ptr != ptr2);
			}

			Assert::AreEqual((unsigned)1, ptr.refs());
		}

		TEST_METHOD(SmartPtrArray)
		{
			int* num = new int[5];
			num[0] = -1;

			Goblin::SmartPtr<int[]> ptr(num, 5);

			Assert::AreEqual(num, ptr.ptr());
			Assert::AreEqual(num, ptr());
			Assert::AreEqual(-1, ptr[0]);
			Assert::AreEqual((unsigned)1, ptr.refs());
			Assert::AreEqual((unsigned)5, ptr.size());

			{
				Goblin::SmartPtr<int[]> ptr2(ptr);
				Assert::AreEqual(num, ptr2.ptr());
				Assert::AreEqual(num, ptr2());
				Assert::AreEqual(-1, ptr2[0]);
				Assert::AreEqual((unsigned)5, ptr2.size());
				Assert::AreEqual((unsigned)2, ptr.refs());
				Assert::AreEqual((unsigned)2, ptr2.refs());

				Assert::IsTrue(ptr == ptr2);
				Assert::IsFalse(ptr != ptr2);

				ptr[1] = 16;
				Assert::AreEqual(16, ptr2[1]);
			}

			Assert::AreEqual((unsigned)1, ptr.refs());
		}

	};
}