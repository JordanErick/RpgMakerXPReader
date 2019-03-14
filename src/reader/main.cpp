#include <reader/reader.hpp>
#include <reader/types/types.hpp>

#include <chrono>
#include <experimental/filesystem>
#include "fmt/ostream.h"

namespace fs = std::experimental::filesystem;

std::string whitespace(int count)
{
    return std::string(count, ' ');
}

void writeToString(std::string& str, const Any& any, int indent = 0)
{
    switch (any.type())
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
            
        case Type::Bool:
            str += fmt::format("{}", *any.as<bool>());
            break;

        case Type::Int:
            str += fmt::format("{}", *any.as<i32>());
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

        case Type::Null:
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

        case Type::String:
            str += fmt::format("\"{}\"", *any.as<std::string>());
            break;

        case Type::Color:
        {
            auto* color = any.as<Color>();

            str += "Color[\n";
            str += whitespace(indent + 2) + fmt::format("'red' = {}\n", color->red());
            str += whitespace(indent + 2) + fmt::format("'green' = {}\n", color->green());
            str += whitespace(indent + 2) + fmt::format("'blue' = {}\n", color->blue());
            str += whitespace(indent + 2) + fmt::format("'alpha' = {}\n", color->alpha());
            str += whitespace(indent) + "]\n";

        } break;

        case Type::Table:
        {
            auto* table = any.as<Table>();

            str += "Table[\n";
            str += whitespace(indent + 2) + fmt::format("'totalSize' = {}\n", table->totalSize());
            str += whitespace(indent + 2) + fmt::format("'xSize' = {}\n", table->xSize());
            str += whitespace(indent + 2) + fmt::format("'ySize' = {}\n", table->ySize());
            str += whitespace(indent + 2) + fmt::format("'zSize' = {}\n", table->zSize());

            for (i32 i = 0; i < table->totalSize(); i++)
            {
                str += whitespace(indent + 2) + fmt::format("'{}' = ", i);
                str += fmt::format("{}", table->data().at(i));
                str += "\n";
            }

            str += whitespace(indent) + "]\n";

        } break;

        case Type::Tone:
        {
            auto* tone = any.as<Tone>();

            str += "Tone[\n";
            str += whitespace(indent + 2) + fmt::format("'red' = {}\n", tone->red());
            str += whitespace(indent + 2) + fmt::format("'green' = {}\n", tone->green());
            str += whitespace(indent + 2) + fmt::format("'blue' = {}\n", tone->blue());
            str += whitespace(indent + 2) + fmt::format("'grey' = {}\n", tone->grey());
            str += whitespace(indent) + "]\n";

        } break;

        default:
            throw std::runtime_error(fmt::format("Invalid type: {}", any.type()));
    }
}

void rxdataToJSON(const fs::path& inputDir, const fs::path& outputDir)
{
    fmt::print("Converting rxdata to json...\n\n");

    for (const auto& entry : fs::directory_iterator(inputDir))
    {
        if (entry.path().extension() == ".rxdata")
        {
            auto start = std::chrono::system_clock::now();

            auto bytes = loadFileIntoMemory(entry.path().string());
            Reader reader{ bytes };

            auto any = reader.parse();
            auto type = entry.path().stem();
            json j;

            if (type == "Actors")
                ;
            else if (type == "Animations")
                ;
            else if (type == "Armors")
            {
                j = Armors{ *any.as<Array>() };
            }
            else if (type == "Classes")
                ;
            else if (type == "CommonEvents")
                ;
            else if (type == "Enemies")
                ;
            else if (type == "Items")
            {
                j = Items{ *any.as<Array>() };
            }
            else if (type == "MapInfos")
            {
                j = MapInfos{ *any.as<Hash>() };
            }
            else if (type.string().rfind("Map") == 0)
            {
                j = Map{ *any.as<Object>() };
            }
            else if (type == "Scripts")
                ;
            else if (type == "Skills")
                ;
            else if (type == "States")
            {
                j = States{ *any.as<Array>() };
            }
            else if (type == "System")
            {
                j = System{ *any.as<Object>() };
            }
            else if (type == "Tilesets")
                ;
            else if (type == "Troops")
                ;
            else if (type == "Weapons")
            {
                j = Weapons{ *any.as<Array>() };
            }

            fs::path outputPath = outputDir;
            outputPath /= entry.path().filename();
            outputPath.replace_extension("json");
            writeStringToFile(outputPath.string(), j.dump(4));

            auto end = std::chrono::system_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            fmt::print("'{}' took {}ms\n", entry.path().filename(), elapsed.count());
        }
    }

    fmt::print("\n");
}

void rxdataToTxt(const fs::path& inputDir, const fs::path& outputDir)
{
    fmt::print("Converting rxdata to txt...\n\n");

    for (const auto& entry : fs::directory_iterator(inputDir))
    {
        if (entry.path().extension() == ".rxdata")
        {
            auto start = std::chrono::system_clock::now();

            auto bytes = loadFileIntoMemory(entry.path().string());
            Reader reader{ bytes };

            auto any = reader.parse();
            auto type = entry.path().stem();

            std::string output;
            writeToString(output, any);
            
            fs::path outputPath = outputDir;
            outputPath /= entry.path().filename();
            outputPath.replace_extension("txt");
            writeStringToFile(outputPath.string(), output);

            auto end = std::chrono::system_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            fmt::print("'{}' took {}ms\n", entry.path().filename(), elapsed.count());
        }
    }

    fmt::print("\n");
}

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        fmt::print("Usage: rmxp_reader input_dir output_dir json|txt\n");
        return EXIT_FAILURE;
    }

    const fs::path inputDir{ argv[1] };
    const fs::path outputDir{ argv[2] };
    const std::string format = argv[3];

    if (!fs::is_directory(inputDir))
    {
        fmt::print("'{}' is not a directory!\n", inputDir);
        return EXIT_FAILURE;
    }

    if (!fs::is_directory(outputDir))
    {
        fmt::print("'{}' is not a directory!\n", outputDir);
        return EXIT_FAILURE;
    }

    if (format == "json")
        rxdataToJSON(inputDir, outputDir);
    else if (format == "txt")
        rxdataToTxt(inputDir, outputDir);
    else
    {
        fmt::print("Invalid format!\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}