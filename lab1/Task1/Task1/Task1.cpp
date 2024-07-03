#include "Import.h"
#include "CopyStreamWithReplacement.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 5)
    {
        cout << "Invalid argument count\nUsage: replace.exe <inputFile> <outputFile> <searchString> <replacementString>\n" << endl;
        return 1;
    }

    //обернуть копи и все остальное в одну функцию
    ifstream inputFile;
    

    ofstream outputFile;
    

    string search = argv[3];
    string replace = argv[4];

    CopyStreamWithReplacement(inputFile, outputFile, search, replace);
    if (!outputFile.flush())
    {
        cout << "Failed to save data on disk\n";
        return 1;
    }
    
    return 0;
}