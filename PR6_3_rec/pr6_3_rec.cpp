// Лабораторна робота № 6.3, варіант 27
// Впорядкування елементів масиву за не зростанням (рекурсивний спосіб)
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <windows.h>
#include <cstdlib>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i);
void Print(int* a, const int size, int i);
int  IndexOfMax(int* a, const int size, int i, int imax);
void Sort(int* a, const int size, int i);

template <typename T>
void Print(T* a, const int size, int i);

template <typename T>
int IndexOfMax(T* a, const int size, int i, int imax);

template <typename T>
void Sort(T* a, const int size, int i);

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    srand((unsigned)time(NULL));

    const int n = 10;
    const int Low = -20;
    const int High = 50;

    // 1) звичайні функції
    int a[n];
    Create(a, n, Low, High, 0);
    cout << "Початковий масив:  ";
    Print(a, n, 0);
    cout << endl;
    Sort(a, n, 0);
    cout << "Впорядкований:     ";
    Print(a, n, 0);
    cout << endl << endl;

    // 2) шаблони функцій
    int b[n] = { 5, -3, 12, 0, 7, 7, -8, 20, 1, 4 };
    cout << "Print<int>, початковий:  ";
    Print<int>(b, n, 0);
    cout << endl;
    Sort<int>(b, n, 0);
    cout << "Sort<int>, впорядкований: ";
    Print<int>(b, n, 0);
    cout << endl << endl;

    double c[n] = { 1.1, 2.2, 3.3, 4.3, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
    cout << "Print<double>, початковий:  ";
    Print<double>(c, n, 0);
    cout << endl;
    Sort<double>(c, n, 0);
    cout << "Sort<double>, впорядкований: ";
    Print<double>(c, n, 0);
    cout << endl << endl;

    string d[n] = { "kiwi", "apple", "pear", "fig", "plum",
                    "lemon", "mango", "cherry", "grape", "banana" };
    cout << "Print<string>, початковий:  ";
    Print<string>(d, n, 0);
    cout << endl;
    Sort<string>(d, n, 0);
    cout << "Sort<string>, впорядкований: ";
    Print<string>(d, n, 0);
    cout << endl;

    return 0;
}

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
}

// індекс найбільшого елемента серед a[i..size-1]; imax – найкращий індекс на даний момент
int IndexOfMax(int* a, const int size, int i, int imax)
{
    if (i >= size)
        return imax;
    if (a[i] > a[imax])
        imax = i;
    return IndexOfMax(a, size, i + 1, imax);
}

void Sort(int* a, const int size, int i)
{
    if (i < size - 1)
    {
        int imax = IndexOfMax(a, size, i + 1, i);
        int tmp = a[i];
        a[i] = a[imax];
        a[imax] = tmp;
        Sort(a, size, i + 1);
    }
}

template <typename T>
void Print(T* a, const int size, int i)
{
    cout << setw(8) << a[i];
    if (i < size - 1)
        Print<T>(a, size, i + 1);
}

template <typename T>
int IndexOfMax(T* a, const int size, int i, int imax)
{
    if (i >= size)
        return imax;
    if (a[i] > a[imax])
        imax = i;
    return IndexOfMax<T>(a, size, i + 1, imax);
}

template <typename T>
void Sort(T* a, const int size, int i)
{
    if (i < size - 1)
    {
        int imax = IndexOfMax<T>(a, size, i + 1, i);
        T tmp = a[i];
        a[i] = a[imax];
        a[imax] = tmp;
        Sort<T>(a, size, i + 1);
    }
}