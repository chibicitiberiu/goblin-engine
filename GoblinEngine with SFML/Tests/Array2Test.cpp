#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Core/Array2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{		
	TEST_CLASS(Array2Test)
	{
	public:
		
		TEST_METHOD(Array2WidthHeightConstructor)
		{
			Goblin::Array2<int> arr(3, 5);
			Assert::AreEqual((size_t)3, arr.getWidth());
			Assert::AreEqual((size_t)5, arr.getHeight());
		}

		TEST_METHOD(Array2WidthHeightValsConstructor)
		{
			// Constants
			const short vals[] = {-1, 2, 3, 1, 
								   4,-2, 1, 4, 
								   2, 1, 9, 1};

			// Test
			Goblin::Array2<short> arr(4, 3, vals);
			Assert::AreEqual((size_t)4, arr.getWidth());
			Assert::AreEqual((size_t)3, arr.getHeight());
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 4; j++)
					Assert::AreEqual(vals[i * 4 + j], arr.get(j, i));
		}

		TEST_METHOD(Array2CopyConstructor)
		{
			Goblin::Array2<int> arr1(3, 5);
			Goblin::Array2<int> arr(arr1);
			Assert::AreEqual((size_t)3, arr.getWidth());
			Assert::AreEqual((size_t)5, arr.getHeight());

			// arr1 and arr3 should not point to the same location
			arr1.set(0, 0, -9999);
			arr.set(0, 0, 9999);
			Assert::AreEqual((int)-9999, arr1.get(0, 0));
			Assert::AreEqual((int)9999, arr.get(0, 0));
		}

		TEST_METHOD(Array2Setter)
		{
			// Test 1
			Goblin::Array2<char> arr1(1, 1);

			arr1.set(0, 0, 'a');
			Assert::AreEqual('a', arr1.get(0, 0));

			arr1.set(0, 0, 'z');
			Assert::AreEqual('z', arr1.get(0, 0));

			// Test 2
			Goblin::Array2<int> arr2(1, 1);
			
			arr2.set(0, 0, -1);
			Assert::AreEqual((int)-1, arr2.get(0, 0));

			arr2.set(0, 0, 100);
			Assert::AreEqual((int)100, arr2.get(0, 0));

			// Bounds check - getter
			try {
				arr1.get(100, 100);
				Assert::Fail(L"Out of bounds");
			}
			catch (Goblin::ArgumentOutOfRangeException&)
			{
			}

			// Bounds check - setter
			try {
				arr2.set(100, 100, -1);
				Assert::Fail(L"Out of bounds");
			}
			catch (Goblin::ArgumentOutOfRangeException&)
			{
			}


		}

	};
}