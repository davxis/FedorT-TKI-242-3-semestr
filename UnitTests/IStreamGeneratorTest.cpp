#include "pch.h"
#include "CppUnitTest.h"
#include "../MyLib/IStreamGenerator.h"
#include <sstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(IStreamGeneratorTest)
	{
	public:

		TEST_METHOD(TestGenerate)
		{
			std::string input{"12 -5 100 4"};
			std::stringstream ss(input);

			IStreamGenerator generator(ss);
			Assert::AreEqual(12, generator.generate());
			Assert::AreEqual(-5, generator.generate());
			Assert::AreEqual(100, generator.generate());
			Assert::AreEqual(4, generator.generate());

			Assert::AreEqual(0, generator.generate());
			Assert::AreEqual(0, generator.generate());
		}
	};
}
