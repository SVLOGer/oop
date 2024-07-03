#include <sstream>

#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../Task1.cpp/ProcessNumbers.h"

using namespace std;

SCENARIO("ProcessNumbers")
{
    WHEN("INPUT is empty")
    {
        THEN("OUTPUT is empty")
        {
            std::vector<double> numbers;
            ProcessNumbers(numbers);
            REQUIRE(numbers.empty());
        }
    }

    WHEN("INPUT is single positive number")
    {
        THEN("OUTPUT is error")
        {
            vector<double> numbers = { 5.5 };
            ProcessNumbers(numbers);
            REQUIRE(numbers.size() == 1);
            REQUIRE(numbers[0] == 5.5);
        }
    }

    WHEN("INPUT is single negative number")
    {
        THEN("OUTPUT is error")
        {
            vector<double> numbers = { -3.7 };
            ProcessNumbers(numbers);
            REQUIRE(numbers.size() == 1);
            REQUIRE(numbers[0] == -3.7 * -3.7 * -3.7);
        }
    }

    WHEN("INPUT is positive and negative numbers")
    {
        THEN("OUTPUT is error")
        {
            vector<double> numbers = { 1.2, -2.3, 3.4, -4.5, 5.6 };
            ProcessNumbers(numbers);
            REQUIRE(numbers.size() == 5 );
            REQUIRE(numbers[0] == 1.2);
            REQUIRE(numbers[1] == -2.3 * 5.6 * -4.5);
            REQUIRE(numbers[2] == 3.4);
            REQUIRE(numbers[3] == -4.5 * 5.6 * -4.5);
            REQUIRE(numbers[4] == 5.6);
        }
    }

    WHEN("INPUT same negative numbers")
    {
        THEN("OUTPUT is error")
        {
            vector<double> numbers = { -2.4, -2.4, -2.4, -2.4 };
            ProcessNumbers(numbers);
            REQUIRE(numbers.size() == 4);
            REQUIRE(numbers[0] == -2.4 * -2.4 * -2.4);
            REQUIRE(numbers[1] == -2.4 * -2.4 * -2.4);
            REQUIRE(numbers[2] == -2.4 * -2.4 * -2.4);
            REQUIRE(numbers[3] == -2.4 * -2.4 * -2.4);
        }
    }

    WHEN("INPUT same positive numbers")
    {
        THEN("OUTPUT is error")
        {
            vector<double> numbers = { 3.1, 3.1, 3.1, 3.1 };
            ProcessNumbers(numbers);
            REQUIRE(numbers.size() == 4);
            REQUIRE(numbers[0] == 3.1);
            REQUIRE(numbers[1] == 3.1);
            REQUIRE(numbers[2] == 3.1);
            REQUIRE(numbers[3] == 3.1);
        }
    }
}
