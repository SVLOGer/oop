#include <iostream>
#include "CRational.h"
//�������� �������� ��� ������
//��������� ToCompoundFraction ��� �������������
int main()
{
    CRational rationalA(-1, 2);
    CRational rationalB(1, -2);
    //����������� �������� �������� � ������� ����� �������� ��� ����� �����
    std::cin >> rationalA >> rationalB;
    std::pair<int, CRational> expectingPair = (rationalA + rationalB).ToCompoundFraction();
    std::cout << expectingPair.first << " " << expectingPair.second;
}
