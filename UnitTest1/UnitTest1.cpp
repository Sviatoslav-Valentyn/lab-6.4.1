#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 6.4.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double A[] = { 0, 0, - 2, - 2, 0 };
			int t = Sum(A, 5);
			Assert::AreEqual(0, t);
		}
	};
}
