#include "reader.hpp"

std::string whitespace(int count)
{
    return std::string(count, ' ');
}

void writeToString(std::string& str, const Any& any, int indent = 0)
{
    switch (any.type().toValue())
    {
        case Type::Array:
        {
            Array* array = any.as<Array>();

            str += fmt::format("Array[\n");

            for(size_t i = 0 ; i < array->size(); i++)
            {
                str += whitespace(indent) + fmt::format("  {} -> ", i);
                writeToString(str, array->at(i), indent + 2);
                str += fmt::format("\n");
            }

            str += whitespace(indent) + fmt::format("]\n");

        } break;
            
        case Type::Bignum:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::Bool:
            str += fmt::format("{}", *any.as<bool>());
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
            str += fmt::format("{}", *any.as<i32>());
            break;

        case Type::Float:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::Hash:
        {
            Hash* hash = any.as<Hash>();

            str += fmt::format("Hash{{\n");

            for (const auto& element : *hash)
            {
                str += whitespace(indent + 2);
                writeToString(str, element.first, 0);
                str += " -> ";

                writeToString(str, element.second, indent + 2);
                str += fmt::format("\n");
            }

            str += whitespace(indent) + fmt::format("}}");
        } break;

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
            str += fmt::format("nil");
            break;

        case Type::Object:
        {
            Object* object = any.as<Object>();

            str += fmt::format("{}(\n", object->className());

            for (const auto& element : *object)
            {
                str += whitespace(indent) + fmt::format("  {} -> ", element.first);
                writeToString(str, element.second, indent + 2);
                str += fmt::format("\n");
            }

            str += whitespace(indent) + fmt::format(")");

        } break;

        case Type::Regexp:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::String:
            str += fmt::format("\"{}\"", *any.as<std::string>());
            break;

        case Type::Struct:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::Symbol:
            str += fmt::format("\"{}\"", *any.as<std::string>());
            break;

        case Type::Symlink:
            str += fmt::format("\"{}\"", *any.as<std::string>());
            break;

        case Type::Uclass:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::Unknown:
            throw std::runtime_error(fmt::format("Unknown type: {}", any.type()));
            break;

        case Type::UserDef:
        {
            Table* table = any.as<Table>();

            str += fmt::format("Table[\n");

            str += whitespace(indent) + fmt::format("  {} -> {}\n", "xLength", table->xLength);
            str += whitespace(indent) + fmt::format("  {} -> {}\n", "yLength", table->yLength);
            str += whitespace(indent) + fmt::format("  {} -> {}\n", "zLength", table->zLength);
            str += whitespace(indent) + fmt::format("  {} -> {}\n", "indices", table->indices);

            for (i32 i = 0; i < table->indices; i++)
            {
                str += whitespace(indent) + fmt::format("  {} -> ", i);
                str += fmt::format("{}", table->data.at(i));
                str += fmt::format("\n");
            }

            str += whitespace(indent) + fmt::format("]\n");

        } break;
           
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

        std::string output;
        writeToString(output, any);

        writeStringToFile(outputFilename, output);
    }
    catch (const std::runtime_error& exception)
    {
        fmt::print("Error: {}", exception.what());
    }

    return 0;
}