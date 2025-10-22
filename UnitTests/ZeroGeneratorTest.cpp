#include "pch.h"
#include "CppUnitTest.h"
#include "../MyLib/ZeroGenerator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(ZeroGeneratorTest)
	{
	public:

		TEST_METHOD(TestGenerate)
		{
			ZeroGenerator generator;
			Assert::AreEqual(0, generator.generate());
			Assert::AreEqual(0, generator.generate());
			Assert::AreEqual(0, generator.generate());
		}
	};
}
