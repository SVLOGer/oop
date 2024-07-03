#include <utility>
#include <iostream>

// [[nodiscard]] используется для того, чтобы возращаемое функцией значение не было проигнорировано
class CRational
{
public:
    // Конструирует рациональное число, равное нулю (0/1)
    CRational();

    // Конструирует рациональное число, равное value (value/1)
    CRational(int value);

    // Конструирует рациональное число, равное numerator/denominator
    // Рациональное число должно храниться в нормализованном виде:
    // знаменатель положительный (числитель может быть отрицательным)
    // числитель и знаменатель не имеют общих делителей (6/8 => 3/4 и т.п.)
    // Если знаменатель равен нулю, должно конструироваться рациональное число, равное нулю,
    // либо должно быть выброшено исключение std::invalid_argument.
    CRational(int numerator, int denominator);

    // Возвращает числитель
    [[nodiscard]] int GetNumerator() const;

    // Возвращает знаменатель (натуральное число)
    [[nodiscard]] int GetDenominator() const;

    // Возвращает отношение числителя и знаменателя в виде числа double
    [[nodiscard]] double ToDouble() const;

    // Для возвращения числа в виде 1(2/4) - одна целая и две четвертых
    [[nodiscard]] std::pair<int, CRational> ToCompoundFraction() const;

    // Прочие операторы согласно заданию
    CRational operator+() const;

    CRational operator-() const;

    CRational operator+(const CRational& rational) const;

    CRational operator-(const CRational& rational) const;

    CRational& operator+=(CRational const& rational);

    void operator-=(CRational const& rational);

    CRational operator*(const CRational& rational) const;

    CRational operator/(const CRational& rational) const;

    void operator*=(CRational const& rational);

    void operator/=(CRational const& rational);

    bool operator==(const CRational& rational) const;

    bool operator!=(const CRational& rational) const;

    bool operator<(const CRational& rational) const;

    bool operator<=(const CRational& rational) const;

    bool operator>(const CRational& rational) const;

    bool operator>=(const CRational& rational) const;

    friend std::ostream& operator<<(std::ostream& stream, const CRational& rational);

    friend std::istream& operator>>(std::istream& stream, CRational& rational);

private:
    int m_numerator;
    int m_denominator;

    // Для сокращение дроби
    void Normalize();

    // Для поиска НОД
    int GetGCD(int a, int b);
};
