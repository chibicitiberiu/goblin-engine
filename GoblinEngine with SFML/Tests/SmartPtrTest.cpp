#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Core/SmartPtr.h"
#include "../Core/Exception.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(SmartPtrTest)
	{
	public:
		
		TEST_METHOD(SmartPtr)
		{
			// Create a pointer
			int* num = new int(10);
			Goblin::SmartPtr<int> ptr(num);

			// Check getters
			Assert::AreEqual(num, ptr.ptr(), L"Same pointer address");
			Assert::AreEqual(num, ptr(), L"Same pointer address");
			Assert::AreEqual(*num, *ptr, L"Dereference pointer");
			Assert::AreEqual((unsigned)1, ptr.refs(), L"Reference count");

			// Create another pointer
			{
				Goblin::SmartPtr<int> ptr2(ptr);
				Goblin::SmartPtr<int> ptr3(new int(10));				

				// Check getters
				Assert::AreEqual(num, ptr2.ptr(), L"Same pointer address");
				Assert::AreEqual(num, ptr2(), L"Same pointer address");
				Assert::AreEqual(*num, *ptr2, L"Dereference pointer");
				
				// Check reference count
				Assert::AreEqual((unsigned)2, ptr.refs(), L"Reference count");
				Assert::AreEqual((unsigned)2, ptr2.refs(), L"Reference count");

				// Check comparison operators (they compare ADDRESSES, not content)
				Assert::IsTrue(ptr == ptr2, L"Equality comparison");
				Assert::IsFalse(ptr == ptr3, L"Equality comparison. Compare by ADDRESS not VALUE");
				Assert::IsFalse(ptr != ptr2, L"Inequality comparison");
				Assert::IsTrue(ptr != ptr3, L"Inequality comparison. Compare by ADDRESS not VALUE");
			}

			// Check reference count
			Assert::AreEqual((unsigned)1, ptr.refs(), L"Reference count");
		}

		TEST_METHOD(SmartPtrNull)
		{
			// Default constructors must set the address to NULL.
			Goblin::SmartPtr<int> p;
			Goblin::SmartPtr<int[]> p2;

			// Check address
			Assert::AreEqual((int*)NULL, p.ptr(), L"Expected address must be NULL");
			Assert::AreEqual((int*)NULL, p(), L"Expected address must be NULL");
			Assert::AreEqual((int*)NULL, p2.ptr(), L"Expected address must be NULL");
			Assert::AreEqual((int*)NULL, p2(), L"Expected address must be NULL");

			// We shouldn't be able to dereference NULL
			try {
				*p;
				Assert::Fail(L"Dereference null pointer");
			}

			catch (Goblin::NullReferenceException&) {
			}

			// We shouldn't be able to index NULL
			try {
				p2[0];
				Assert::Fail(L"Index null pointer");
			}
			catch (Goblin::NullReferenceException&) {
			}
		}

		TEST_METHOD(SmartPtrArray)
		{
			// Create an array
			int* num = new int[5];
			num[0] = -1;

			// Create array pointer
			Goblin::SmartPtr<int[]> ptr(num, 5);

			// Check getters
			Assert::AreEqual(num, ptr.ptr(), L"Same pointer address");
			Assert::AreEqual(num, ptr(), L"Same pointer address");
			Assert::AreEqual(-1, ptr[0], L"Indexing");
			Assert::AreEqual((unsigned)1, ptr.refs(), L"Reference count");
			Assert::AreEqual((unsigned)5, ptr.size(), L"Array size");

			// Create second array pointer
			{
				Goblin::SmartPtr<int[]> ptr2(ptr);
				
				// Check getters
				Assert::AreEqual(num, ptr2.ptr(), L"Same pointer address");
				Assert::AreEqual(num, ptr2(), L"Same pointer address");
				Assert::AreEqual(-1, ptr2[0], L"Indexing");
				
				// Check reference count
				Assert::AreEqual((unsigned)5, ptr2.size(), L"Array size");
				Assert::AreEqual((unsigned)2, ptr.refs(), L"Reference count");
				Assert::AreEqual((unsigned)2, ptr2.refs(), L"Reference count");

				// Check comparison operators (they compare ADDRESSES, not content)
				Assert::IsTrue(ptr == ptr2, L"Equality comparison");
				Assert::IsFalse(ptr != ptr2, L"Inequality comparison");

				// Check indexing operator
				ptr[1] = 16;
				Assert::AreEqual(16, ptr2[1], L"Indexing");
			}

			// Check reference count
			Assert::AreEqual((unsigned)1, ptr.refs(), L"Reference count");

			// Make sure bounds are checked.
			try {
				ptr[100];
				Assert::Fail(L"Index outside bounds.");
			}

			catch (Goblin::ArgumentOutOfRangeException&)
			{
			}
		}

	};
}