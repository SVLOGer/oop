#include <iostream>
#include "primes.h"
#include <string>

using namespace std;

struct Args
{
	int upperBound;
};

Args ParseArgs(int argc, char** argv)
{
	if (argc != 2)
	{
		throw invalid_argument("Invalid arguments count\nUsage: primes.cpp <upper bound>");
	}

	Args args;
	args.upperBound = stoi(argv[1]);

	return args;
}

void PrintSet(const set<int> set)
{
	for (auto element : set)
	{
		if (!(cout << element << " "))
		{
			throw runtime_error("Error during output");
		}
	}
	cout << endl;
}

int main(int argc, char** argv)
{
	try
	{
		auto args = ParseArgs(argc, argv);
		auto primes = GeneratePrimeNumbersSet(args.upperBound);
		cout << "Primes: ";
		PrintSet(primes);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
		return 0;
	}

	return 1;
}