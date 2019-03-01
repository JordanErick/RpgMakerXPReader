#include "reader.hpp"

#include <iostream>

void print(const Any& any)
{
    switch (any.type().toValue())
    {
        case Type::Nil:
            std::cout << "nil";
            break;

        case Type::Bool:
            std::cout << (*any.as<bool>() ? "true" : "false");
            break;

        case Type::Fixnum:
            std::cout << *any.as<i32>();
            break;

        case Type::String:
        case Type::Symbol:
        case Type::Symlink:
            std::cout << '"' << *any.as<std::string>() << '"';
            break;

        case Type::Array:
        {
            auto* array = any.as<Array>();

            std::cout << '[';

            for (size_t i = 0; i < array->size(); i++)
            {
                print(array->at(i));

                if (i != array->size() - 1)
                    std::cout << ' ';
            }

            std::cout << "]";

        } break;

    case Type::Object:
    {
        auto* object = any.as<Object>();

        std::cout << "{\n";

        for (const auto& pair : *object)
        {
            std::cout << pair.first;
            std::cout << " -> ";
            print(pair.second);
            std::cout << "\n";
        }
        std::cout << "}\n";
    } break;

    case Type::Hash:
    {
        auto* hash = any.as<Hash>();

        std::cout << "{\n";

        for (const auto& pair : *hash)
        {
            print(pair.first);
            std::cout << " -> ";
            print(pair.second);
            std::cout << "\n";
        }
        std::cout << "}\n";

    } break;

    case Type::UserDef:
        std::cout << "userdef(" << any.as<Table>()->indices << ")";
        break;

    default:
        std::cout << "Unknown";
        break;
    }
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        fmt::print("Usage: marshal_to_cpp filename\n");
        return 1;
    }

    Reader reader{ loadFileIntoMemory(argv[1]) };
    Any any = reader.parse();
    print(any);
}