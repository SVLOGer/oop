#include "CHttpUrl.h"
#include <regex>
#include <algorithm>
#include <stdexcept>
//Если слишком большой порт - то вывести сообщение оь ошибки, а не падать
using namespace std;

namespace
{
    regex urlRegex(R"(^(http|https|ftp):\/\/([^\/:]+)(?::(\d+))?(\/.*)?$)", regex::icase);

    string ToLower(const string& str)
    {
        string newStr = str;
        transform(newStr.begin(), newStr.end(), newStr.begin(), ::tolower);
        return newStr;
    }
}

CUrlParsingError::CUrlParsingError(const string& message)
    : runtime_error(message) 
{
}

CHttpUrl::CHttpUrl(const string& url) 
{
    if (!ParseURL(url, m_protocol, m_port, m_host, m_document)) 
    {
        throw CUrlParsingError("Invalid URL format");
    }
}

string CHttpUrl::GetURL() const 
{
    return m_url;
}

string CHttpUrl::GetDomain() const 
{
    return m_host;
}

string CHttpUrl::GetDocument() const 
{
    return m_document;
}

Protocol CHttpUrl::GetProtocol() const 
{
    return m_protocol;
}

unsigned short CHttpUrl::GetPort() const 
{
    return m_port;
}

bool CHttpUrl::ParseURL(const string& url, Protocol& protocol, unsigned short& port, string& host, string& document) 
{
    smatch urlMatchResult;

    if (regex_match(url, urlMatchResult, urlRegex)) 
    {
        string protocolStr = ToLower(urlMatchResult[1].str());

        if (protocolStr == "http") 
        {
            protocol = Protocol::HTTP;
            port = 80;
        }
        else if (protocolStr == "https") 
        {
            protocol = Protocol::HTTPS;
            port = 443;
        }
        else if (protocolStr == "ftp") 
        {
            protocol = Protocol::FTP;
            port = 21;
        }
        else 
        {
            return false;
        }

        host = urlMatchResult[2].str();

        if (urlMatchResult[3].matched) 
        {
            int portValue = stoi(urlMatchResult[3].str());
            if (portValue < 1 || portValue >= 65535) 
            {
                return false;
            }
            port = static_cast<unsigned short>(portValue);
        }

        document = urlMatchResult[4].matched ? urlMatchResult[4].str() : "";
        m_url = url;
        return true;
    }

    return false;
}
