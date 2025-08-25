/*
Created by @PieroCastillo on 2025-08-21
*/
#ifndef TOKEN_HPP
#define TOKEN_HPP

// standard headers
#include <vector>
#include <variant>
#include <string>

namespace Wea
{
    enum TokenType
    {
        Unknown,

        Identifier,
        Literal,
        // variable related keywords
        Let,
        Global,
        Shared,
        Local,
        View,
        Mut,
        Ref,

        Type,
        Proc,
        Pack,
        Record,

        // statement related keywords
        If,
        While,
        Loop,

        SizeOf,

        // symbols
        Cross,              // +
        CrossCross,         // ++
        Dash,               // -
        DashDash,           // --
        Asterisk,           // *
        Question,           // ?
        Hash,               // #
        Dolar,              // $
        At,                 // @
        Arrow,              // ->
        LargeArrow,         // -->
        Comma,              // ,
        Semicolon,          // ;
        Colon,              // :
        Equal,              // =
        AsteriskEqual,      // *=
        CrossEqual,         // +=
        DashEqual,          // -=
        LessThan,           // <
        GreaterThan,        // >
        LessEqualThan,      // <=
        GreaterEqualThan,   // >=
        LeftParenthesis,    // (
        RightParenthesis,   // )
        LeftCurlyBracket,   // {
        RightCurlyBracket,  // }
        LeftSquareBracket,  // [
        RightSquareBracket, // ]
    };

    using TokenData = std::variant<std::monostate, std::string>;

    struct Token
    {
        TokenType type;
        TokenData data;
    };
};

#endif // TOKEN_HPP