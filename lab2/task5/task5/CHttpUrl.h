#ifndef CHTTPURL_H
#define CHTTPURL_H

#include <string>
#include <stdexcept>

enum class Protocol {
    HTTP,
    HTTPS,
    FTP
};

class CUrlParsingError : public std::runtime_error {
public:
    explicit CUrlParsingError(const std::string& message);
};

class CHttpUrl {
public:
    CHttpUrl(const std::string& url);

    std::string GetURL() const;
    std::string GetDomain() const;
    std::string GetDocument() const;
    Protocol GetProtocol() const;
    unsigned short GetPort() const;

private:
    bool ParseURL(const std::string& url, Protocol& protocol, unsigned short& port, std::string& host, std::string& document);

    std::string m_url;
    Protocol m_protocol;
    unsigned short m_port;
    std::string m_host;
    std::string m_document;
};

#endif // CHTTPURL_H
