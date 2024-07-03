#include "Invert.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) 
    {
        cout << "Неполный ввод, введите в формате: invert.exe <matrix file1>\n";
        return 1;
    }

    string inputFileName = argv[1];

    string result = Invert(inputFileName);

    cout << result;

    return 0;
}