#include "ProcessNumbers.h"
#include "ReadPrintNumbers.h"

using namespace std;

int main() 
{
    vector<double> numbers = ReadInput();

    ProcessNumbers(numbers);

    std::ranges::sort(numbers);
    PrintNumbers(numbers);

    return 0;
}
