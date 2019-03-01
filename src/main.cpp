#include "reader.hpp"

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

int main()
{
    Reader reader{ loadFileIntoMemory(SystemPath) };
    auto any = reader.parse();
    print(any);

    /*
    MarshalReader reader{ loadFileIntoMemory(TroopsPath) };
    auto value = reader.parse();
    auto* pointer = &value;

    std::cout << "Marshal To Cpp Explorer [Version 0.1]" << '\n';
    std::cout << "(c) 2019 Heaven31415. All rights reserved." << '\n';

    while (true)
    {
        std::string command;
        std::cout << "\n(" << pointer->getType() << ")" << ">";
        std::getline(std::cin, command);

        if (command == "q" || command == "quit" || command == "exit") break;
        else
        {
            if (command == "cls")
                system("cls");
            else if (command == "size")
                handleSizeCommand(pointer);
            else if (command == "ls")
                handleLsCommand(pointer);
            else if (startsWith(command, "cd"))
                handleCdCommand(command, pointer);
            else
                std::cout << "'" << command << "' is not recognized as an command." << '\n';

        }
    }

    */
}

/*

#include "explorer.hpp"

void handleSizeCommand(Value* pointer)
{
    switch (pointer->getType())
    {
        case Value::Type::String:
        case Value::Type::Symbol:
        case Value::Type::Symlink:
            std::cout << static_cast<std::string*>(pointer->getValue())->size() << '\n';
            break;
        case Value::Type::Array:
            std::cout << static_cast<std::vector<Value>*>(pointer->getValue())->size() << '\n';
            break;
        case Value::Type::Hash:
        case Value::Type::Object:
            std::cout << static_cast<std::map<Value, Value>*>(pointer->getValue())->size() << '\n';
            break;
        default:
            std::cout << "Invalid command for type: " << pointer->getType() << "." << '\n';
    }
}

void handleLsCommand(Value* pointer)
{
    switch (pointer->getType())
    {
        case Value::Type::Nil:
            std::cout << "nil" << '\n';
            break;

        case Value::Type::Bool:
            std::cout << std::boolalpha << *static_cast<bool*>(pointer->getValue()) << std::noboolalpha << '\n';
            break;

        case Value::Type::Fixnum:
            std::cout << *static_cast<int*>(pointer->getValue()) << '\n';
            break;

        case Value::Type::Float:
            std::cout << "NYI" << '\n';
            break;

        case Value::Type::String:
        case Value::Type::Symbol:
        case Value::Type::Symlink:
            std::cout << *static_cast<std::string*>(pointer->getValue()) << '\n';
            break;

        case Value::Type::Array:
        {
            auto* array = static_cast<std::vector<Value>*>(pointer->getValue());

            std::cout << '[';
            for (size_t i = 0; i < array->size(); i++)
            {
                std::cout << i << "=" << array->at(i).getType();
                if (i != array->size() - 1) std::cout << ' ';
            }
            std::cout << ']' << '\n';

            break;
        }

        case Value::Type::Hash:
        case Value::Type::Object:
            std::cout << static_cast<std::map<Value, Value>*>(pointer->getValue())->size() << '\n';
            break;
        default:
            std::cout << "Invalid command for type: " << pointer->getType() << "." << '\n';
    }
}

void handleCdCommand(const std::string& command, Value* pointer)
{
    auto elements = split(command, ' ');

    try
    {
        switch (pointer->getType())
        {
            case Value::Type::Nil:
            case Value::Type::Bool:
            case Value::Type::Fixnum:
            case Value::Type::Float:
            case Value::Type::String:
            case Value::Type::Symbol:
            case Value::Type::Symlink:
                throw std::runtime_error("Invalid current type");
        }

        if (elements.size() != 2)
            throw std::runtime_error("Invalid command syntax");


    }
    catch (const std::runtime_error& ex)
    {
        std::cout << ex.what() << '\n';
    }
    catch (const std::invalid_argument& ex)
    {
        std::cout << ex.what() << '\n';
    }
    catch (const std::out_of_range& ex)
    {
        std::cout << ex.what() << '\n';
    }
}

*/