#include "Import.h"
#include "Radix.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {//расставить правильно {
        cout << "Invalid argument count\nUsage: radix.exe <source notation> <destination notation> <value>\n";
        return 1;
    }

    string result = Radix(argv[1], argv[2], argv[3]);

    if (!(cout << result << endl))
    {
        cerr << "Error writing to output" << endl;
        return 1;
    }
    
    return 0;
}
