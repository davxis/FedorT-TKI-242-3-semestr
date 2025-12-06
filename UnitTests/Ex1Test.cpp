#include "CppUnitTest.h"
#include "../MyLib/Matrix.h"
#include <string>
#include "../MyLib/IStreamGenerator.h"
#include <sstream>
#include <memory>
#include "../Lab4_2/Ex1.h"
#include "../MyLib/Generator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(Ex1Test)
	{
	public:

		TEST_METHOD(TestPositiveUniqueMax)
		{
			std::stringstream input("1 2 3");
			auto matr = std::make_unique<Matrix<int>>(3);
			Matrix<int>* matr_ptr = matr.get();
			auto gen = std::make_unique<IStreamGenerator>(input);
			Generator<int>* gen_ptr = gen.get();
			auto ex = std::make_unique<Ex1>(std::move(matr), std::move(gen));

			matr_ptr->generateValues(*gen_ptr);
			ex->Task();

			Assert::AreEqual(1, (*matr_ptr)[0]);
			Assert::AreEqual(2, (*matr_ptr)[1]);
			Assert::AreEqual(-3, (*matr_ptr)[2]);
		}

		TEST_METHOD(TestNegativeUniqueMax)
		{
			std::stringstream input("-3 -2 -1");
			auto matr = std::make_unique<Matrix<int>>(3);
			Matrix<int>* matr_ptr = matr.get();
			auto gen = std::make_unique<IStreamGenerator>(input);
			Generator<int>* gen_ptr = gen.get();
			auto ex = std::make_unique<Ex1>(std::move(matr), std::move(gen));

			matr_ptr->generateValues(*gen_ptr);
			ex->Task();

			Assert::AreEqual(-3, (*matr_ptr)[0]);
			Assert::AreEqual(-2, (*matr_ptr)[1]);
			Assert::AreEqual(1, (*matr_ptr)[2]);
		}

		TEST_METHOD(TestMultipleMax)
		{
			std::stringstream input("5 4 5 3");
			auto matr = std::make_unique<Matrix<int>>(4);
			Matrix<int>* matr_ptr = matr.get();
			auto gen = std::make_unique<IStreamGenerator>(input);
			Generator<int>* gen_ptr = gen.get();
			auto ex = std::make_unique<Ex1>(std::move(matr), std::move(gen));

			matr_ptr->generateValues(*gen_ptr);
			ex->Task();

			Assert::AreEqual(-5, (*matr_ptr)[0]);
			Assert::AreEqual(4, (*matr_ptr)[1]);
			Assert::AreEqual(-5, (*matr_ptr)[2]);
			Assert::AreEqual(3, (*matr_ptr)[3]);
		}
	};
}