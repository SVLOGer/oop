#pragma once

#ifndef CURLPARSINGERROR_H
#define CURLPARSINGERROR_H

#include <stdexcept>
#include <string>

class CUrlParsingError : public std::invalid_argument
{
public:
    explicit CUrlParsingError(const std::string& message);
};

#endif // CURLPARSINGERROR_H
