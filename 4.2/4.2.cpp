/*
Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). 
Упорядочить последовательность по неубыванию первой цифры числа, числа с одинаковыми 
первыми цифрами дополнительно упорядочить по неубыванию наименьшей цифры числа, числа 
с одинаковыми первыми цифрами и одинаковыми наименьшими цифрами дополнительно 
упорядочить по неубыванию самого числа.
*/

#include <iostream>

using namespace std;

int a[1000];
int n;
int b[10000];
int c[10000];
int q1[10000];
int q2[10000];

int main()
{
	

	cout << "kol-vo elementov: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "element " << i + 1 << ": ";
		cin >> a[i];

	}

	cout << "matrix: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";

	
	}
	cout << "" << endl;

	cout << "1 sort: ";
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				
				swap (a[i], a[j]);
			
			}
		
		}

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";


	}

	cout << " 2 sort: ";

	
	for (int i = 0; i < n; i++)
	{
		
		int y = a[i];
		int first;
		int sum = 0;

		while (y > 0)
		{
			
			first = y % 10;
			y = y / 10;
			c[i] = first;
			sum++;
			b[i] = sum;
			
			


		}
		
		
		

	}

	int min1 = 10000000000;
	int min2 = 10000000000;

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (c[i] > c[j])
			{
				swap (c[i], c[j]);
				swap (a[i], a[j]);
				swap (b[i], b[j]);
			}

			else if (c[i] == c[j])
			{
				int second1;
				int second2;
				int u = c[i];
				int o = c[j];
				
				for (int v = 0; v < b[i]; v++)
				{
					second1 = u % 10;
					u = u / 10;
					q1[v] = second1; 
				}

				for (int p = 0; p < b[j]; p++)
				{
					second2 = o % 10;
					o = o / 10;
					q2[p] = second2;
				}

				for (int x = 0; x < b[i]; x++)
				{
					
					if (q1[x] < min1)
						min1 = q1[x];


				}

				for (int y = 0; y < b[i]; y++)
				{
					
					if (q1[y] < min2)
						min2 = q1[y];


				}

				if (min1 > min2)
				{
					swap (c[i], c[j]);
					swap (a[i], a[j]);
					swap (b[i], b[j]);
				}
			
				
					
				
			}
			
		}

	for (int i = 0; i < n; i++)
	{

		cout << a[i] << " (" << c[i] << "; " << b[i]<< ") ";

	}
			



}

