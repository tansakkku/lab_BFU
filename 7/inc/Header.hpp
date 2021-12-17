#pragma once

const int w = 10000;
const int v = 100;

namespace hd
{
	void Input(int n, int m, int mas[v][v]);

	void Output(int n, int m, int mas[v][v]);

	bool Min(int mas[v][v], int n, int m);

	bool Max(int mas[v][v], int n, int m);

	void Proizved_Strok_i_Sort(int sum[w], int mas[v][v], int n, int m);
}
