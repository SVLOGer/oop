#pragma once

#include <format>
#include <fstream>
#include <iostream>
#include <queue>
#include <thread>
#include <vector>
#include <string>
#include <stack>

enum class SymbolCode
{
	EMPTY_CELL = 0,
	POINT = 1,
	WALL = 2,
	FILL = 3
};

void FillMap(const std::string& inputFileName, const std::string& outputFileName);
std::vector<std::vector<SymbolCode>> FillMapTest(std::ifstream& input);
std::vector<std::vector<SymbolCode>> ReadMap(std::ifstream& inputFile);