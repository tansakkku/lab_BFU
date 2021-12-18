#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);

	ifstream in("input.txt");
	ofstream out("output.txt");
	
	int size = 0;
	char a[100];
	int num;

	in >> num;
	in >> a;

	string b[5000];
	string s;
	

	while (in >> s) 
	{

		s.erase(remove_if(s.begin(), s.end(), ispunct), s.end());

		for (int i = 0; i < s.length(); i++)
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] += 32;
		

		bool proverka = false;
		for (int i = 0; i < s.length(); i++)
			for(int j = 0; j < s.length(); j++)
				if (s[i] == a[j])
				{
					proverka = true;
					break;
				}

		if (not proverka)
		{
			bool sl = false;
			for (int i = 0; i < size; i++)
				if (s == b[i])
				{
					sl = true;
					break;
				}

			if (not sl)
			{
				b[size] = s;
				size++;
			}
		}
	}
	
	for (int i = 0; i < size - 1; i++) 
		for (int j = i + 1; j < size; j++) 
			if (b[i].length() < b[j].length()) 
				swap(b[i], b[j]);
			
		
	for (int i = 0; i < num; i++)
		out << b[i] << endl;

	return 0;
			
}
