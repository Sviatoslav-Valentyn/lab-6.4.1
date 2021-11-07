// Варіант 6(Ітераційний спосіб)
#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

void Init(int* b, const int n)
{
    for (size_t i = 0; i < n; i++)
        b[i] = -2 + rand() % 5;  // (-2, 2)
}

void Print(const int* const b, const int n)
{
    cout << "{ ";
    for (size_t i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << "}" << endl;
}

int Min(const int* const b, const int n)
{
    int min = b[0];
    for (int i = 0; i < n; i++)
    {
        if (b[i] < min)
        {
            min = b[i];
        }
    }
    return min;
}

int FirstElement(int* b, const int n)
{
    for (int i = 0; i < n; i++)
    {
        if (b[i] > 0)
            return i;
    }
    return -1;

}

int LastElement(int* b, const int n)
{
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (b[i] > 0)
        {
            index = i;

        }
    }
    return index;
}

int Sum(int b[], const int n)
{
    int s = 0;
    for (int i = 1 + FirstElement(b, n); i < LastElement(b, n); i++)
        s += b[i];
    return s;
}

int Nadx0(int* b, const int n, int start)
{
    for (int i = start; i < n; i++)
    {
        if (b[i] == 0)
            return i;
    }
    return -1;
}

void Sort(int* b, const int n)
{
    for (int i = 0; i < n; i++)
    {
        int index = Nadx0(b, n, i);
        if (index == -1)
            index = i;

        int tmp = b[i];
        b[i] = b[index];
        b[index] = tmp;
    }
}

int main()
{
    SetConsoleOutputCP(1251);

    srand(time(0));
    int n;
    cout << "n = "; cin >> n;

    int* b = new int[n];

    Init(b, n);
    Print(b, n);
    cout << "Мінімальний елемент = " << Min(b, n) << endl;
    cout << "Суму елементів масиву = " << Sum(b, n) << endl;
    Sort(b, n);
    Print(b, n);


    delete[] b;
    b = nullptr;

    return 0;
}