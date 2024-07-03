#include <sstream>

#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../Task2/HtmlDecode.h"

using namespace std;
// аждый тест провер€ет определенный аспект
SCENARIO("HtmlDecode")
{
    WHEN("INPUT is empty")
    {
        THEN("OUTPUT is empty")
        {
            string html;
            REQUIRE(HtmlDecode(html) == "");
        }
    }
    WHEN("INPUT is &quot;")
    {
        THEN("OUTPUT is \"")
        {
            string html = "&quot;";
            REQUIRE(HtmlDecode(html) == "\"");
        }
    }
    WHEN("INPUT is &lt;")
    {
        THEN("OUTPUT is <")
        {
            string html = "&lt;";
            REQUIRE(HtmlDecode(html) == "<");
        }
    }
    WHEN("INPUT is &gt;")
    {
        THEN("OUTPUT is >")
        {
            string html = "&gt;";
            REQUIRE(HtmlDecode(html) == ">");
        }
    }
    WHEN("INPUT is &amp;")
    {
        THEN("OUTPUT is &")
        {
            string html = "&amp;";
            REQUIRE(HtmlDecode(html) == "&");
        }
    }
    WHEN("INPUT is &apos;")
    {
        THEN("OUTPUT is '")
        {
            string html = "&apos;";
            REQUIRE(HtmlDecode(html) == "'");
        }
    }
    WHEN("INPUT have fake html entity")
    {
        THEN("OUTPUT don't decode fake html entity")
        {
            string html = "& &apos&ltgt&amp;";
            REQUIRE(HtmlDecode(html) == "& &apos&ltgt&");
        }
    }
    WHEN("INPUT is text beetwen html entities")
    {
        THEN("OUTPUT is text beetwen html entities")
        {
            string html = "This is a &quot;test&quot;";
            REQUIRE(HtmlDecode(html) == "This is a \"test\"");
        }
    }
    WHEN("INPUT is some html entities in a row")
    {
        THEN("OUTPUT is decode all html entities on a row")
        {
            string html = "This is &lt;&quot;a&quot;&gt; test";
            REQUIRE(HtmlDecode(html) == "This is <\"a\"> test");
        }
    }
}
