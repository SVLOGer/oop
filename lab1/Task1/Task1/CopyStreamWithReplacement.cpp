#include "Import.h"
#include "CopyStreamWithReplacement.h"

using namespace std;

string ReplaceString(const string& subject, const string& searchString, const string& replacementString)
{
	size_t pos = 0;
	string result;
	if (searchString.empty())
	{
		return subject;
	}
	while (pos < subject.length())
	{
		size_t foundPos = subject.find(searchString, pos);
		result.append(subject, pos, foundPos - pos);
		if (foundPos != string::npos)
		{
			result.append(replacementString);
			pos = foundPos + searchString.length();
		}
		else
		{
			break;
		}
	}
	return result;
}

void CopyStreamWithReplacement(istream& input, ostream& output, const string& searchString, const string& replacementString)
{
	string line;

	while (getline(input, line))
	{
		if (!(output << ReplaceString(line, searchString, replacementString) << "\n"))
		{
			cerr << "Error writing to outputFile" << endl;
			return;
		}
	}
	if (!input.eof())
	{
		cerr << "Error reading inputFile" << endl;
		return;
	}
}