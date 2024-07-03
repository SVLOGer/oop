#define CATCH_CONFIG_MAIN
#include "../Task5/Fill.h"
#include "../../../catch2/catch.hpp"

TEST_CASE("File matrix")
{
    std::stringstream input(
        """\n"
        " #######""\n"
        " #     #""\n"
        " #  O  #""\n"
        " #     #""\n"
        " ####### ""\n"
        "         ""\n"
    );

    std::ifstream inputFile(input.str());

    auto actual = FillMapTest(inputFile);

    std::stringstream expected(
        """\n"
        " #######""\n"
        " #-----#""\n"
        " #--O--#""\n"
        " #-----#""\n"
        " ####### ""\n"
        "         ""\n"
    );
    
    std::ifstream expectedFile(expected.str());

    std::vector<std::vector<SymbolCode>> expectedMap = ReadMap(expectedFile);

    REQUIRE(actual == expectedMap);
}

TEST_CASE("No figure - no fill")
{
    std::stringstream input(" O ""\n");

    std::ifstream inputFile(input.str());

    auto actual = FillMapTest(inputFile);

    std::stringstream expected(" O ""\n" );

    std::ifstream expectedFile(expected.str());

    std::vector<std::vector<SymbolCode>> expectedMap = ReadMap(expectedFile);

    REQUIRE(actual == expectedMap);
}

TEST_CASE("Non closed figure")
{
    std::stringstream input(
        """\n"
        " #######""\n"
        " #     #""\n"
        "    O  #""\n"
        " #     #""\n"
        " ####### ""\n"
        "         ""\n"
    );

    std::ifstream inputFile(input.str());

    auto actual = FillMapTest(inputFile);

    std::stringstream expected(
        """\n"
        "-#######""\n"
        "-#-----#""\n"
        "----O--#""\n"
        " #-----#""\n"
        " #######-""\n"
        "---------""\n"
    );

    std::ifstream expectedFile(expected.str());

    std::vector<std::vector<SymbolCode>> expectedMap = ReadMap(expectedFile);

    REQUIRE(actual == expectedMap);
}