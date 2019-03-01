#include "reader.hpp"

void writeToString(std::string& str, const Any& any)
{
    switch (any.type().toValue())
    {
        case Type::Array:
            break;

        case Type::Bignum:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::Bool:
            break;

        case Type::Class:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::Data:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::Extended:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::Fixnum:
            break;

        case Type::Float:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::Hash:
            break;

        case Type::HashDef:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::Ivar:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::Link:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::Module:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::ModuleOld:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::Nil:
            break;

        case Type::Object:
            break;

        case Type::Regexp:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::String:
            break;

        case Type::Struct:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::Symbol:
            break;

        case Type::Symlink:
            break;

        case Type::Uclass:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::Unknown:
            throw std::runtime_error(fmt::format("Unknown type: {}", any.type()));
            break;

        case Type::UserDef:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::UserMarshal:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        default:
            throw std::runtime_error(fmt::format("Invalid type: {}", any.type()));
    }
}

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        fmt::print("Usage: marshal_to_cpp input_filename output_filename\n");
        return 1;
    }

    const std::string inputFilename{ argv[1] };
    const std::string outputFilename{ argv[2] };

    try 
    {
        auto bytes = loadFileIntoMemory(inputFilename);

        Reader reader{ bytes };
        Any any = reader.parse();

        std::string output = "hi";
        writeToString(output, any);

        writeStringToFile(outputFilename, output);
    }
    catch (const std::runtime_error& exception)
    {
        fmt::print("Error: {}", exception.what());
        return 1;
    }

    return 0;
}