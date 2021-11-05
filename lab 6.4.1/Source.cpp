// Варіант 6(Ітераційний спосіб)
#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

void Init(double* b, const int size)
{
    for (size_t i = 0; i < size; i++)
        b[i] = -2 + rand() % 5;  // (-2, 2)
}

void Print(const double* const b, const int size)
{
    cout << "{ ";
    for (size_t i = 0; i < size; i++)
    {
        cout << b[i] << " ";
    }
    cout << "}" << endl;
}

double Min(const double* const b, const int n)
{
    double min = b[0];
    for (int i = 0; i < n; i++)
    {
        if (b[i] < min)
        {
            min = b[i];
        }
    }
    return min;
}

int FirstElement(double* b, const int size)
{
    for (int i = 0; i < size; i++)
    {
        if (b[i] > 0)
            return i;
    }
    return -1;

}

int LastElement(double* b, const int size)
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (b[i] > 0)
        {
            index = i;

        }
    }
    return index;
}

double Sum(double b[], const int n)
{
    double s = 0;
    for (int i = 1 + FirstElement(b, n); i < LastElement(b, n); i++)
        s += b[i];
    return s;
}

int Nadx0(double* b, const int size, int start)
{
    for (int i = start; i < size; i++)
    {
        if (b[i] == 0)
            return i;
    }
    return -1;
}

void Sort(double* b, const int n)
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

    double* b = new double[n];

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