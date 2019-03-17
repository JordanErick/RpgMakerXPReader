#pragma once

#include "../object.hpp"
#include "table.hpp"

namespace rpg
{
    class Actor
    {
    public:
                           Actor();
                           Actor(const Object& object);

        bool               shieldFix() const;
        i32                shieldID() const;
        bool               helmetFix() const;
        i32                helmetID() const;
        bool               bodyArmorFix() const;
        i32                bodyArmorID() const;
        bool               accessoryFix() const;
        i32                accessoryID() const;
        i32                battlerHue() const;
        const std::string& battlerName() const;
        i32                characterHue() const;
        const std::string& characterName() const;
        i32                classID() const;
        i32                experienceBasis() const;
        i32                experienceInflation() const;
        i32                finalLevel() const;
        i32                ID() const;
        i32                initialLevel() const;
        const std::string& name() const;
        const Table&       parameters() const;
        bool               weaponFix() const;
        i32                weaponID() const;

        bool               operator==(const Actor& other) const;
        bool               operator!=(const Actor& other) const;
        bool               operator<(const Actor& other) const;
    private:
        bool               mShieldFix;
        i32                mShieldID;
        bool               mHelmetFix;
        i32                mHelmetID;
        bool               mBodyArmorFix;
        i32                mBodyArmorID;
        bool               mAccessoryFix;
        i32                mAccessoryID;
        i32                mBattlerHue;
        std::string        mBattlerName;
        i32                mCharacterHue;
        std::string        mCharacterName;
        i32                mClassID;
        i32                mExperienceBasis;
        i32                mExperienceInflation;
        i32                mFinalLevel;
        i32                mID;
        i32                mInitialLevel;
        std::string        mName;
        Table              mParameters;
        bool               mWeaponFix;
        i32                mWeaponID;

        friend void        to_json(json& j, const Actor& o);
        friend void        from_json(const json& j, Actor& o);
    };

    void to_json(json& j, const Actor& o);
    void from_json(const json& j, Actor& o);
}