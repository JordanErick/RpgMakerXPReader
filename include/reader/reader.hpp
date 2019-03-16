#pragma once

#include <chrono>
#include <experimental/filesystem>

#include "any.hpp"
#include "object.hpp"
#include "types.hpp"

#include "fmt/ostream.hpp"

namespace fs = std::experimental::filesystem;

namespace rpg
{
    class Reader
    {
    public:
                                 Reader(const std::vector<u8>& bytes);
        Any                      parse();

    private:
        void                     readVersion();
        Any                      readFixnum();
        Any                      readString();
        Any                      readSymbol();
        Any                      readSymlink();
        Any                      readUserDef();
        Any                      readArray();
        Any                      readHash();
        Any                      readObject();
        Any                      readLink();

        template<typename T>
        T read()
        {
            if (mIndex + sizeof(T) > mBytes.size())
                throw std::runtime_error("End of buffer");

            T value = *reinterpret_cast<T*>(mBytes.data() + mIndex);
            mIndex += sizeof(T);

            return value;
        }

    private:
        size_t                   mIndex;
        std::vector<u8>          mBytes;
        std::vector<std::string> mSymbolCache;
        std::vector<Any>         mObjectCache;
    };
}

std::string                      whitespace(int count);
void                             writeToString(std::string& str, const rpg::Any& any, int indent = 0);
void                             rxdataToJSON(const fs::path& inputDir, const fs::path& outputDir);
void                             rxdataToTxt(const fs::path& inputDir, const fs::path& outputDir);