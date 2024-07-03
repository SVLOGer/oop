#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../task1/CHttpUrl.h"
#include "../task1/CUrlParsingError.h"

TEST_CASE("CHttpUrl valid URL")
{
    CHttpUrl url("http://example.com/index.html");
    REQUIRE(url.GetDomain() == "example.com");
    REQUIRE(url.GetDocument() == "/index.html");
    REQUIRE(url.GetProtocol() == Protocol::HTTP);
    REQUIRE(url.GetPort() == 80);
    REQUIRE(url.GetURL() == "http://example.com/index.html");
}

TEST_CASE("CHttpUrl invalid URL")
{
    REQUIRE_THROWS_AS(CHttpUrl("htp://example.com"), CUrlParsingError);
}

TEST_CASE("CHttpUrl valid HTTPS URL with port")
{
    CHttpUrl url("https://example.com:8443/index.html");
    REQUIRE(url.GetDomain() == "example.com");
    REQUIRE(url.GetDocument() == "/index.html");
    REQUIRE(url.GetProtocol() == Protocol::HTTPS);
    REQUIRE(url.GetPort() == 8443);
    REQUIRE(url.GetURL() == "https://example.com:8443/index.html");
}

TEST_CASE("CHttpUrl construct with domain, document, and protocol")
{
    CHttpUrl url("example.com", "index.html", Protocol::HTTP);
    REQUIRE(url.GetDomain() == "example.com");
    REQUIRE(url.GetDocument() == "/index.html");
    REQUIRE(url.GetProtocol() == Protocol::HTTP);
    REQUIRE(url.GetPort() == 80);
    REQUIRE(url.GetURL() == "http://example.com/index.html");
}

TEST_CASE("CHttpUrl construct with domain, document, protocol, and port")
{
    CHttpUrl url("example.com", "index.html", Protocol::HTTPS, 443);
    REQUIRE(url.GetDomain() == "example.com");
    REQUIRE(url.GetDocument() == "/index.html");
    REQUIRE(url.GetProtocol() == Protocol::HTTPS);
    REQUIRE(url.GetPort() == 443);
    REQUIRE(url.GetURL() == "https://example.com/index.html");
}

TEST_CASE("CHttpUrl invalid port")
{
    REQUIRE_THROWS_AS(CHttpUrl("example.com", "index.html", Protocol::HTTP, 70000), std::invalid_argument);
}

TEST_CASE("URL with uppercase")
{
    CHttpUrl url("HTTP://example.com/index.html");
    REQUIRE(url.GetDomain() == "example.com");
    REQUIRE(url.GetDocument() == "/index.html");
    REQUIRE(url.GetProtocol() == Protocol::HTTP);
    REQUIRE(url.GetPort() == 80);
    REQUIRE(url.GetURL() == "http://example.com/index.html");
}