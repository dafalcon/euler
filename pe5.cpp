#include <iostream>
using namespace std;

typedef unsigned long long BIG;

inline bool factorable_by_digits(BIG x, BIG max)
{
	for (BIG i = max - 1; i > 1; --i)
		if (0 != x % i)
			return false;
	return true;
}

inline BIG brute_force(BIG max)
{
	BIG x;
	for (x = max; !factorable_by_digits(x, max); x += max);
	return x;
}

int main(BIG argc, const char** argv)
{
	BIG max = argc == 2 ? atoi(argv[1]) : 20;
	cout << "Finding the smallest number that can be divided by each of the integers 1.." << max << endl;
	cout << brute_force(max) << endl;
	return 0;
}


