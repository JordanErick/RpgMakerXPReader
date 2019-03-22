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

        bool               shieldFix() const { return mShieldFix; }
        i32                shieldID() const { return mShieldID; }
        bool               helmetFix() const { return mHelmetFix; }
        i32                helmetID() const { return mHelmetID; }
        bool               bodyArmorFix() const { return mBodyArmorFix; }
        i32                bodyArmorID() const { return mBodyArmorID; }
        bool               accessoryFix() const { return mAccessoryFix; }
        i32                accessoryID() const { return mAccessoryID; }
        i32                battlerHue() const { return mBattlerHue; }
        const std::string& battlerName() const { return mBattlerName; }
        i32                characterHue() const { return mCharacterHue; }
        const std::string& characterName() const { return mCharacterName; }
        i32                classID() const { return mClassID; }
        i32                experienceBasis() const { return mExperienceBasis; }
        i32                experienceInflation() const { return mExperienceInflation; }
        i32                finalLevel() const { return mFinalLevel; }
        i32                ID() const { return mID; }
        i32                initialLevel() const { return mInitialLevel; }
        const std::string& name() const { return mName; }
        const Table&       parameters() const { return mParameters; }
        bool               weaponFix() const { return mWeaponFix; }
        i32                weaponID() const { return mWeaponID; }

        bool               operator==(const Actor& other) const;
        bool               operator!=(const Actor& other) const;
        bool               operator<(const Actor& other) const;
    private:
        bool               mShieldFix = false;
        i32                mShieldID = 0;
        bool               mHelmetFix = false;
        i32                mHelmetID = 0;
        bool               mBodyArmorFix = false;
        i32                mBodyArmorID = 0;
        bool               mAccessoryFix = false;
        i32                mAccessoryID = 0;
        i32                mBattlerHue = 0;
        std::string        mBattlerName = "";
        i32                mCharacterHue = 0;
        std::string        mCharacterName = "";
        i32                mClassID = 1;
        i32                mExperienceBasis = 30;
        i32                mExperienceInflation = 30;
        i32                mFinalLevel = 99;
        i32                mID = 0;
        i32                mInitialLevel = 1;
        std::string        mName = "";
        Table              mParameters = {};
        bool               mWeaponFix = false;
        i32                mWeaponID = 0;

        friend void        to_json(json& j, const Actor& o);
        friend void        from_json(const json& j, Actor& o);
    };

    void to_json(json& j, const Actor& o);
    void from_json(const json& j, Actor& o);
}