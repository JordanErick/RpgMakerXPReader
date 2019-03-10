#include "utility.hpp"

std::vector<u8> loadFileIntoMemory(const std::string& filename)
{
    FILE* file = fopen(filename.c_str(), "rb");

    if (!file)
        throw std::runtime_error(fmt::format("Unable to open '{}'", filename));

    fseek(file, 0, SEEK_END);

    auto bytes = std::vector<u8>(ftell(file));

    fseek(file, 0, SEEK_SET);

    if (fread(bytes.data(), sizeof(u8), bytes.size(), file) != bytes.size())
    {
        fclose(file);
        throw std::runtime_error(fmt::format("Unable to read data from '{}'", filename));
    }

    fclose(file);
    return bytes;
}

void writeStringToFile(const std::string& filename, const std::string& str)
{
    FILE* file = fopen(filename.c_str(), "w");

    if (fwrite(str.data(), str.size(), 1, file) != 1)
    {
        fclose(file);
        throw std::runtime_error(fmt::format("Unable to write data to '{}'", filename));
    }

    fclose(file);
}