#include "reader.hpp"
#include "items.hpp"
#include "system.hpp"

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
            auto* array = any.as<Array>();

            if (array->empty())
            {
                str += "Array[]";
            }
            else
            {
                str += "Array[\n";

                for (size_t i = 0; i < array->size(); i++)
                {
                    str += whitespace(indent + 2) + fmt::format("'{}' = ", i);
                    writeToString(str, array->at(i), indent + 2);
                    str += "\n";
                }

                str += whitespace(indent) + "]\n";
            }

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
            auto* hash = any.as<Hash>();

            str += "Hash{\n";

            for (const auto& element : *hash)
            {
                str += whitespace(indent + 2) + "'";
                writeToString(str, element.first, 0);
                str += "' -> ";

                writeToString(str, element.second, indent + 2);
                str += "\n";
            }

            str += whitespace(indent) + "}";
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
            auto* object = any.as<Object>();

            str += fmt::format("{}(\n", object->className());

            for (const auto& element : *object)
            {
                str += whitespace(indent + 2) + fmt::format("'{}' = ", element.first);
                writeToString(str, element.second, indent + 2);
                str += "\n";
            }

            str += whitespace(indent) + ")\n";

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
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;
           
        case Type::UserMarshal:
            throw std::runtime_error(fmt::format("Not implemented: {}", any.type()));
            break;

        case Type::Color:
        {
            auto* color = any.as<Color>();

            str += "Color[\n";
            str += whitespace(indent + 2) + fmt::format("'red' = {}\n", color->red);
            str += whitespace(indent + 2) + fmt::format("'green' = {}\n", color->green);
            str += whitespace(indent + 2) + fmt::format("'blue' = {}\n", color->blue);
            str += whitespace(indent + 2) + fmt::format("'alpha' = {}\n", color->alpha);
            str += whitespace(indent) + "]\n";

        } break;

        case Type::Table:
        {
            auto* table = any.as<Table>();

            str += "Table[\n";
            str += whitespace(indent + 2) + fmt::format("'totalSize' = {}\n", table->totalSize);
            str += whitespace(indent + 2) + fmt::format("'xSize' = {}\n", table->xSize);
            str += whitespace(indent + 2) + fmt::format("'ySize' = {}\n", table->ySize);
            str += whitespace(indent + 2) + fmt::format("'zSize' = {}\n", table->zSize);

            for (i32 i = 0; i < table->totalSize; i++)
            {
                str += whitespace(indent + 2) + fmt::format("'{}' = ", i);
                str += fmt::format("{}", table->data.at(i));
                str += "\n";
            }

            str += whitespace(indent) + "]\n";

        } break;

        case Type::Tone:
        {
            auto* tone = any.as<Tone>();

            str += "Tone[\n";
            str += whitespace(indent + 2) + fmt::format("'red' = {}\n", tone->red);
            str += whitespace(indent + 2) + fmt::format("'green' = {}\n", tone->green);
            str += whitespace(indent + 2) + fmt::format("'blue' = {}\n", tone->blue);
            str += whitespace(indent + 2) + fmt::format("'grey' = {}\n", tone->grey);
            str += whitespace(indent) + "]\n";

        } break;

        default:
            throw std::runtime_error(fmt::format("Invalid type: {}", any.type()));
    }
}

int marshalToText(int argc, char** argv)
{
    if (argc != 3)
    {
        fmt::print("Usage: marshal_to_cpp input_filename output_filename\n");
        return 1;
    }

    const std::string inputFilename{ argv[1] };
    const std::string outputFilename{ argv[2] };

    {
        auto bytes = loadFileIntoMemory(inputFilename);

        Reader reader{ bytes };
        auto any = reader.parse();

        std::string output;
        writeToString(output, any);

        writeStringToFile(outputFilename, output);
    }
  
    return 0;
}

int main(int argc, char** argv)
{
    return marshalToText(argc, argv);
}