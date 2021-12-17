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
   
   
    
    std::cout << "Stroki: ";
    std::cin >> n;
    std::cout << std::endl;
    std::cout << "Stolbi: ";
    std::cin >> m;
    std::cout << std::endl;

    hd::Input(n, m, mas);

    std::cout << "Matrix: " << std::endl;

    hd::Output(n, m, mas);


    
    if (hd::Min(mas, n, m) == true && hd::Max(mas, n, m) == true)
        hd::Proizved_Strok_i_Sort(sum, mas, n, m);

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

