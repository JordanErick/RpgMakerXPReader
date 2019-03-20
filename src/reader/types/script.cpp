#include "reader\types\script.hpp"

rpg::Script::Script()
: mID{}
, mMagicNumber{}
, mName{}
, mCode{}
{
}

rpg::Script::Script(i32 id, const Array& array)
: mID{id}
, mMagicNumber{}
, mName{}
, mCode{}
{
    mMagicNumber = *array[0].as<i32>();
    mName = *array[1].as<std::string>();
    mCode = decompress(*array[2].as<std::string>());
}

i32 rpg::Script::ID() const
{
    return mID;
}

i32 rpg::Script::magicNumber() const
{
    return mMagicNumber;
}

const std::string& rpg::Script::name() const
{
    return mName;
}

const std::string& rpg::Script::code() const
{
    return mCode;
}

bool rpg::Script::operator==(const Script& other) const
{
    return mID == other.mID;
}

bool rpg::Script::operator!=(const Script& other) const
{
    return !operator==(other);
}

bool rpg::Script::operator<(const Script& other) const
{
    return mID < other.mID;
}

void rpg::to_json(json& j, const Script& o)
{
    j = json{
        JSON_SET(ID),
        JSON_SET(MagicNumber),
        JSON_SET(Name),
        JSON_SET(Code)
    };
}

void rpg::from_json(const json& j, Script& o)
{
    JSON_GET(ID);
    JSON_GET(MagicNumber);
    JSON_GET(Name);
    JSON_GET(Code);
}
