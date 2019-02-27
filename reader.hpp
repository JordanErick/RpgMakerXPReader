#pragma once

#include "value.hpp"

class MarshalReader
{
public:
    MarshalReader(std::vector<u8> bytes);

    Value parse();

    void seek(size_t index) { mIndex = index; }
    size_t tell() { return mIndex; }

private:
    template<typename T>
    T read()
    {
        if (mIndex + sizeof(T) > mBytes.size())
            throw std::runtime_error("End of buffer");

        T value = *((T*)(mBytes.data() + mIndex));
        mIndex += sizeof(T);

        return value;
    }

    int readFixnum();
    std::string readString();
    std::string readSymbol();
    std::vector<Value> readArray();
    std::map<Value, Value> readObject();
    std::map<Value, Value> readHash();
    std::string readSymlink();
    Table readUserDef();

private:
    std::vector<u8> mBytes;
    size_t mIndex;

    std::vector<std::string> mSymbolCache;
};