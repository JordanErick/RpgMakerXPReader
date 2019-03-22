#pragma once

#include "audio_file.hpp"

namespace rpg
{
    class Armor
    {
    public:
        enum class Kind : i32
        {
            Shield,
            Helmet,
            BodyArmor,
            Accessory,
        };

                                Armor() {}
                                Armor(const Object& object);

        i32                     agilityBonus() const { return mAgilityBonus; }
        i32                     autoStateID() const { return mAutoStateID; }
        const std::string&      description() const { return mDescription; }
        i32                     dexterityBonus() const { return mDexterityBonus; }
        i32                     evasionCorrection() const { return mEvasionCorrection; }
        const std::vector<i32>& guardElementSet() const { return mGuardElementSet; }
        const std::vector<i32>& guardStateSet() const { return mGuardStateSet; }
        const std::string&      iconName() const { mIconName; }
        i32                     ID() const { return mID; }
        i32                     intelligenceBonus() const { return mIntelligenceBonus; }
        Kind                    kind() const { return mKind; }
        i32                     magicDefense() const { return mMagicDefense; }
        const std::string&      name() const { return mName; }
        i32                     physicalDefense() const { return mPhysicalDefense; }
        i32                     price() const { return mPrice; }
        i32                     strengthBonus() const { return mStrengthBonus; }

        bool                    operator==(const Armor& other) const;
        bool                    operator!=(const Armor& other) const;
        bool                    operator<(const Armor& other) const;
    private:
        i32                     mAgilityBonus = 0;
        i32                     mAutoStateID = 0;
        std::string             mDescription = "";
        i32                     mDexterityBonus = 0;
        i32                     mEvasionCorrection = 0;
        std::vector<i32>        mGuardElementSet = {};
        std::vector<i32>        mGuardStateSet = {};
        std::string             mIconName = "";
        i32                     mID = 0;
        i32                     mIntelligenceBonus = 0;
        Kind                    mKind = Kind::Shield;
        i32                     mMagicDefense = 0;
        std::string             mName = "";
        i32                     mPhysicalDefense = 0;
        i32                     mPrice = 0;
        i32                     mStrengthBonus = 0;

        friend void             to_json(json& j, const Armor& o);
        friend void             from_json(const json& j, Armor& o);
    };

    void to_json(json& j, const Armor& o);
    void from_json(const json& j, Armor& o);
}
