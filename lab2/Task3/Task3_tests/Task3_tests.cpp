#include <sstream>

#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../Task3/Dictionary.h"

using namespace std;

SCENARIO("Dictionary")
{
    WHEN("INPUT is empty")
    {
        THEN("OUTPUT is empty")
        {
            string dictionaryFilename;
            unordered_map<string, string> dictionary;
            Dictionary(dictionaryFilename, dictionary);
            REQUIRE();
        }//тесты
    }
}
