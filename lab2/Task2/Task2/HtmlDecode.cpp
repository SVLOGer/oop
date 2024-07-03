#include "HtmlDecode.h"

using namespace std;
// сделать глобальной константой
//сделать поиск по строковый значений
// не использовать [] использовать find

const pair<string, char> htmlEntities[] = {
       {"&quot;", '"'},
       {"&apos;", '\''},
       {"&lt;", '<'},
       {"&gt;", '>'},
       {"&amp;", '&'},
};

string HtmlDecode(const string& html)
{
    string result;
    result.reserve(html.size());

    for (size_t i = 0; i < html.size(); ++i)
    {
        if (html[i] == '&')
        {
            bool foundEntity = false;
            for (const auto& entity : htmlEntities)
            {
                if (html.substr(i, entity.first.size()) == entity.first)
                {
                    result += entity.second;
                    i += entity.first.size() - 1;
                    foundEntity = true;
                    break;
                }
            }
            if (!foundEntity)
            {
                result += html[i];
            }
        }
        else
        {
            result += html[i];
        }
    }

    return result;
}
