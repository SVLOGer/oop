#include <sstream>

#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../task4/primes.h"

using namespace std;

SCENARIO("Primes")
{
    WHEN("INPUT is 10")
    {
        THEN("OUTPUT is 2 3 5 7")
        {
            auto primes = GeneratePrimeNumbersSet(10);
            set<int> answer = { 2, 3, 5, 7 };
            REQUIRE(primes == answer);
        }
    }

    WHEN("INPUT is 2")
    {
        THEN("OUTPUT is 2")
        {
            auto primes = GeneratePrimeNumbersSet(2);
            set<int> answer = { 2 };
            REQUIRE(primes == answer);
        }
    }

    WHEN("INPUT is 100'000'000")
    {
        THEN("OUTPUT is 5761455 primes")
        {
            auto primes = GeneratePrimeNumbersSet(100000000);
            REQUIRE(primes.size() == 5761455);
        }
    }

    WHEN("INPUT is lower  then minimal prime")
    {
        THEN("OUTPUT is error")
        {
            REQUIRE_THROWS_AS(GeneratePrimeNumbersSet(0), invalid_argument);
        }
    }

    WHEN("INPUT is bigger then 100'000'000")
    {
        THEN("OUTPUT is error")
        {
            REQUIRE_THROWS_AS(GeneratePrimeNumbersSet(100000001), invalid_argument);
        }
    }
}
