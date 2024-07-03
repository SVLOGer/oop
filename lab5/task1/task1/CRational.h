#include <utility>
#include <iostream>

// [[nodiscard]] ������������ ��� ����, ����� ����������� �������� �������� �� ���� ���������������
class CRational
{
public:
    // ������������ ������������ �����, ������ ���� (0/1)
    CRational();

    // ������������ ������������ �����, ������ value (value/1)
    CRational(int value);

    // ������������ ������������ �����, ������ numerator/denominator
    // ������������ ����� ������ ��������� � ��������������� ����:
    // ����������� ������������� (��������� ����� ���� �������������)
    // ��������� � ����������� �� ����� ����� ��������� (6/8 => 3/4 � �.�.)
    // ���� ����������� ����� ����, ������ ���������������� ������������ �����, ������ ����,
    // ���� ������ ���� ��������� ���������� std::invalid_argument.
    CRational(int numerator, int denominator);

    // ���������� ���������
    [[nodiscard]] int GetNumerator() const;

    // ���������� ����������� (����������� �����)
    [[nodiscard]] int GetDenominator() const;

    // ���������� ��������� ��������� � ����������� � ���� ����� double
    [[nodiscard]] double ToDouble() const;

    // ��� ����������� ����� � ���� 1(2/4) - ���� ����� � ��� ���������
    [[nodiscard]] std::pair<int, CRational> ToCompoundFraction() const;

    // ������ ��������� �������� �������
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

    // ��� ���������� �����
    void Normalize();

    // ��� ������ ���
    int GetGCD(int a, int b);
};
