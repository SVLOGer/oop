#include <sstream>

#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../Task3/Invert.h"

using namespace std;

SCENARIO("Invert")
{
	WHEN("INPUT is empty")
	{
		string inputFileName = "";
		THEN("OUTPUT is error")
		{
			REQUIRE(Invert(inputFileName) == "");
		}
	}

	WHEN("Matrix not singular")
	{
		string inputFileName = "right_matrix";
		THEN("OUTPUT is right")
		{
			REQUIRE(Invert(inputFileName) == "-0.297297 -0.108108 0.189189\n-0.486486 0.459459 -0.054054\n0.756756 -0.270270 -0.027027");
		}
	}
	WHEN("Matrix is singular")
	{
		string inputFileName = "singular_matrix";
		THEN("OUTPUT is error")
		{
			REQUIRE(Invert(inputFileName) == "");
		}
	}
}