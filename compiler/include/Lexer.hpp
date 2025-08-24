/*
Created by @PieroCastillo on 2025-08-21
*/
#ifndef LEXER_HPP
#define LEXER_HPP

// standard headers
#include <vector>
#include <string>

// project headers
#include "Token.hpp"

namespace Wea
{
    class Lexer
    {
    private:
        inline auto splitString(std::string& str) -> std::vector<std::string>;
        inline auto getTokens(const std::vector<std::string>& tokenLitList) -> std::vector<Token>;
    public:
        auto Parse(std::string& str) -> std::vector<Token>;
    };
};

#endif // LEXER_HPP