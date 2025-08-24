// standard
#include <string>
#include <array>
#include <string_view>
#include <utility>

// project headers
#include "Lexer.hpp"

using namespace Wea;

auto Lexer::splitString(std::string& str) -> std::vector<std::string>
{
    const auto length = str.length();
    std::vector<std::string> tokenLitList;
    tokenLitList.reserve(0.25 * length);

    int32_t idx = 0;
    std::string tokenLit;
    bool onString = false;

    while (idx <= length)
    {
        char chr = str[idx];

        if (onString)
        {
            // TODO: implement on string values ( "something" )
            continue;
        }

        if (idx == length || (chr == ' ') || (chr == '\n'))
        {
            if (!tokenLit.empty())
            {
                tokenLitList.push_back(std::move(tokenLit));
                tokenLit = "";
            }

            ++idx;
            continue;
        }
        tokenLit += chr;
        ++idx;
    }

    tokenLitList.shrink_to_fit();
    return tokenLitList;
}

constexpr uint32_t fnv1a(std::string_view str) {
    uint32_t h = 2166136261u;
    for (char c : str) h = (h ^ c) * 16777619u;
    return h;
}

constexpr TokenType toEnum(std::string_view key)
{
    switch (fnv1a(key))
    {
    case fnv1a("let"): return TokenType::Let;
    case fnv1a("global"): return TokenType::Global;
    case fnv1a("shared"): return TokenType::Shared;
    case fnv1a("local"): return TokenType::Local;
    case fnv1a("view"): return TokenType::View;
    case fnv1a("mut"): return TokenType::Mut;
    case fnv1a("ref"): return TokenType::Ref;
    case fnv1a("Type"): return TokenType::Type;
    case fnv1a("Proc"): return TokenType::Proc;
    case fnv1a("Pack"): return TokenType::Pack;
    case fnv1a("Record"): return TokenType::Record;
    case fnv1a("if"): return TokenType::If;
    case fnv1a("while"): return TokenType::While;
    case fnv1a("loop"): return TokenType::Loop;
    case fnv1a("sizeof"): return TokenType::SizeOf;
    case fnv1a("+"): return TokenType::Cross;
    case fnv1a("++"): return TokenType::CrossCross;
    case fnv1a("-"): return TokenType::Dash;
    case fnv1a("--"): return TokenType::DashDash;
    case fnv1a("*"): return TokenType::Asterisk;
    case fnv1a("?"): return TokenType::Question;
    case fnv1a("#"): return TokenType::Hash;
    case fnv1a("$"): return TokenType::Dolar;
    case fnv1a("@"): return TokenType::At;
    case fnv1a("->"): return TokenType::Arrow;
    case fnv1a("-->"): return TokenType::LargeArrow;
    case fnv1a(","): return TokenType::Comma;
    case fnv1a(";"): return TokenType::Semicolon;
    case fnv1a(":"): return TokenType::Colon;
    case fnv1a("="): return TokenType::Equal;
    case fnv1a("*="): return TokenType::AsteriskEqual;
    case fnv1a("+="): return TokenType::CrossEqual;
    case fnv1a("-="): return TokenType::DashEqual;
    case fnv1a("<"): return TokenType::LessThan;
    case fnv1a(">"): return TokenType::GreaterThan;
    case fnv1a("<="): return TokenType::LessEqualThan;
    case fnv1a(">="): return TokenType::GreaterEqualThan;
    case fnv1a("("): return TokenType::LeftParenthesis;
    case fnv1a(")"): return TokenType::RightParenthesis;
    case fnv1a("{"): return TokenType::LeftCurlyBracket;
    case fnv1a("}"): return TokenType::RightCurlyBracket;
    case fnv1a("["): return TokenType::LeftSquareBracket;
    case fnv1a("]"): return TokenType::RightSquareBracket;
    default: return TokenType::Unknown;
    }
}

auto Lexer::getTokens(const std::vector<std::string>& tokenLitList) -> std::vector<Token>
{
    const auto length = tokenLitList.size();
    std::vector<Token> tokenList;
    tokenList.resize(length);

    for (const std::string& tokenLit : tokenLitList)
    {
        auto tokenType = toEnum(tokenLit);
        // TODO: manage other cases
    }

    return tokenList;
}

auto Lexer::Parse(std::string& text) -> std::vector<Token>
{
    auto txt = std::move(text);

    std::vector<Token> tokens;
    tokens.reserve(0.25 * text.size()); // approximate token count

    auto tokenLitList = splitString(txt);

    return tokens;
}