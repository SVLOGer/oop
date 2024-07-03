#include <iostream>
#include <sstream>
#include <vector>
#define CATCH_CONFIG_MAIN
#include "../task1/CRational.h"
#include "../../../catch2/catch.hpp"

using namespace std;

TEST_CASE("empty input")
{
    CRational rational;

    REQUIRE(rational.GetNumerator() == 0);
    REQUIRE(rational.GetDenominator() == 1);
}

TEST_CASE("int input")
{
    CRational rational(10);

    REQUIRE(rational.GetNumerator() == 10);
    REQUIRE(rational.GetDenominator() == 1);
}

TEST_CASE("numerator and denominator input")
{
    CRational rational(10, 1);

    REQUIRE(rational.GetNumerator() == 10);
    REQUIRE(rational.GetDenominator() == 1);
}

TEST_CASE("input needs to be normalized")
{
    CRational rational(10, 2);

    REQUIRE(rational.GetNumerator() == 5);
    REQUIRE(rational.GetDenominator() == 1);
}

TEST_CASE("input is negative numerator")
{
    CRational rational(-10, 1);

    REQUIRE(rational.GetNumerator() == -10);
    REQUIRE(rational.GetDenominator() == 1);
}

TEST_CASE("input is negative denominator")
{
    CRational rational(10, -1);

    REQUIRE(rational.GetNumerator() == -10);
    REQUIRE(rational.GetDenominator() == 1);
}

TEST_CASE("input is zero denominator")
{
    REQUIRE_THROWS_AS(CRational(10, 0), invalid_argument);
}

template <typename T>
string toStringWithPrecision(const T value, const int n = 2)
{
    ostringstream out;
    out.precision(n);
    out << fixed << value;
    return move(out).str();
}

TEST_CASE("input is need to convertation to double")
{
    CRational rational(3, 5);
    double expectingDouble = 0.6;
    auto result1 = toStringWithPrecision(rational.ToDouble());
    auto result2 = toStringWithPrecision(expectingDouble);

    REQUIRE(result1 == result2);
}

TEST_CASE("input is need to convertation to mixed")
{
    CRational rational(7, 5);
    pair<int, CRational> expectingPair = { 1, CRational(2, 5) };

    REQUIRE(rational.ToCompoundFraction() == expectingPair);
}

TEST_CASE("input is int and need to convertation to mixed")
{
    CRational rational(5, 5);
    pair<int, CRational> expectingPair = { 1, CRational(0, 1) };

    REQUIRE(rational.ToCompoundFraction() == expectingPair);
}

TEST_CASE("input is ratonal and need to convertation to mixed")
{
    CRational rational(2, 5);
    pair<int, CRational> expectingPair = { 0, CRational(2, 5) };

    REQUIRE(rational.ToCompoundFraction() == expectingPair);
}

TEST_CASE("input is zero numerator and need to convertation to mixed")
{
    CRational rational(0, 5);
    pair<int, CRational> expectingPair = { 0, CRational(0, 1) };

    REQUIRE(rational.ToCompoundFraction() == expectingPair);
}

TEST_CASE("input is need to convertation to negative")
{
    CRational rational(7, 5);
    CRational expectingRational(-7, 5);

    REQUIRE(-rational == expectingRational);
}

TEST_CASE("input is need to convertation to positive")
{
    CRational rational(7, 5);
    CRational expectingRational(7, 5);

    REQUIRE(+rational == expectingRational);
}


TEST_CASE("test sum")
{
    CRational rationalA(5, 5);
    CRational rationalB(2, 1);
    CRational expectingRational(3, 1);

    REQUIRE(rationalA + rationalB == expectingRational);
}

TEST_CASE("test sum with int")
{
    CRational rationalA(5, 5);
    CRational expectingRational(3, 1);

    REQUIRE(rationalA + 2 == expectingRational);
}

TEST_CASE("test sub")
{
    CRational rationalA(7, 5);
    CRational rationalB(2, 1);
    CRational expectingRational(-3, 5);

    REQUIRE(rationalA - rationalB == expectingRational);
}

TEST_CASE("test sub with int")
{
    CRational rationalA(7, 5);
    CRational expectingRational(-3, 5);

    REQUIRE(rationalA - 2 == expectingRational);
}

TEST_CASE("test unar sum")
{
    CRational rationalA(5, 5);
    CRational rationalB(2, 1);
    rationalA += rationalB;
    CRational expectingRational(3, 1);

    REQUIRE(rationalA == expectingRational);
}

TEST_CASE("test unar sum with int")
{
    CRational rationalA(5, 5);
    rationalA += 2;
    CRational expectingRational(3, 1);

    REQUIRE(rationalA == expectingRational);
}

TEST_CASE("test unar sub")
{
    CRational rationalA(7, 5);
    CRational rationalB(2, 3);
    rationalA -= rationalB;
    CRational expectingRational(11, 15);

    REQUIRE(rationalA == expectingRational);
}

