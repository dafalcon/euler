#include <iostream>
#include <vector>
using namespace std;

typedef long BIG;

bool is_prime(BIG x)
{
	if (0 == x % 2)
		return false;
	for (BIG i = 3; i < x / 2 + 1; i += 2)
		if (0 == x % i)
			return false;
	return true;
}

int main(int argc, const char** argv)
{
	BIG n = argc == 2 ? atol(argv[1]) : 600851475143;
	cout << "Finding the largest prime factor of " << n << endl;
	BIG x = 1;
	BIG y = n;
	BIG largest_prime = 1;
	BIG i;

	// walk through integers trying to find factors of n.
	// if x = some factor of n and y = n / x, 
	// you can stop when x > y because at that point you're only
	// finding factors you've already found since multiplication 
    // is commutative (x * y = n and y * x = n)

	// i could write this a bit more efficiently so it doesn't check
	// for a largest prime the last time through the loop (we've
	// already checked those numbers)
	for (i = 2; i < n / 2 + 1 && x < y; ++i)
	{
		if (0 == n % i)
		{
			x = i;
			y = n / i;
			cout << x << " " << y << endl;

			if (x > largest_prime && is_prime(x))
				largest_prime = x;
			if (y > largest_prime && is_prime(y))
				largest_prime = y;
		}
	}
	cout << "Stopped testing at: " << i << endl;
	cout << "Largest prime factor: " << largest_prime << endl;
	return 0;
}
