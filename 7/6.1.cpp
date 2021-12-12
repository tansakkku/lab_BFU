/*
Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. 
Если в матрице есть еще один элемент, равный ее минимальному элементу, 
и не менее 2-х элементов, абсолютные величины которых - простые числа, упорядочить 
строки матрицы по невозрастанию произведений элементов.

*/

#include <iostream>
#include <fstream>
#include "Header.hpp"

int sum[w];
int mas[v][v];




int main()
{
   
    int n, m;
    std::ifstream in("input.txt");
    in >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            in >> mas[i][j];

    
    if (hd::Min(mas, n, m) == true && hd::Max(mas, n, m) == true)
        hd::Sum_Strok_i_Sort(sum, mas, n, m);

    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cout << mas[i][j] << " ";
            }
            std::cout << std::endl;
                
            

        }

    }

    return 0;
}

