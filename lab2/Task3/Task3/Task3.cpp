#include "Dictionary.h"
#include <fcntl.h>
#include <io.h>

using namespace std;

int main(int argc, char* argv[]) 
{
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <dictionary_file>" << endl;
        return 1;
    }

    const string dictionaryFilename = argv[1];

    Dictionary(dictionaryFilename);

    return 0;
}