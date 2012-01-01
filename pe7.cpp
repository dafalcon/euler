#include <iostream>
#include <vector>
using namespace std;

vector<long> primes;

long stop_factoring_at(long x)
{
	return x % 2 == 0 ? x / 2 : x / 2 + 1;
}

void print_long_vector(const vector<long>& v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}

void sieve_to(vector<long>& primes, long x)
{
	bool sieve[x];
	memset(sieve, 1, x);
	long j, step;
	for (long p = 2; p < x; p++)
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

bool is_prime(long x)
{
	long stop = stop_factoring_at(x);
	// check known primes first
	for (int i = 0; i < primes.size() && primes[i] < stop; i++)
		if (primes[i] != 1 && 0 == x % primes[i])
			return false;
	// check numbers from last known prime up to stop
	for (long y = primes.back() + 1; y < stop; y++)
		if (0 == x % y)
			return false;
	primes.push_back(x);
	return true;
}

int main(int argc, const char** argv)
{
	vector<long> primes;
	long x = argc == 2 ? atol(argv[1]) : 1000;
	sieve_to(primes, x);
	cout << "primes" << endl;
	print_long_vector(primes);
	if (primes.size() > 10001)
		cout << "10001: " << primes[10000] << endl;
	/*long x = argc == 2 ? atol(argv[1]) : 600851475143;
	cout << "Finding the largest prime factor of " << x << endl;

	long largest_prime = 1;
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
	cout << "The largest prime is: " << largest_prime << endl;*/
	return 0;
}
