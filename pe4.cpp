#include <string.h>
#include <stdlib.h>
//#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

// TODO: if upper_bound is greater than MAX_INT, use unsigned long long and atoll
// else use unsigned int and atoi

// OR 
// stop using strings
// actually strings might not be so bad - generating the next palindrome is cheap and infrequent
// it's the division that takes a long time

typedef unsigned long long BIGNUM;
//typedef unsigned int BIGNUM;

inline bool is_palindrome(const char* s, int length)
{
	for (int i = 0; i < length / 2; ++i)
		if (s[i] != s[length - i - 1])
			return false;
	return true;
}

inline char* next_largest_palindrome(char* s, int starting_digits)
{
	// assuming s is already a numeric palindrome, find the next
	// lowest
	int digits = starting_digits;
//	while (digits > 0)
	//{
		int half_digits = digits / 2;
		bool even = 0 == digits % 2;
		int init_i, init_j;
		
		if (even)
		{
			init_i = half_digits - 1;
			init_j = half_digits;
		}
		else init_i = init_j = half_digits;

		// find the first digit that isn't zero and decrement it
		int j = init_j;
		for (int i = init_i; i > -1; --i)
		{
			if (even && i == init_i)
			{
				if (s[i] == '0')
				{
					s[i] = s[j] = '9';
				}
				else
				{
					s[i] = s[j] = s[i] - 1;
					return s;
				}
			}
			else
			{
				if (s[i] == '0')
					s[i] = s[j] = '9';
				else
				{
					s[i] = s[j] = s[i] - 1;
					return s;
				}
			}
			++j;
		}

		// everything is zero at this point
		cout << s << endl;
		//}
		return NULL;
}

inline bool is_factorable_into(BIGNUM x, int upper_factor, int lower_factor)
{
	BIGNUM div;
	//printf("checking %llu %d %d\n", x, upper_factor, lower_factor);
	for (int i = upper_factor; i >= lower_factor; --i)
	{
		if (0 == x % i)
		{
			div = x / i;
			if (div > upper_factor)
				return false;
			else if (div >= lower_factor)
			{
				printf("factors: %d %llu\n", i, div);
				return true;
			}
		}
	}
	return false;
}

// find the largest palindrome that is a product of two n digit
// integers. 
int main(int argc, const char** argv)
{
	// n is the number of digits, defaults to 3
	int n = argc == 2 ? atoi(argv[1]) : 3;

	// calculate upper and lower bounds
	BIGNUM upper_factor = 0;
	BIGNUM lower_factor = pow(10, n - 1);
	for (int i = 0; i < n; ++i)
		upper_factor += 9 * pow(10, i);
	BIGNUM upper_bound = upper_factor * upper_factor;

	printf("Searching for the largest palindrome that is a product of two %d digit integers...\n", n);
	cout << "Upper bound = " << upper_bound << endl;

	// find largest palindrome
	char buffer[128];
	int digits = sprintf(buffer, "%llu", upper_bound);
	while (!is_palindrome(buffer, digits))
	{
		--upper_bound;
		digits = sprintf(buffer, "%llu", upper_bound);
	}

	printf("Largest possible palindrome = %s\n", buffer);
	char* next = buffer;
	while (NULL != next)
	{
		if (is_factorable_into(atoll(buffer), upper_factor, lower_factor))
		{
			printf("answer: %s\n", buffer);
			return 0;
		}
		next = next_largest_palindrome(buffer, digits);
	}
	printf("No answer found, may need to reduce digits in next_largest_palindrome\n");
	printf("%s\n", buffer);
	return 1;
}
