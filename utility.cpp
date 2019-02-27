#include "utility.hpp"

std::vector<u8> loadFileIntoMemory(const std::string& filename)
{
    FILE* file = fopen(filename.c_str(), "rb");

    if (!file)
        throw std::runtime_error("'" + filename + "' unable to open");

    fseek(file, 0, SEEK_END);

    auto bytes = std::vector<u8>(ftell(file));

    fseek(file, 0, SEEK_SET);

    if (fread(bytes.data(), sizeof(u8), bytes.size(), file) != bytes.size())
    {
        fclose(file);
        throw std::runtime_error("'" + filename + "' unable to read data");
    }

    fclose(file);
    return bytes;
}