TEST_CASE("test unar sub with int")
{
    CRational rationalA(7, 5);
    rationalA -= 2;
    CRational expectingRational(-3, 5);

    REQUIRE(rationalA == expectingRational);
}

TEST_CASE("test multiply")
{
    CRational rationalA(7, 5);
    CRational rationalB(2, 3);
    CRational expectingRational(14, 15);

    REQUIRE(rationalA * rationalB == expectingRational);
}

TEST_CASE("test multiply with int")
{
    CRational rationalA(7, 5);
    CRational expectingRational(14, 5);

    REQUIRE(rationalA * 2 == expectingRational);
}

TEST_CASE("test div")
{
    CRational rationalA(7, 5);
    CRational rationalB(2, 3);
    CRational expectingRational(21, 10);

    REQUIRE(rationalA / rationalB == expectingRational);
}

TEST_CASE("test div with int")
{
    CRational rationalA(7, 5);
    CRational expectingRational(7, 10);

    REQUIRE(rationalA / 2 == expectingRational);
}

TEST_CASE("test unar mupltiplay")
{
    CRational rationalA(7, 5);
    CRational rationalB(2, 3);
    CRational expectingRational(14, 15);
    rationalA *= rationalB;

    REQUIRE(rationalA == expectingRational);
}

TEST_CASE("test unar mupltiplay with int")
{
    CRational rationalA(7, 5);
    CRational expectingRational(14, 5);
    rationalA *= 2;

    REQUIRE(rationalA == expectingRational);
}

TEST_CASE("test unar div")
{
    CRational rationalA(7, 5);
    CRational rationalB(2, 3);
    CRational expectingRational(21, 10);
    rationalA /= rationalB;

    REQUIRE(rationalA == expectingRational);
}

TEST_CASE("test unar div with int")
{
    CRational rationalA(7, 5);
    CRational expectingRational(7, 10);
    rationalA /= 2;

    REQUIRE(rationalA == expectingRational);
}

TEST_CASE("true test compare equal")
{
    CRational rationalA(7, 5);
    CRational rationalB(7, 5);

    REQUIRE(rationalA == rationalB);
}

TEST_CASE("false test compare equal")
{
    CRational rationalA(7, 5);
    CRational rationalB(2, 5);

    REQUIRE(!(rationalA == rationalB));
}

TEST_CASE("test compare equal with one: numerator neg and denominator positive, second convert one")
{
    CRational rationalA(-1, 2);
    CRational rationalB(1, -2);

    REQUIRE(rationalA == rationalB);
}

TEST_CASE("true test compare not equal")
{
    CRational rationalA(7, 5);
    CRational rationalB(2, 5);

    REQUIRE(rationalA != rationalB);
}

TEST_CASE("false test compare not equal")
{
    CRational rationalA(7, 5);
    CRational rationalB(7, 5);

    REQUIRE(!(rationalA != rationalB));
}

TEST_CASE("true test compare smaller equal")
{
    CRational rationalA(7, 5);
    CRational rationalB(7, 5);
    CRational rationalC(5, 5);

    REQUIRE(rationalA <= rationalB);
    REQUIRE(rationalC <= rationalB);
}


TEST_CASE("false test compare less or equal")
{
    CRational rationalB(7, 5);
    CRational rationalC(5, 5);

    REQUIRE(!(rationalB <= rationalC));
}

TEST_CASE("true test compare smaller")
{
    CRational rationalB(7, 5);
    CRational rationalC(5, 5);

    REQUIRE(rationalC < rationalB);
}

TEST_CASE("false test compare smaller")
{
    CRational rationalB(7, 5);
    CRational rationalC(5, 5);

    REQUIRE(!(rationalB < rationalC));
}

TEST_CASE("true test compare bigger equal")
{
    CRational rationalA(7, 5);
    CRational rationalB(7, 5);
    CRational rationalC(5, 5);

    REQUIRE(rationalA >= rationalB);
    REQUIRE(rationalB >= rationalC);
}

TEST_CASE("false test compare bigger equal")
{
    CRational rationalB(7, 5);
    CRational rationalC(5, 5);

    REQUIRE(!(rationalC >= rationalB));
}

TEST_CASE("true test compare bigger")
{
    CRational rationalB(7, 5);
    CRational rationalC(5, 5);

    REQUIRE(rationalB > rationalC);
}

TEST_CASE("false test compare bigger")
{
    CRational rationalB(7, 5);
    CRational rationalC(5, 5);

    REQUIRE(!(rationalC > rationalB));
}

TEST_CASE("test cout and cin")
{
    CRational rationalB(7, 5);
    CRational rationalA;
    std::stringstream ss;
    ss << rationalB;
    ss >> rationalA;

    REQUIRE(rationalA == rationalB);
}