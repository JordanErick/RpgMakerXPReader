#pragma once

#include "any.hpp"
#include "object.hpp"

class Reader
{
public:
    Reader(const std::vector<u8>& bytes);
    Any parse();

private:
    void readVersion();
    Any readFixnum();
    Any readString();
    Any readSymbol();
    Any readSymlink();
    Any readUserDef();
    Any readArray();
    Any readHash();
    Any readObject();
    Any readLink();

    template<typename T>
    T read()
    {
        if (mIndex + sizeof(T) > mBytes.size())
            throw std::runtime_error("End of buffer");

        T value = *((T*)(mBytes.data() + mIndex));
        mIndex += sizeof(T);

        return value;
    }

private:
    size_t mIndex;
    std::vector<u8> mBytes;
    std::vector<std::string> mSymbolCache;
    std::vector<Any> mObjectCache;
};