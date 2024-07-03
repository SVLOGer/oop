#include "Dictionary.h"

using namespace std;

//сделать тип dictionary
// отформатировать код
//функция должна возвращать словарь функция сложная

bool IsValidInput(string& word)
{
    for (char c : word)
    {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

Dictionary ReadDictionaryFromFile(const string& filename) 
{
    Dictionary dictionary;
    ifstream file(filename);
    if (file.is_open()) {
        //фраза может быть из нескольких слов
        string english, russian;
        bool validInput = true;
        while (file >> english >> russian) {
            if (IsValidInput(english) || IsValidInput(russian))
            {
                cout << "Error: it's not a word" << endl;
                break;
            }

            if (!english.empty() && !russian.empty()) {
                dictionary[english] = russian;
            }
            else {
                cout << "Error: Invalid input in the dictionary file." << endl;
            }
        }
        file.close();
    }
    else {
        cout << "Error: Unable to open file " << filename << endl;
    }

    return dictionary;
}

void WriteDictionaryToFile(const string& filename, Dictionary& dictionary)
{
    ofstream file(filename);
    if (file.is_open()) 
    {
        for (const auto& pair : dictionary) {
            if (!(file << pair.first << " " << pair.second << endl))
            {
                cout << "Error: output error" << endl;
            }
        }
        file.close();
    }

}

void AddNewTranslation(Dictionary& dictionary, string& input)
{
    string translation;
    cout << "Translation not found. Enter translation in Russian: ";
    getline(cin, translation);
    if (!translation.empty()) 
    {
        dictionary[input] = translation;
    }
}

//почему функция изменяет словарь
void SaveDictionary(const string& dictionaryFilename, Dictionary& dictionary)
{
    char choice;
    cout << "Do you want to save changes to the dictionary? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') 
    {
        WriteDictionaryToFile(dictionaryFilename, dictionary);
        cout << "Dictionary saved to file." << endl;
    }
}

void TranslateWordsEnToRu(string& input, Dictionary& dictionary)
{
    if (dictionary.find(input) != dictionary.end()) {
        cout << "Translation: " << dictionary[input] << endl;
    }
    else {
        //можно выделить в отдельную функцию
        AddNewTranslation(dictionary, input);
    }
}

bool FileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

//название функции(глагол)
//зачем передается словарь
void WorkingWithDictionary(const string& dictionaryFilename)
{
    Dictionary dictionary;

    if (FileExists(dictionaryFilename))
    {
        ReadDictionaryFromFile(dictionaryFilename);
    }

    string input;
    while (true) {
        cout << "Enter a word or phrase in English (or '...' to exit): ";
        getline(cin, input);

        if (input == "...") {
            if (!dictionary.empty()) {
                if (FileExists(dictionaryFilename))
                {
                    SaveDictionary(dictionaryFilename, dictionary);
                }
                else
                {
                    string dictionaryFilenameForSave = "dictionary.txt";
                    SaveDictionary(dictionaryFilenameForSave, dictionary);
                }
            }
            break;
        }

        TranslateWordsEnToRu(input, dictionary);
    }
}