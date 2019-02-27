#include "reader.hpp"

void print(const Value& value)
{
    switch (value.getType())
    {
        case Value::Type::Nil:
            std::cout << "nil";
            break;

        case Value::Type::Bool:
            std::cout << (*static_cast<bool*>(value.getValue()) ? "true" : "false");
            break;

        case Value::Type::Fixnum:
            std::cout << *(static_cast<int*>(value.getValue()));
            break;

        case Value::Type::String:
        case Value::Type::Symbol:
        case Value::Type::Symlink:
            std::cout << '"' << *(static_cast<std::string*>(value.getValue())) << '"';
            break;

        case Value::Type::Array:
        {
            auto* values = static_cast<std::vector<Value>*>(value.getValue());

            std::cout << '[';

            for (size_t i = 0; i < values->size(); i++)
            {
                print(values->at(i));

                if (i != values->size() - 1)
                    std::cout << ' ';
            }

            std::cout << "]";

        } break;

        case Value::Type::Object:
        case Value::Type::Hash:
        {
            auto* object = static_cast<std::map<Value, Value>*>(value.getValue());
            std::cout << "{\n";
            for (const auto& pair : *object)
            {
                print(pair.first);
                std::cout << " -> ";
                print(pair.second);
                std::cout << '\n';
            }
            std::cout << "}\n";
        } break;

        case Value::Type::UserDef:
        {
            std::cout << "userdef(" << static_cast<Table*>(value.getValue())->indices << ")";
        } break;

        default:
            std::cout << "Unknown";
            break;
    }
}

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

}

int main()
{
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
            else if (command.rfind("cd", 0) == 0)
                handleCdCommand(command, pointer);
            else
                std::cout << "'" << command << "' is not recognized as an command." << '\n';

        }
    }
}