#include <stdexcept>
#include "CRational.h"
#include <iostream>

using namespace std;

CRational::CRational() : m_numerator(0), m_denominator(1)
{
}

CRational::CRational(int value) : m_numerator(value), m_denominator(1)
{
}

CRational::CRational(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator)
{
    if (denominator == 0)
    {
        throw invalid_argument("Denominator can't be zero");
    }
    if (denominator < 0)
    {
        m_numerator = -m_numerator;
        m_denominator = -m_denominator;
    }
    Normalize();
}

int CRational::GetNumerator() const
{
    return m_numerator;
}

int CRational::GetDenominator() const
{
    return m_denominator;
}

double CRational::ToDouble() const
{
    return static_cast<float>(m_numerator) / static_cast<float>(m_denominator);
}

void CRational::Normalize()
{
    int gcd = GetGCD(m_numerator, m_denominator);
    m_numerator /= gcd;
    m_denominator /= gcd;
}

int CRational::GetGCD(int a, int b)
{
    if (a < b)
    {
        swap(a, b);
    }
    if (b == 0)
    {
        return a;
    }
    while (a % b != 0)
    {
        a = a % b;
        swap(a, b);
    }
    return b;
}

CRational CRational::operator+() const
{
    return *this;
}

CRational CRational::operator-() const
{
    return { -m_numerator, m_denominator };
}

CRational CRational::operator+(const CRational& rational) const
{
    int resDenominator = GetDenominator() * rational.GetDenominator();
    int resNumerator = m_numerator * rational.GetDenominator() + rational.GetNumerator() * GetDenominator();
    return { resNumerator, resDenominator };
}

CRational CRational::operator-(const CRational& rational) const
{
    int resDenominator = GetDenominator() * rational.GetDenominator();
    int resNumerator = m_numerator * rational.GetDenominator() - rational.GetNumerator() * GetDenominator();
    return { resNumerator, resDenominator };
}

CRational& CRational::operator+=(const CRational& rational)
{
    *this = *this + rational;
    Normalize();
    return *this;
}

void CRational::operator-=(const CRational& rational)
{
    *this = *this - rational;
    Normalize();
}

CRational CRational::operator*(const CRational& rational) const
{
    return {
        GetNumerator() * rational.GetNumerator(),
        GetDenominator() * rational.GetDenominator()
    };
}

CRational CRational::operator/(const CRational& rational) const
{
    return {
        GetNumerator() * rational.GetDenominator(),
        GetDenominator() * rational.GetNumerator()
    };
}

void CRational::operator*=(const CRational& rational)
{
    *this = *this * rational;
    Normalize();
}

void CRational::operator/=(const CRational& rational)
{
    *this = *this / rational;
    Normalize();
}

bool CRational::operator==(const CRational& rational) const
{
    return (GetDenominator() == rational.GetDenominator()) && (GetNumerator() == rational.GetNumerator());
}

bool CRational::operator!=(const CRational& rational) const
{
    return !((GetDenominator() == rational.GetDenominator()) && (GetNumerator() == rational.GetNumerator()));
}

bool CRational::operator<(CRational const& rational) const
{
    return (GetNumerator() * rational.GetDenominator() < rational.GetNumerator() * GetDenominator());
}

bool CRational::operator<=(CRational const& rational) const
{
    return (GetNumerator() * rational.GetDenominator() <= rational.GetNumerator() * GetDenominator());
}

bool CRational::operator>(CRational const& rational) const
{
    //“есты операции сравнени€ должны провер€ть граничные услови€, например если > помен€ть на >=
    return (GetNumerator() * rational.GetDenominator() > rational.GetNumerator() * GetDenominator());
}

bool CRational::operator>=(CRational const& rational) const
{
    return (GetNumerator() * rational.GetDenominator() >= rational.GetNumerator() * GetDenominator());
}

ostream& operator<<(ostream& stream, const CRational& rational)
{
    stream << rational.GetNumerator() << '/' << rational.GetDenominator();
    return stream;
}

istream& operator>>(istream& stream, CRational& rational)
{
    int numerator;
    int denominator;

    if ((stream >> numerator) && (stream.get() == '/') && (stream >> denominator))
    {
        rational = { numerator, denominator };
    }
    else
    {
        stream.setstate(stream.rdstate() | ios_base::failbit); //ошибка
    }
    return stream;
}

pair<int, CRational> CRational::ToCompoundFraction() const
{
    int intPart = m_numerator / m_denominator;
    return {
        intPart,
        CRational(abs(m_numerator % m_denominator), m_denominator)
    };
}
