#include "ProcessNumbers.h"

using namespace std;

void ProcessNumbers(vector<double>& numbers)
{
    if (!numbers.empty()) 
    {
        auto [minPos, maxPos] = minmax_element(numbers.begin(), numbers.end());
        double min = *minPos;
        double max = *maxPos;

        //алгоритм трансформ
        transform(numbers.begin(), numbers.end(), numbers.begin(), [min, max](double num) 
            {
                if (num < 0) {
                    return num * min * max;
                }
                return num;
            }
        );
    }
}