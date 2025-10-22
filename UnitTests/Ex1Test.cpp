#include "pch.h"
#include "CppUnitTest.h"
#include "../MyLib/Matrix.h"
#include <string>
#include "../MyLib/IStreamGenerator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(Ex1Test)
	{
	public:

		TEST_METHOD(TestEx1)
		{
			Matrix<int> matr(3);
		}
	};
}
