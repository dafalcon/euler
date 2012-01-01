#include <iostream>
#include <math.h>
using namespace std;

typedef unsigned long long BIG;

BIG brute_force(BIG max)
{
	BIG sum = 1;
	BIG sum_squares = 1;
	++max;
	for (BIG i = 2; i < max; ++i)
	{
		sum_squares += pow(i, 2);
		sum += i;
	}

	cout << "Sum squares " << sum_squares << endl;
	cout << "Sum " << sum << endl;

	return pow(sum, 2) - sum_squares;
}

int main(BIG argc, const char** argv)
{
	BIG max = argc == 2 ? atoi(argv[1]) : 20;
	cout << "Finding the difference between the sum of the square and the square of the sums up to " << max << endl;
	cout << "Answer " << brute_force(max) << endl;
	return 0;
}
