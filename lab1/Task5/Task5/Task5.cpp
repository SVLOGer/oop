#include "Fill.h"
#include <iostream>
#include <vector>

struct Args
{
	std::string inputFileName;
	std::string outputFileName;
};

Args ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		throw std::invalid_argument("Invalid arguments count\nUsage: {} <input file> <output file>");
	}

	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];

	return args;
}

int main(int argc, char* argv[])
{
	try
	{
		auto args = ParseArgs(argc, argv);
		FillMap(args.inputFileName, args.outputFileName);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
