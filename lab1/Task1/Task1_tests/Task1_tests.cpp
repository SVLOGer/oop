#include <sstream>

#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../Task1/CopyStreamWithReplacement.h"

using namespace std;

SCENARIO("CopyStreamWithReplacement")
{
	WHEN("INPUT is empty")
	{
		istringstream input("");
		ostringstream output;
		string searchString;
		string replacementString;

		THEN("OUTPUT is empty")
		{
			CopyStreamWithReplacement(input, output, searchString, replacementString);
			REQUIRE(output.str().empty());
		}
	}

	WHEN("INPUT replace one with one")
	{
		istringstream input("11");
		ostringstream output;
		string searchString = "11";
		string replacementString = "22";

		THEN("OUTPUT is 22")
		{
			CopyStreamWithReplacement(input, output, searchString, replacementString);
			REQUIRE(output.str() == "22\n");
		}
	}

	WHEN("INPUT replace one with one and output characters before and after")
	{
		istringstream input("33311333");
		ostringstream output;
		string searchString = "11";
		string replacementString = "22";

		THEN("OUTPUT is 33322333")
		{
			CopyStreamWithReplacement(input, output, searchString, replacementString);
			REQUIRE(output.str() == "33322333\n");
		}
	}

	WHEN("INPUT replace one with one in several lines")
	{
		istringstream input("33311333\n2112\n3");
		ostringstream output;
		string searchString = "11";
		string replacementString = "22";

		THEN("OUTPUT is 33322333\n2222\n3\n")
		{
			CopyStreamWithReplacement(input, output, searchString, replacementString);
			REQUIRE(output.str() == "33322333\n2222\n3\n");
		}
	}

	WHEN("INPUT replace one with several")
	{
		istringstream input("1");
		ostringstream output;
		string searchString = "1";
		string replacementString = "11";

		THEN("OUTPUT is 11\n")
		{
			CopyStreamWithReplacement(input, output, searchString, replacementString);
			REQUIRE(output.str() == "11\n");
		}
	}

	WHEN("INPUT replace one with several and output the rest")
	{
		istringstream input("3331333");
		ostringstream output;
		string searchString = "1";
		string replacementString = "11";

		THEN("OUTPUT is 33311333\n")
		{
			CopyStreamWithReplacement(input, output, searchString, replacementString);
			REQUIRE(output.str() == "33311333\n");
		}
	}

	WHEN("INPUT replace many one with several")
	{
		istringstream input("11");
		ostringstream output;
		string searchString = "1";
		string replacementString = "11";

		THEN("OUTPUT is 1111\n")
		{
			CopyStreamWithReplacement(input, output, searchString, replacementString);
			REQUIRE(output.str() == "1111\n");
		}
	}

	WHEN("INPUT \n")
	{
		istringstream input("\n");
		ostringstream output;
		string searchString = "1";
		string replacementString = "11";

		THEN("OUTPUT is \n")
		{
			CopyStreamWithReplacement(input, output, searchString, replacementString);
			REQUIRE(output.str() == "\n");
		}
	}

	WHEN("INPUT any and searchString is \n")
	{
		istringstream input("11\n11");
		ostringstream output;
		string searchString = "\n";
		string replacementString = "11";

		THEN("OUTPUT is 11\n11\n")
		{
			CopyStreamWithReplacement(input, output, searchString, replacementString);
			REQUIRE(output.str() == "11\n11\n");
		}
	}
	
	WHEN("INPUT any and searchString is nothing")
	{
		istringstream input("22\n22");
		ostringstream output;
		string searchString;
		string replacementString = "33";

		THEN("OUTPUT is 22\n22\n")
		{
			CopyStreamWithReplacement(input, output, searchString, replacementString);
			REQUIRE(output.str() == "22\n22\n");
		}
	}
}