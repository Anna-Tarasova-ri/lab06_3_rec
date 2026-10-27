// Unit-тест до лабораторної роботи № 6.3, варіант 27 (рекурсивний спосіб)
// Тестуються функції Sort та IndexOfMax.
// Тип проєкту: "Native Unit Test Project" (Visual Studio).
// Шлях у #include змініть відповідно до назви вашого проєкту.
#include"pch.h"

#include "CppUnitTest.h"
#include "../PR6_3_rec/pr6_3_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_6_3_recursive
{
    TEST_CLASS(UnitTest_6_3_recursive)
    {
    public:

        // ---- IndexOfMax ----

        TEST_METHOD(IndexOfMax_Int_Middle)
        {
            int a[5] = { 1, 7, 3, 9, 2 };
            Assert::AreEqual(3, IndexOfMax(a, 5, 0, 0));
        }

        TEST_METHOD(IndexOfMax_Int_FromPosition)
        {
            int a[5] = { 100, 7, 3, 9, 2 };      // максимум a[0] не враховується, пошук з i = 1
            Assert::AreEqual(3, IndexOfMax(a, 5, 2, 1));
        }

        // ---- звичайна функція Sort(int*, int, int) ----

        TEST_METHOD(Sort_Int_Unsorted)
        {
            int a[6] = { 3, 9, -2, 7, 0, 5 };
            int expected[6] = { 9, 7, 5, 3, 0, -2 };
            Sort(a, 6, 0);
            for (int i = 0; i < 6; i++)
                Assert::AreEqual(expected[i], a[i]);
        }

        TEST_METHOD(Sort_Int_AlreadyNonIncreasing)
        {
            int a[5] = { 10, 8, 8, 3, -1 };
            int expected[5] = { 10, 8, 8, 3, -1 };
            Sort(a, 5, 0);
            for (int i = 0; i < 5; i++)
                Assert::AreEqual(expected[i], a[i]);
        }

        TEST_METHOD(Sort_Int_Ascending)
        {
            int a[5] = { 1, 2, 3, 4, 5 };
            int expected[5] = { 5, 4, 3, 2, 1 };
            Sort(a, 5, 0);
            for (int i = 0; i < 5; i++)
                Assert::AreEqual(expected[i], a[i]);
        }

        TEST_METHOD(Sort_Int_Duplicates)
        {
            int a[7] = { 4, 1, 4, 2, 1, 4, 2 };
            int expected[7] = { 4, 4, 4, 2, 2, 1, 1 };
            Sort(a, 7, 0);
            for (int i = 0; i < 7; i++)
                Assert::AreEqual(expected[i], a[i]);
        }

        TEST_METHOD(Sort_Int_OneElement)
        {
            int a[1] = { 42 };
            Sort(a, 1, 0);
            Assert::AreEqual(42, a[0]);
        }

        // ---- шаблон Sort<T> ----

        TEST_METHOD(Sort_Template_Int)
        {
            int a[5] = { 2, 8, -5, 8, 1 };
            int expected[5] = { 8, 8, 2, 1, -5 };
            Sort<int>(a, 5, 0);
            for (int i = 0; i < 5; i++)
                Assert::AreEqual(expected[i], a[i]);
        }

        TEST_METHOD(Sort_Template_Double)
        {
            double a[5] = { 1.5, 9.25, -3.0, 4.75, 0.0 };
            double expected[5] = { 9.25, 4.75, 1.5, 0.0, -3.0 };
            Sort<double>(a, 5, 0);
            for (int i = 0; i < 5; i++)
                Assert::AreEqual(expected[i], a[i]);
        }

        TEST_METHOD(Sort_Template_String)
        {
            string a[4] = { "kiwi", "apple", "pear", "fig" };
            string expected[4] = { "pear", "kiwi", "fig", "apple" };
            Sort<string>(a, 4, 0);
            for (int i = 0; i < 4; i++)
                Assert::AreEqual(expected[i], a[i]);
        }
    };
}