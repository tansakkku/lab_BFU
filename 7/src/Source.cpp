#include "Header.hpp"
#include <iostream>




namespace hd 
{
    bool Min(int mas[v][v], int n, int m)
    {
        int minimum = 100000;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {

                if (mas[i][j] < minimum)
                {
                    minimum = mas[i][j];
                }
            }
        int ssum = 0;
        for (int x = 0; x < n; x++)
            for (int y = 0; y < m; y++)
                if (minimum == mas[x][y])
                {
                    ssum = ssum + 1;
                }

        if (ssum > 1)
            return true;

        return false;
    }


    bool Max(int mas[v][v], int n, int m)
    {
        int maximum = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (mas[i][j] > maximum)
                {
                    maximum = mas[i][j];
                }
            }






        if (maximum < 2)
            return false;

        for (int d = 2; d <= sqrt(maximum); d++)
            if (maximum % d == 0)
                return false;


        return true;

    }



    void Sum_Strok_i_Sort(int sum[w], int mas[v][v], int n, int m)
    {

        for (int i = 0; i < n; i++)
        {
            int summ = 0;
            for (int j = 0; j < m; j++)
            {
                summ = summ + mas[i][j];
                sum[i] = summ;

            }
        }

        for (int x = 0; x < n; x++)
            for (int y = x + 1; y < n; y++)
            {
                if (sum[x] < sum[y])
                {
                    for (int q = 0; q < m; q++)
                        std::swap(mas[x][q], mas[y][q]);
                    std::swap(sum[x], sum[y]);


                }

            }
        for (int i = 0; i < n; i++)
        {


            for (int j = 0; j < m; j++)
            {
                std::cout << mas[i][j] << " ";
            }

            std::cout << std::endl;
        }
    }

}