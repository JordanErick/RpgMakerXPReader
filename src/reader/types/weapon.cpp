#include "reader/types/weapon.hpp"

rpg::Weapon::Weapon()
: mAgilityBonus{}
, mAttackerAnimation{}
, mTargetAnimation{}
, mAttackPower{}
, mDescription{}
, mDexterityBonus{}
, mElementSet{}
, mIconName{}
, mID{}
, mIntelligenceBonus{}
, mMagicDefense{}
, mMinusStateSet{}
, mName{}
, mPhysicalDefense{}
, mPlusStateSet{}
, mPrice{}
, mStrengthBonus{}
{
}

rpg::Weapon::Weapon(const Object& object)
: mAgilityBonus{}
, mAttackerAnimation{}
, mTargetAnimation{}
, mAttackPower{}
, mDescription{}
, mDexterityBonus{}
, mElementSet{}
, mIconName{}
, mID{}
, mIntelligenceBonus{}
, mMagicDefense{}
, mMinusStateSet{}
, mName{}
, mPhysicalDefense{}
, mPlusStateSet{}
, mPrice{}
, mStrengthBonus{}
{
    if (object.className() != "RPG::Weapon")
        throw std::runtime_error(fmt::format("Invalid class name: {}", object.className()));

    mAgilityBonus = *object["@agi_plus"].as<i32>();
    mAttackerAnimation = *object["@animation1_id"].as<i32>();
    mTargetAnimation = *object["@animation2_id"].as<i32>();
    mAttackPower = *object["@atk"].as<i32>();
    mDescription = *object["@description"].as<std::string>();
    mDexterityBonus = *object["@dex_plus"].as<i32>();

    auto* elementSet = object["@element_set"].as<Array>();
    for (const auto& e : *elementSet)
        mElementSet.push_back(*e.as<i32>());

    mIconName = *object["@icon_name"].as<std::string>();
    mID = *object["@id"].as<i32>();
    mIntelligenceBonus = *object["@int_plus"].as<i32>();
    mMagicDefense = *object["@mdef"].as<i32>();

    auto* minusStateSet = object["@minus_state_set"].as<Array>();
    for (const auto& e : *minusStateSet)
        mMinusStateSet.push_back(*e.as<i32>());

    mName = *object["@name"].as<std::string>();
    mPhysicalDefense = *object["@pdef"].as<i32>();

    auto* plusStateSet = object["@plus_state_set"].as<Array>();
    for (const auto& e : *plusStateSet)
        mPlusStateSet.push_back(*e.as<i32>());

    mPrice = *object["@price"].as<i32>();
    mStrengthBonus = *object["@str_plus"].as<i32>();
}

i32 rpg::Weapon::agilityBonus() const
{
    return mAgilityBonus;
}

i32 rpg::Weapon::attackerAnimation() const
{
    return mAttackerAnimation;
}

i32 rpg::Weapon::targetAnimation() const
{
    return mTargetAnimation;
}

i32 rpg::Weapon::attackPower() const
{
    return mAttackPower;
}

const std::string& rpg::Weapon::description() const
{
    return mDescription;
}

i32 rpg::Weapon::dexterityBonus() const
{
    return mDexterityBonus;
}

const std::vector<i32>& rpg::Weapon::elementSet() const
{
    return mElementSet;
}

const std::string& rpg::Weapon::iconName() const
{
    return mIconName;
}

i32 rpg::Weapon::ID() const
{
    return mID;
}

i32 rpg::Weapon::intelligenceBonus() const
{
    return mIntelligenceBonus;
}

i32 rpg::Weapon::magicDefense() const
{
    return mMagicDefense;
}

const std::vector<i32>& rpg::Weapon::minusStateSet() const
{
    return mMinusStateSet;
}

const std::string& rpg::Weapon::name() const
{
    return mName;
}

i32 rpg::Weapon::physicalDefense() const
{
    return mPhysicalDefense;
}

const std::vector<i32>& rpg::Weapon::plusStateSet() const
{
    return mPlusStateSet;
}

i32 rpg::Weapon::price() const
{
    return mPrice;
}

i32 rpg::Weapon::strengthBonus() const
{
    return mStrengthBonus;
}

bool rpg::Weapon::operator==(const Weapon& other) const
{
    return mID == other.mID;
}

bool rpg::Weapon::operator!=(const Weapon& other) const
{
    return !operator==(other);
}

bool rpg::Weapon::operator<(const Weapon& other) const
{
    return mID < other.mID;
}

void rpg::to_json(json& j, const Weapon& o)
{
    j = json{
        JSON_SET(AgilityBonus),
        JSON_SET(AttackerAnimation),
        JSON_SET(TargetAnimation),
        JSON_SET(AttackPower),
        JSON_SET(Description),
        JSON_SET(DexterityBonus),
        JSON_SET(ElementSet),
        JSON_SET(IconName),
        JSON_SET(ID),
        JSON_SET(IntelligenceBonus),
        JSON_SET(MagicDefense),
        JSON_SET(MinusStateSet),
        JSON_SET(Name),
        JSON_SET(PhysicalDefense),
        JSON_SET(PlusStateSet),
        JSON_SET(Price),
        JSON_SET(StrengthBonus)
    };
}

void rpg::from_json(const json& j, Weapon& o)
{
    JSON_GET(AgilityBonus);
    JSON_GET(AttackerAnimation);
    JSON_GET(TargetAnimation);
    JSON_GET(AttackPower);
    JSON_GET(Description);
    JSON_GET(DexterityBonus);
    JSON_GET(ElementSet);
    JSON_GET(IconName);
    JSON_GET(ID);
    JSON_GET(IntelligenceBonus);
    JSON_GET(MagicDefense);
    JSON_GET(MinusStateSet);
    JSON_GET(Name);
    JSON_GET(PhysicalDefense);
    JSON_GET(PlusStateSet);
    JSON_GET(Price);
    JSON_GET(StrengthBonus);
}
