#include "CHttpUrl.h"
#include <regex>
#include <algorithm>
#include <stdexcept>

CUrlParsingError::CUrlParsingError(const std::string& message)
    : std::runtime_error(message) {}

CHttpUrl::CHttpUrl(const std::string& url) {
    if (!ParseURL(url, m_protocol, m_port, m_host, m_document)) {
        throw CUrlParsingError("Invalid URL format");
    }
}

std::string CHttpUrl::GetURL() const {
    return m_url;
}

std::string CHttpUrl::GetDomain() const {
    return m_host;
}

std::string CHttpUrl::GetDocument() const {
    return m_document;
}

Protocol CHttpUrl::GetProtocol() const {
    return m_protocol;
}

unsigned short CHttpUrl::GetPort() const {
    return m_port;
}

bool CHttpUrl::ParseURL(const std::string& url, Protocol& protocol, unsigned short& port, std::string& host, std::string& document) {
    std::regex urlRegex(R"(^(http|https|ftp):\/\/([^\/:]+)(?::(\d+))?(\/.*)?$)", std::regex::icase);
    std::smatch urlMatchResult;

    if (std::regex_match(url, urlMatchResult, urlRegex)) {
        std::string protocolStr = urlMatchResult[1].str();
        std::transform(protocolStr.begin(), protocolStr.end(), protocolStr.begin(), ::tolower);

        if (protocolStr == "http") {
            protocol = Protocol::HTTP;
            port = 80;
        }
        else if (protocolStr == "https") {
            protocol = Protocol::HTTPS;
            port = 443;
        }
        else if (protocolStr == "ftp") {
            protocol = Protocol::FTP;
            port = 21;
        }
        else {
            return false;
        }

        host = urlMatchResult[2].str();

        if (urlMatchResult[3].matched) {
            int portValue = std::stoi(urlMatchResult[3].str());
            if (portValue < 1 || portValue > 65535) {
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
