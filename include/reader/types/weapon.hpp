#pragma once

#include "audio_file.hpp"

namespace rpg
{
    class Weapon
    {
    public:
                                Weapon() {}
                                Weapon(const Object& object);

        i32                     agilityBonus() const { return mAgilityBonus; }
        i32                     attackerAnimation() const { return mAttackerAnimation; }
        i32                     targetAnimation() const { return mTargetAnimation; }
        i32                     attackPower() const { return mAttackPower; }
        const std::string&      description() const { return mDescription; }
        i32                     dexterityBonus() const { return mDexterityBonus; }
        const std::vector<i32>& elementSet() const { return mElementSet; }
        const std::string&      iconName() const { return mIconName; }
        i32                     ID() const { return mID; }
        i32                     intelligenceBonus() const { return mIntelligenceBonus; }
        i32                     magicDefense() const { return mMagicDefense; }
        const std::vector<i32>& minusStateSet() const { return mMinusStateSet; }
        const std::string&      name() const { return mName; }
        i32                     physicalDefense() const { return mPhysicalDefense; }
        const std::vector<i32>& plusStateSet() const { return mPlusStateSet; }
        i32                     price() const { return mPrice; }
        i32                     strengthBonus() const { return mStrengthBonus; }

        bool                    operator==(const Weapon& other) const;
        bool                    operator!=(const Weapon& other) const;
        bool                    operator<(const Weapon& other) const;
    private:
        i32                     mAgilityBonus = 0;
        i32                     mAttackerAnimation = 0;
        i32                     mTargetAnimation = 0;
        i32                     mAttackPower = 0;
        std::string             mDescription = "";
        i32                     mDexterityBonus = 0;
        std::vector<i32>        mElementSet = {};
        std::string             mIconName = "";
        i32                     mID = 0;
        i32                     mIntelligenceBonus = 0;
        i32                     mMagicDefense = 0;
        std::vector<i32>        mMinusStateSet = {};
        std::string             mName = "";
        i32                     mPhysicalDefense = 0;
        std::vector<i32>        mPlusStateSet = {};
        i32                     mPrice = 0;
        i32                     mStrengthBonus = 0;

        friend void             to_json(json& j, const Weapon& o);
        friend void             from_json(const json& j, Weapon& o);
    };

    void to_json(json& j, const Weapon& o);
    void from_json(const json& j, Weapon& o);
}