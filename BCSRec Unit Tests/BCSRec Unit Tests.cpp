#include "pch.h"
#include "CppUnitTest.h"
extern "C" int getPerimeter(int* length, int* width);
extern "C" int getArea(int* length, int* width);
extern "C" void setLength(int input, int* length);
extern "C" void setWidth(int input, int* width);

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
		// Test Area Formula Calculation
		TEST_METHOD(TestGetArea)
		{
			int length = 5;  // Assign length 5
			int width = 2;   // Assign width 2

			int result = getArea(&length, &width); // Call the Function

			Assert::AreEqual(10, result); // Check if result is correct
		}
		// Test 1 for setLength: Normal input
		TEST_METHOD(SetLength_NormalValue)
		{
			int length = 0;
			setLength(50, &length);   // Call the function with 50
			Assert::AreEqual(50, length);  // Check if it was stored correctly
		}
		// Test 2: Edge case (lowest possible valid value)
		TEST_METHOD(SetLength_LowerBound1)
		{
			int length = 0;
			setLength(1, &length);   // 1 is allowed
			Assert::AreEqual(1, length); // Check that it passed 
		}
		// Test 3: Invalid input (too high should keep original value)
		TEST_METHOD(SetLength_TooHigh)
		{
			int length = 99;          // Start with 99
			setLength(150, &length);  // 150 is invalid, should not update
			Assert::AreEqual(99, length);  // Check that it didn’t change
		}
		// Test 1 for setWidth: Normal input 
		TEST_METHOD(SetWidth_NormalValue)
		{
			int width = 0;
			setWidth(75, &width);
			Assert::AreEqual(75, width);
		}
		// Test 2: Edge case (highest possible valid value)
		TEST_METHOD(SetWidth_UpperBound99)
		{
			int width = 0;			// start with 0
			setWidth(99, &width);   // 99 is allowed
			Assert::AreEqual(99, width); // Check that it passed
		}
		// Test 3: Invalid input (too low should keep original value)
		TEST_METHOD(SetWidth_TooLow)
		{
			int width = 55;          // Start with 55
			setWidth(0, &width);     // 0 is invalid
			Assert::AreEqual(55, width);  // Check that it didn’t change
		}








	};
}

