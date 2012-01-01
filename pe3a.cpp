#include <iostream>
#include <vector>
using namespace std;

typedef long BIG;
vector<BIG> primes;

BIG stop_factoring_at(BIG x)
{
	return x % 2 == 0 ? x / 2 : x / 2 + 1;
}

void print_long_vector(const vector<BIG>& v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}

void sieve_to(vector<BIG>& primes, BIG x)
{
	bool sieve[x];
	memset(sieve, 1, x);
	BIG j, step;
	for (BIG p = 2; p < x; p++)
	{
		if (sieve[p]) // skip if we already know it isn't a prime number
		{
			primes.push_back(p);
			j = 2;
			step = j * p;
			while (step < x)
			{
				sieve[step] = false;
				++j;
				step = j * p;
			}
		}
	}
}

/*bool is_prime(BIG x)
{
	BIG stop = stop_factoring_at(x);
	// check known primes first
	for (int i = 0; i < primes.size() && primes[i] < stop; i++)
		if (primes[i] != 1 && 0 == x % primes[i])
			return false;
	// check numbers from last known prime up to stop
	for (BIG y = primes.back() + 1; y < stop; y++)
		if (0 == x % y)
			return false;
	primes.push_back(x);
	return true;
}*/

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
			//if (x < y && is_prime(x))
			//largest_prime = x;
		}
	}
	cout << "Stopped testing at: " << i << endl;
	cout << "Largest prime factor: " << largest_prime << endl;
	return 0;





	/*long largest_prime = 1;
	primes.push_back(1);

	long stop = stop_factoring_at(x);
	cout << "I will stop testing at " << stop << endl;
	for (long y = largest_prime + 1; y < stop; y++)
	{
		if (0 == x % y && is_prime(y))
		{
			largest_prime = y;
			cout << "Discovered prime: " << largest_prime << endl;
		}
		if (0 == y % 100000000)
			cout << "Testing: " << y << endl;
	}
	cout << "The largest prime is: " << largest_prime << endl;
	return 0;*/
}
