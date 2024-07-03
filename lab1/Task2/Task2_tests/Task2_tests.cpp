#include <sstream>

#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../Task2/Radix.h"

using namespace std;

SCENARIO("StringToInt, IntToString")
{
	WHEN("INPUT is empty")
	{
		THEN("OUTPUT is error")
		{
			REQUIRE(Radix("", "","") == "Error: Base should be between 2 and 36\n");
		}
	}

	WHEN("INPUT value is empty")
	{
		THEN("OUTPUT is error")
		{
			REQUIRE(Radix("2", "4","") == "Error: Value is empty");
		}
	}

	WHEN("INPUT value is positive")
	{
		THEN("OUTPUT is positive")
		{
			REQUIRE(Radix("16", "10", "1F") == "31");
		}
	}

	WHEN("INPUT value is negative")
	{
		THEN("OUTPUT is negative")
		{
			REQUIRE(Radix("16", "10", "-1F") == "-31");
		}
	}

	WHEN("INPUT value is bigger than max int")
	{
		THEN("OUTPUT is error")
		{
			REQUIRE(Radix("10", "2", "2147483648") == "Error: Number is bigger than max number");
		}
	}

	WHEN("INPUT value is max int")
	{
		THEN("OUTPUT is max int in current radix")
		{
			REQUIRE(Radix("10", "2", "2147483647") == "1111111111111111111111111111111");
		}
	}

	WHEN("INPUT value is 0")
	{
		THEN("OUTPUT is 0")
		{
			REQUIRE(Radix("10", "2", "0") == "0");
		}
	}
}
