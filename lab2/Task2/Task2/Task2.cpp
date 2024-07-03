#include "HtmlDecode.h"

using namespace std;

int main() 
{
    string line;
    while (getline(cin, line)) 
    {
        if (!(cout << HtmlDecode(line) << std::endl))
        {
            cout << "Error: error in output" << endl;
        }
    }
    return 0;
}