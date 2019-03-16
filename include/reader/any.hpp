#pragma once

#include "type.hpp"
#include "types/color.hpp"
#include "types/table.hpp"
#include "types/tone.hpp"
#include "utility.hpp"

namespace rpg
{
    class Any
    {
    public:
                Any();
                Any(Type type, void* value);
                Any(const Any& other);
        Any&    operator=(const Any& other);
                ~Any();

        bool    operator==(const Any& other) const;
        bool    operator!=(const Any& other) const;
        bool    operator<(const Any& other) const;

        Type    type() const;
        void*   value() const;

        template<typename T>
        T*      as() const { return static_cast<T*>(mValue); }

    private:
        void    destructor();

    private:
        Type    mType;
        void*   mValue;
    };

    using Array = std::vector<Any>;
    using Hash = std::map<Any, Any>;
}