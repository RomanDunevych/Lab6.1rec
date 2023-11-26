#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.1rec/Lab6.1rec.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCountAndSumRecursive)
        {
            const int SIZE = 25;
            int t[SIZE] = { 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16, 17, -18, 19, -20, 21, -22, 23, -24, 25 };
            int count = 0, sum = 0;

            countAndSumRecursive(t, SIZE, count, sum, 0);

            Assert::AreEqual(8, count);
            Assert::AreEqual(-104, sum);

            for (int i = 0; i < SIZE; i++) {
                if (t[i] < 0 && i % 3 != 0) {
                    Assert::AreEqual(0, t[i]);
                }
            }
        }
    };
}
