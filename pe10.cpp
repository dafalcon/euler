#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool* sieve(bool* s, int size)
{
	memset(s, 1, size);
	int i = 2;
	int step;
	while (i < size / 2 + 1)
	{
		if (s[i])
		{
			step = i + i;
			while (step < size)
			{
				s[step] = false;
				step += i;
			}
		}
		++i;
	}
	return s;
}

int main(int argc, const char** argv)
{
	int max = argc == 2 ? atoi(argv[1]) : 2000000;
	++max;
	bool s[max];
	sieve(s, max);
	long long sum = 0;
	for (int i = 2; i < max; ++i)
		if (s[i])
			sum += i;
	cout << sum << endl;
}
