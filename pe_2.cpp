#include <iostream>
using namespace std;

int main(int argc, const char** argv)
{
	int max = argc == 2 ? atoi(argv[1]) : 4000000;
	int sum = 0;
	int x1 = 1;
	int x2 = 1;
	int x3 = 2;
	while (x3 < max)
	{
		if (0 == x3 % 2)
			sum += x3;
		x1 = x2; 
		x2 = x3;
		x3 = x1 + x2;		
	}
	cout << sum << endl;
	return 0;
}
