#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#define CATCH_CONFIG_MAIN
#include "../Task4/CryptTools.h"
#include "../../../catch2/catch.hpp"

using namespace std;

bool CheckFiles(string file1Name, string file2Name)
{
    ifstream file1(file1Name);
    ifstream file2(file2Name);

    char buffer1[256];
    char buffer2[256];

    while (file1.getline(buffer1, 256) && file2.getline(buffer2, 256)) {
        if (strcmp(buffer1, buffer2) != 0) {
            return false;
        }
    }

    if (file1.peek() != EOF && file2.peek() != EOF) {
        return false;
    }

    return true;
}

TEST_CASE("encrypt and decrypt large file")
{
    string testFile = "./test1.txt";
    string outCrypt = "crypted.txt";
    string outDecrypt = "decrypted.txt";
    int key = 120;

    Crypt(testFile, outCrypt, key);
    Decrypt(testFile, outDecrypt, key);

    REQUIRE(CheckFiles(testFile, outDecrypt));
}

TEST_CASE("key is 256")
{
    string testFile = "./test1.txt";
    string outCrypt = "crypted.txt";
    int cryptKey = 256;
    
    REQUIRE_THROWS_AS(Crypt(testFile, outCrypt, cryptKey), invalid_argument);
}

TEST_CASE("key is -1")
{
    string testFile = "./test1.txt";
    string outCrypt = "crypted.txt";
    int cryptKey = -1;

    REQUIRE_THROWS_AS(Crypt(testFile, outCrypt, cryptKey), invalid_argument);
}

TEST_CASE("file not exist")
{
    string testFile = "./test.txt";
    string outCrypt = "crypted.txt";
    int cryptKey = 20;

    REQUIRE_THROWS_AS(Crypt(testFile, outCrypt, cryptKey), runtime_error);
}