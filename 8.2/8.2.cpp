#include <iostream>
#include <climits>
/*
#define I 100
#define J 100
*/

using namespace std;

int main()
{
    
    int stroki, stolbi;

    //Ввод элементов матрицы

    cout << "Введите кол-во строк: ";
    cin >> stroki;

    cout << "Введите кол-во столбцов: ";
    cin >> stolbi;

    int** a = new int* [stroki];
    for (int i = 0; i < stroki; i++)
        a[i] = new int[stolbi];

    for (int i = 0; i < stroki; i++)
        for (int j = 0; j < stolbi; j++)
        {
            cout << "i(" << i + 1 << ") j(" << j + 1 << ") : ";
            cin >> a[i][j];


        }
    cout << "Матрица: " << endl;

    for (int i = 0; i < stroki; i++)
    {
        for (int j = 0; j < stolbi; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    // находим сумму строк
    //int b[100];

    int* b = new int[stroki];

    for (int i = 0; i < stroki; i++)
    {
        int sum = 0;
        for (int j = 0; j < stolbi; j++)
        {
            sum = sum + a[i][j];
        }
        b[i] = sum;
    }


    int min = INT_MAX;
    int num = -1;
    for (int i = 0; i < stroki; i++)
    {
        if (b[i] < b[i + 1])
        {
            if (b[i] < min)
            {
                min = b[i];
                num = i;
            }
        }

    }


    cout << num << " " << b[0] << endl;

    for (int i = 0; i < stroki; i++)
    {
        cout << b[i] << " " << endl;
    }


    for (int j = 0; j < stolbi; j++)
    {
        a[num][j] = b[0];
    }

    cout << "Новая матрица: " << endl;

    for (int i = 0; i < stroki; i++)
    {
        for (int j = 0; j < stolbi; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    delete[] a;
    delete[] b;

}