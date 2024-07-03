#include <iostream>
#include "CRational.h"
//Бинарные операции вне класса
//Исправить ToCompoundFraction для отрицательных
int main()
{
    CRational rationalA(-1, 2);
    CRational rationalB(1, -2);
    //Реализовать бинарные операции в которых левый аргумент это целое число
    std::cin >> rationalA >> rationalB;
    std::pair<int, CRational> expectingPair = (rationalA + rationalB).ToCompoundFraction();
    std::cout << expectingPair.first << " " << expectingPair.second;
}
