#include "reader/utility.hpp"

std::vector<u8> loadFileIntoVector(const std::string& filename)
{
    std::ifstream file{ filename, std::fstream::binary };

    if (!file)
        throw std::runtime_error(fmt::format("Unable to open '{}'", filename));

    file.seekg(0, std::fstream::end);

    auto bytes = std::vector<u8>(static_cast<size_t>(file.tellg()));

    file.seekg(0, std::fstream::beg);

    file.read(reinterpret_cast<char*>(bytes.data()), bytes.size());

    if(!file)
        throw std::runtime_error(fmt::format("Unable to read data from '{}'", filename));

    return bytes;
}

std::string loadFileIntoString(const std::string& filename)
{
    std::ifstream file{ filename };

    if (!file)
        throw std::runtime_error(fmt::format("Unable to open '{}'", filename));

    file.seekg(0, std::fstream::end);

    auto bytes = std::string(static_cast<size_t>(file.tellg()), ' ');

    file.seekg(0, std::fstream::beg);

    file.read(&bytes[0], bytes.size());

    bytes.resize(static_cast<size_t>(file.gcount()));

    return bytes;
}

std::string decompress(const std::string& str)
{
    z_stream stream{};
    int err;

    stream.next_in = (Byte*)str.data();
    stream.avail_in = (uInt)str.size();
    
    err = inflateInit(&stream);
    if (err != Z_OK)
        throw std::runtime_error(fmt::format("inflateInit error: {}", err));

    Byte* buffer = nullptr;
    size_t size = str.size();

    while (true)
    {
        size *= 2;
        buffer = (Byte*)realloc(buffer, size);

        stream.next_out = buffer + stream.total_out;
        stream.avail_out = size - stream.total_out;

        err = inflate(&stream, Z_NO_FLUSH);

        if (err == Z_STREAM_END) 
            break;

        if (err != Z_OK)
        {
            free(buffer);
            inflateEnd(&stream);
            throw std::runtime_error(fmt::format("inflate error: {}", err));
        }
    }

    size = stream.total_out;
    err = inflateEnd(&stream);

    if (err != Z_OK)
    {
        free(buffer);
        throw std::runtime_error(fmt::format("inflateEnd error: {}", err));
    }

    std::string output{ (char*)buffer, size };
    free(buffer);

    return output;
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