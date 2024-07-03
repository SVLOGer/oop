#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../task5/CHttpUrl.h"

TEST_CASE("Valid URL parsing", "[CHttpUrl]") {
    SECTION("HTTP protocol with default port") {
        CHttpUrl url("http://www.example.com");
        REQUIRE(url.GetProtocol() == Protocol::HTTP);
        REQUIRE(url.GetPort() == 80);
        REQUIRE(url.GetDomain() == "www.example.com");
        REQUIRE(url.GetDocument() == "");
    }

    SECTION("HTTPS protocol with default port") {
        CHttpUrl url("https://www.example.com");
        REQUIRE(url.GetProtocol() == Protocol::HTTPS);
        REQUIRE(url.GetPort() == 443);
        REQUIRE(url.GetDomain() == "www.example.com");
        REQUIRE(url.GetDocument() == "");
    }

    SECTION("FTP protocol with default port") {
        CHttpUrl url("ftp://ftp.example.com");
        REQUIRE(url.GetProtocol() == Protocol::FTP);
        REQUIRE(url.GetPort() == 21);
        REQUIRE(url.GetDomain() == "ftp.example.com");
        REQUIRE(url.GetDocument() == "");
    }

    SECTION("URL with specified port") {
        CHttpUrl url("http://www.example.com:8080");
        REQUIRE(url.GetProtocol() == Protocol::HTTP);
        REQUIRE(url.GetPort() == 8080);
        REQUIRE(url.GetDomain() == "www.example.com");
        REQUIRE(url.GetDocument() == "");
    }

    SECTION("URL with document") {
        CHttpUrl url("http://www.example.com/index.html");
        REQUIRE(url.GetProtocol() == Protocol::HTTP);
        REQUIRE(url.GetPort() == 80);
        REQUIRE(url.GetDomain() == "www.example.com");
        REQUIRE(url.GetDocument() == "/index.html");
    }
}

TEST_CASE("Invalid URL parsing", "[CHttpUrl]") {
    SECTION("Invalid protocol") {
        REQUIRE_THROWS_AS(CHttpUrl("htp://www.example.com"), CUrlParsingError);
    }

    SECTION("Invalid port number") {
        REQUIRE_THROWS_AS(CHttpUrl("http://www.example.com:70000"), CUrlParsingError);
    }

    SECTION("Empty host") {
        REQUIRE_THROWS_AS(CHttpUrl("http:///index.html"), CUrlParsingError);
    }
}
