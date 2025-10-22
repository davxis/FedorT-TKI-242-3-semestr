#include "pch.h"
#include "CppUnitTest.h"
#include "../MyLib/Matrix.h"
#include <string>
#include "../MyLib/IStreamGenerator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(MatrixTest)
	{
	public:

		TEST_METHOD(TestConstructors)
		{
			// “естируем конструктор принимающий int
			// и метод getCount()
			Matrix<std::string> matr(3);
			matr[0] = "apple";
			matr[1] = "juice";
			matr[2] = "potato";
			Assert::AreEqual(3, (int)matr.getCount());

			// “естируем конструктор копировани€
			Matrix<std::string> matrCpy(matr);
			matrCpy[1] = "other";
			Assert::IsTrue(matr[0] == "apple");
			Assert::IsTrue(matrCpy[0] == "apple");
			Assert::IsTrue(matr[1] == "juice");
			Assert::IsTrue(matrCpy[1] == "other");
			Assert::IsTrue(matr[2] == "potato");
			Assert::IsTrue(matrCpy[2] == "potato");
			Assert::AreEqual(3, (int)matrCpy.getCount());
		}

		TEST_METHOD(TestToString)
		{
			Matrix<int> matr(3);
			matr[0] = -12;
			matr[1] = 100;
			matr[2] = 315;
			std::string s = matr.toString();
			Assert::IsTrue(s == "[-12 100 315]");
		}

		TEST_METHOD(TestAssignment)
		{
			// “естируем конструктор принимающий int
			// и метод getCount()
			Matrix<std::string> matr(3);
			matr[0] = "apple";
			matr[1] = "juice";
			matr[2] = "potato";

			// “естируем конструктор копировани€
			Matrix<std::string> matrCpy;
			matrCpy = matr;
			matrCpy[1] = "other";
			Assert::IsTrue(matr[0] == "apple");
			Assert::IsTrue(matrCpy[0] == "apple");
			Assert::IsTrue(matr[1] == "juice");
			Assert::IsTrue(matrCpy[1] == "other");
			Assert::IsTrue(matr[2] == "potato");
			Assert::IsTrue(matrCpy[2] == "potato");
			Assert::AreEqual(3, (int)matrCpy.getCount());
		}

		TEST_METHOD(TestStreamInputOutput)
		{
			Matrix<int> matr(3);
			std::stringstream ss("324 -15 6");
			ss >> matr;
			Assert::AreEqual(3, (int)matr.getCount());
			Assert::AreEqual(324, matr[0]);
			Assert::AreEqual(-15, matr[1]);
			Assert::AreEqual(6, matr[2]);

			std::stringstream ssOut;
			ssOut << matr;
			std::string strOut = ssOut.str();
			Assert::IsTrue(strOut == "[324 -15 6]");
		}

		TEST_METHOD(TestGenerateValues)
		{
			Matrix<int> matr(3);
			std::stringstream ss("-15 7 28");
			Generator<int>* generator = new IStreamGenerator(ss);

			matr.generateValues(*generator);

			Assert::AreEqual(3, (int)matr.getCount());
			Assert::AreEqual(-15, matr[0]);
			Assert::AreEqual(7, matr[1]);
			Assert::AreEqual(28, matr[2]);

			delete generator;
		}
	};
}
