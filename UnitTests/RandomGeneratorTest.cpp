#include "CppUnitTest.h"
#include "../MyLib/RandomGenerator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(RandomGeneratorTest)
	{
	public:

		TEST_METHOD(TestGenerate)
		{
			int min = 2;
			int max = 5;
			RandomGenerator generator(min, max);

			// '()' в конце инициализируют значения элементов массива
			// значением по умолчанию (false)
			bool* hasValue = new bool[max - min + 1]();

			int genCounts = 1000;
			for (int i = 0; i < genCounts; i++) {
				int val = generator.generate();
				Assert::IsTrue(val >= min && val <= max, L"Value should be in range [2; 5]");
				hasValue[val - min] = true;
			}

			for (int i = 0; i < max - min + 1; i++) {
				Assert::IsTrue(hasValue[i], L"One of values was not generated");
			}

			delete[] hasValue;
		}
	};
}
