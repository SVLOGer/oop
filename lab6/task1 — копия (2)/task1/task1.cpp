#include "CHttpUrl.h"
#include <iostream>

using namespace std;

int main()
{
    string url;

    while (getline(cin, url))
    {
        try
        {
            CHttpUrl httpUrl(url);
            cout << "URL: " << httpUrl.GetURL() << endl;
            cout << "Domain: " << httpUrl.GetDomain() << endl;
            cout << "Document: " << httpUrl.GetDocument() << endl;
            cout << "Protocol: " << (httpUrl.GetProtocol() == Protocol::HTTP ? "http" : "https") << endl;
            cout << "Port: " << httpUrl.GetPort() << endl;
        }
        catch (const CUrlParsingError& e)
        {
            cout << "Error parsing URL: " << e.what() << endl;
        }
        catch (const invalid_argument& e)
        {
            cout << "Invalid argument: " << e.what() << endl;
        }
    }

    return 0;
}
