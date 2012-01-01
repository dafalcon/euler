#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int max = argc == 2 ? atoi(argv[1]) : 1000;
	long sum = 0;
	cout << "Computing sum of all multiples of 3 and 5 up to " << max << "... ";
	for (int x = 1; x < max; x++)
		if (x % 3 == 0 || x % 5 == 0)
			sum += x;
	cout << sum << endl;
	return 0;
}
