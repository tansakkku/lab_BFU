#include <iostream>
#include <chrono>

using namespace std;

const int N = 10000;

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};


int main()
{
	int mas[N];

	Timer t;

	if (N > 10000)
		return 0;

	for (int i = 0; i <= N; i++)
	{
		mas[i] = rand();
		//cout << "Time elapsed: " << t.elapsed() << endl;
	}


	for (int i = 0; i <= N; i++)
		if (mas[i] % 2 != 0)
		{
			cout << "Final: " << mas[i] << endl;
			cout << "Time elapsed: " << t.elapsed() << endl;
			return 0;
		}

	//Сложноть кода О(N)

}