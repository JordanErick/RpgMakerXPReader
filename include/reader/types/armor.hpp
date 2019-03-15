#pragma once

#include "common.hpp"

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

                            Armor();
                            Armor(const Object& object);

    i32                     agilityBonus() const;
    i32                     autoStateID() const;
    const std::string&      description() const;
    i32                     dexterityBonus() const;
    i32                     evasionCorrection() const;
    const std::vector<i32>& guardElementSet() const;
    const std::vector<i32>& guardStateSet() const;
    const std::string&      iconName() const;
    i32                     ID() const;
    i32                     intelligenceBonus() const;
    Kind                    kind() const;
    i32                     magicDefense() const;
    const std::string&      name() const;
    i32                     physicalDefense() const;
    i32                     price() const;
    i32                     strengthBonus() const;

    bool                    operator==(const Armor& other) const;
    bool                    operator!=(const Armor& other) const;
    bool                    operator<(const Armor& other) const;
private:
    i32                     mAgilityBonus;
    i32                     mAutoStateID;
    std::string             mDescription;
    i32                     mDexterityBonus;
    i32                     mEvasionCorrection;
    std::vector<i32>        mGuardElementSet;
    std::vector<i32>        mGuardStateSet;
    std::string             mIconName;
    i32                     mID;
    i32                     mIntelligenceBonus;
    Kind                    mKind;
    i32                     mMagicDefense;
    std::string             mName;
    i32                     mPhysicalDefense;
    i32                     mPrice;
    i32                     mStrengthBonus;

    friend void             to_json(json& j, const Armor& o);
    friend void             from_json(const json& j, Armor& o);
};

void to_json(json& j, const Armor& o);
void from_json(const json& j, Armor& o);