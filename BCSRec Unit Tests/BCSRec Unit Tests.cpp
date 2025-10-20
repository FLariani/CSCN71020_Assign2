#include "pch.h"
#include "CppUnitTest.h"
extern "C" int getPerimeter(int* length, int* width);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BCSRecUnitTests
{
	TEST_CLASS(BCSRecUnitTests)
	{
	public:

		TEST_METHOD(TestGetPerimeter)
		{
			int length = 5;  // Assign length 5
			int width = 2;   // Assign width 2

			int result = getPerimeter(&length, &width);  // Call the Function

			Assert::AreEqual(14, result); // Check if result is correct
		}

	};
}

