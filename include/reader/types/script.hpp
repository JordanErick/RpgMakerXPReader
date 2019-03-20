#pragma once

#include "../any.hpp"
#include "../utility.hpp"

namespace rpg
{
    class Script
    {
    public:
                           Script();
                           Script(i32 id, const Array& array);

        i32                ID() const;
        i32                magicNumber() const;
        const std::string& name() const;
        const std::string& code() const;

        bool               operator==(const Script& other) const;
        bool               operator!=(const Script& other) const;
        bool               operator<(const Script& other) const;
    private:
        i32                mID;
        i32                mMagicNumber;
        std::string        mName;
        std::string        mCode;

        friend void        to_json(json& j, const Script& o);
        friend void        from_json(const json& j, Script& o);
    };

    void to_json(json& j, const Script& o);
    void from_json(const json& j, Script& o);
}