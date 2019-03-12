#include "common.hpp"

class Weapon
{
public:
                            Weapon();
                            Weapon(const Object& object);

    i32                     agilityBonus() const;
    i32                     attackerAnimation() const;
    i32                     targetAnimation() const;
    i32                     attackPower() const;
    const std::string&      description() const;
    i32                     dexterityBonus() const;
    const std::vector<i32>& elementSet() const;
    const std::string&      iconName() const;
    i32                     ID() const;
    i32                     intelligenceBonus() const;
    i32                     magicDefense() const;
    const std::vector<i32>& minusStateSet() const;
    const std::string&      name() const;
    i32                     physicalDefense() const;
    const std::vector<i32>& plusStateSet() const;
    i32                     price() const;
    i32                     strengthBonus() const;

    bool                    operator==(const Weapon& other) const;
    bool                    operator!=(const Weapon& other) const;
    bool                    operator<(const Weapon& other) const;
private:
    i32 mAgilityBonus;
    i32 mAttackerAnimation;
    i32 mTargetAnimation;
    i32 mAttackPower;
    std::string mDescription;
    i32 mDexterityBonus;
    std::vector<i32> mElementSet;
    std::string mIconName;
    i32 mID;
    i32 mIntelligenceBonus;
    i32 mMagicDefense;
    std::vector<i32> mMinusStateSet;
    std::string mName;
    i32 mPhysicalDefense;
    std::vector<i32> mPlusStateSet;
    i32 mPrice;
    i32 mStrengthBonus;

    friend void             to_json(json& j, const Weapon& o);
    friend void             from_json(const json& j, Weapon& o);
};

void to_json(json& j, const Weapon& o);
void from_json(const json& j, Weapon& o);