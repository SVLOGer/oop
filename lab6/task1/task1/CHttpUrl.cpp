#include "CHttpUrl.h"
#include <regex>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <iostream>

using namespace std;

namespace
{
    const unsigned short DEFAULT_HTTP_PORT = 80;
    const unsigned short DEFAULT_HTTPS_PORT = 443;

    const regex URL_REGEX(R"(^(http|https|HTTP|HTTPS):\/\/([^\/:]+)(?::(\d+))?(\/.*)?$)");

    string ToLower(const string& str)
    {
        string newStr = str;
        transform(newStr.begin(), newStr.end(), newStr.begin(), ::tolower);
        return newStr;
    }
}

CHttpUrl::CHttpUrl(const string& url)
{
    smatch match;
    if (!regex_match(url, match, URL_REGEX))
    {
        throw CUrlParsingError("Invalid URL format");
    }

    m_protocol = ParseProtocol(match[1].str());
    m_domain = match[2].str();
    ValidateDomain(m_domain);

    if (match[3].matched)
    {
        m_port = ParsePort(match[3].str());
    }
    else
    {
        m_port = GetDefaultPort(m_protocol);
    }

    m_document = match[4].matched ? match[4].str() : "/";
    ValidateDocument(m_document);
}

CHttpUrl::CHttpUrl(const string& domain, const string& document, Protocol protocol)
    : CHttpUrl(domain, document, protocol, GetDefaultPort(protocol))
{
}

CHttpUrl::CHttpUrl(const string& domain, const string& document, Protocol protocol, unsigned long port)
    : m_domain(domain), m_document(document), m_protocol(protocol), m_port(port)
{
    ValidateDomain(m_domain);
    ValidateDocument(m_document);
    if (port < 1 || port > 65535)
    {
        throw CUrlParsingError("Invalid port number");
    }
}

string CHttpUrl::GetURL() const
{
    ostringstream url;
    url << (m_protocol == Protocol::HTTP ? "http" : "https") << "://";
    url << m_domain;

    if (m_port != GetDefaultPort(m_protocol))
    {
        url << ":" << m_port;
    }

    url << m_document;
    return url.str();
}

string CHttpUrl::GetDomain() const
{
    return m_domain;
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

unsigned short CHttpUrl::GetDefaultPort(Protocol protocol)
{
    return protocol == Protocol::HTTP ? DEFAULT_HTTP_PORT : DEFAULT_HTTPS_PORT;
}

Protocol CHttpUrl::ParseProtocol(const string& protocol)
{
    string lowerProtocol = ToLower(protocol);

    if (lowerProtocol == "http")
    {
        return Protocol::HTTP;
    }
    else if (lowerProtocol == "https")
    {
        return Protocol::HTTPS;
    }
    else
    {
        throw CUrlParsingError("Invalid protocol");
    }
}

unsigned short CHttpUrl::ParsePort(const string& port)
{
    unsigned long portNumber;
    try
    {
        portNumber = stoul(port);
        cout << portNumber << endl;
    }
    catch (const exception&)
    {
        throw CUrlParsingError("Invalid port number");
    }
    if (portNumber <= 1 || portNumber > 65535)
    {
        throw out_of_range("Port number out of range");
    }
    return static_cast<unsigned short>(portNumber);
}

void CHttpUrl::ValidateDomain(const string& domain)
{
    if (domain.empty())
    {
        throw CUrlParsingError("Domain name cannot be empty");
    }
}

void CHttpUrl::ValidateDocument(string& document)
{
    if (document.empty() || document[0] != '/')
    {
        document = "/" + document;
    }
}
