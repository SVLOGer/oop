#include "Radix.h"
#include "Import.h"

using namespace std;

//упростить функцию
int StringToInt(const string& str, int radix, bool& wasError) {
    int result = 0;
    int power = 1;//rename base/radix
    int len = str.length();
    int startIdx = 0;

    bool isNegative = false;
    if (str[0] == '-')
    {
        isNegative = true;
        startIdx = 1;
    }

    for (int i = len - 1; i >= startIdx; --i)
    {
        char c = str[i];
        int digit;

        //выделить в отдельную функцию
        if (isdigit(c))
        {
            digit = c - '0';
        }
        else if (isalpha(c))
        {
            digit = c - 'A' + 10;
        }
        else
        {
            wasError = true;
            return 1;
        }

        if (digit >= radix)
        {
            wasError = true;
            return 1;
        }

        if (result + digit * power >= 0)
        {
            result += digit * power;
        }
        else
        {
            wasError = true;//enum(errorcode)
            return 2;//почему
        }

        power *= radix;
    }

    wasError = false;
    return isNegative ? -result : result;
}

string IntToString(int n, int radix, bool& wasError) {
    string result;

    if (n == 0)//костыль сделать обработку в цикле
    {
        return "0";
    }

    bool isNegative = false;
    if (n < 0)
    {
        isNegative = true;
        n = -n;//убрать, можно для отрицательных вычитать
    }

    while (n > 0)
    {
        int digit = n % radix;
        char c;

        if (digit < 10) {
            c = '0' + digit;
        }
        else {
            c = 'A' + digit - 10;
        }

        result = c + result;

        n /= radix;
    }

    wasError = false;
    if (isNegative)
    {
        result = "-" + result;
    }

    return result;
}

//убрать arg и сделать переменные
//другое имя ConvertNotation
string Radix(const string& arg1, const string& arg2, const string& arg3)
{
    bool wasError = false;

    int sourceRadix = StringToInt(arg1, 10, wasError);
    if (wasError)
    {
        return "Error: Invalid character in string";
    }
    if (sourceRadix < 2 || sourceRadix > 36)
    {
        return "Error: Base should be between 2 and 36\n";
    }

    int destinationRadix = StringToInt(arg2, 10, wasError);
    if (wasError)
    {
        return "Error: Invalid character in string";
    }
    if (destinationRadix < 2 || destinationRadix > 36)
    {
        return "Error: Base should be between 2 and 36\n";
    }

    string value = arg3;
    if (value == "")
    {
        return "Error: Value is empty";
    }

    int decimalValue = StringToInt(value, sourceRadix, wasError);
    if (wasError)
    {
        if (decimalValue == 1)
        {
            return "Error: Incorrect digit for the base of the number system";
        }
        if (decimalValue == 2)
        {
            return "Error: Number is bigger than max number";
        }
    }

    string result = IntToString(decimalValue, destinationRadix, wasError);

    return result;
}