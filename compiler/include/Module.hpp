/*
Created by @PieroCastillo on 2025-08-24
*/
#ifndef MODULE_HPP
#define MODULE_HPP

// standard headers
#include <vector>
#include <string>
#include <variant>
#include <stdint.h>

// project headers

namespace Wea::AST
{
    struct Type;
    struct CustomType;

    struct Statement
    {

    };

    struct Function
    {
        std::string identifier;

    };

    struct Field {
        std::string name;
        uint32_t typeIndex; // índice en tabla global de tipos
    };

    enum class TypeKind { Native, Custom };

    struct Type {
        TypeKind kind;
        std::string identifier;

        // si es Custom, apunta a índice en la tabla de CustomTypes
        uint32_t customIndex = UINT32_MAX;

        static Type Native(std::string id) {
            return { TypeKind::Native, std::move(id), UINT32_MAX };
        }
        static Type Custom(std::string id, size_t idx) {
            return { TypeKind::Custom, std::move(id), idx };
        }
    };

    struct CustomType {
        std::string identifier;
        std::vector<Field> fields;
    };

    //  TODO: apply the same pattern with Property
    struct Property
    {
        std::string name;
        // getter
        // setter
    };

    struct Module
    {
        std::string identifier;
        std::vector<Function> funcsTable;
        std::vector<Type> typesTable;
        std::vector<CustomType> typesTable;
    };
};

#endif // MODULE_HPP