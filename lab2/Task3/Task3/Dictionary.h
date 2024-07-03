#pragma once

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <fstream>

using Dictionary = std::unordered_map<string, string>;

void TranslateEnToRu(const std::string& dictionaryFilename, Dictionary& dictionary);