#pragma once
//Прочитать про гарантии безопасности исключений какие особенности
//Учитывать разные регистры урлов
//сделать статическими приватные функции - отстутствие, базовый, сильный, гарантия
#ifndef CHTTPURL_H
#define CHTTPURL_H

#include <string>
#include "CUrlParsingError.h"

enum class Protocol
{
    HTTP,
    HTTPS
};

class CHttpUrl
{
public:
    CHttpUrl(const std::string& url);
    CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol = Protocol::HTTP);
    CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol, unsigned long port);

    std::string GetURL() const;
    std::string GetDomain() const;
    std::string GetDocument() const;
    Protocol GetProtocol() const;
    unsigned short GetPort() const;

private:
    std::string m_domain;
    std::string m_document;
    Protocol m_protocol;
    unsigned short m_port;
    static unsigned short GetDefaultPort(Protocol protocol);
    static Protocol ParseProtocol(const std::string& protocol);
    static unsigned short ParsePort(const std::string& port);
    static void ValidateDomain(const std::string& domain);
    static void ValidateDocument(std::string& document);
};

#endif // CHTTPURL_H
