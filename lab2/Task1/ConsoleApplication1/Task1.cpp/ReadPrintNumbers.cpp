#include "ReadPrintNumbers.h"

using namespace std;

vector<double> ReadInput()
{
    //итераторы
    vector<double> numbers;
    istream_iterator<double> it(cin);
    istream_iterator<double> end;

    while (it != end) 
    {
        numbers.push_back(*it);
        ++it;
    }

    if (!cin.eof()) 
    {
        cout << "Error: It's not number" << endl;
        return {};
    }

    return numbers;
}

void PrintNumbers(vector<double>& numbers)
{
    for (const auto& num : numbers) 
    {
        if (!(cout << fixed << setprecision(5) << num << " "))
        {
            cout << "Error: Error print";
            return;
        }
    }
    cout << endl;
}