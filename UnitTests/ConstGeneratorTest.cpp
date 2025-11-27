#include "CppUnitTest.h"
#include "../MyLib/ConstGenerator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(ConstGeneratorTest)
	{
	public:
		
		TEST_METHOD(TestGenerate)
		{
			ConstGenerator generator(-30);
			Assert::AreEqual(-30, generator.generate());
		}
	};
}
