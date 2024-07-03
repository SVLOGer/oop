#include "primes.h"
#include "vector"
#include <cmath>
#include <stdexcept>

using namespace std;

set<int> GeneratePrimeNumbersSet(int upperBound)
{
	//если меньше, то вернуть пустое множество
	if (upperBound > MaxUpperBound || upperBound < 2)
	{
		throw invalid_argument("Invalid argument");
	}

	vector<bool> sieve(upperBound + 1, true); //сито
	set<int> primes;

	//объяснить как работает
	for (size_t i = 2; i <= upperBound; i++)
	{
		if (sieve[i])
		{
			primes.insert(i);

			for (size_t j = i * i; j <= upperBound; j += i)
			{
				sieve[j] = false;
			}
		}
	}

	return primes;
}
