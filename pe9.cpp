#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(int argc, const char** argv)
{
	int a, b, a2;
	double c;
	double product = 0;
	double sum = 0;
	for (a = 3; sum != 1000 && a < 1000; ++a)
	{
		a2 = pow(a, 2);
		sum = 0;
		for (b = a + 1; sum < 1000; ++b)
		{
			c = (sqrt(a2 + pow(b, 2)));
			sum = a + b + c;
			/*if (c == floor(c))
			  cout << a << " " << b << " " << c << " " << sum << endl;*/
		}
	}
	--a;
	--b;
	cout << a << " " << b << " " << c << " " << sum << endl;
	cout << (int)(a * b * c) << endl;
	return 0;
}
