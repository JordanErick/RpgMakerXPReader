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

std::vector<std::string> split(const std::string& str, char delimiter)
{
    if (str.length() == 0) return {};

    std::vector<std::string> lines;

    size_t actual = 0;
    while (true)
    {
        size_t pos = str.find(delimiter, actual);
        if (pos - actual != 0) lines.push_back(str.substr(actual, pos - actual));

        if (pos == std::string::npos || pos + 1 >= str.length()) break;
        else actual = pos + 1;
    }

    return lines;
}