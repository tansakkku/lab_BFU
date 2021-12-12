#pragma once

const int w = 10000;
const int v = 100;

namespace hd
{
	bool Min(int mas[v][v], int n, int m);

	bool Max(int mas[v][v], int n, int m);

	void Sum_Strok_i_Sort(int sum[w], int mas[v][v], int n, int m);
}
