#include "reader/types/weapon.hpp"

Weapon::Weapon()
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

Weapon::Weapon(const Object& object)
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

i32 Weapon::agilityBonus() const
{
    return mAgilityBonus;
}

i32 Weapon::attackerAnimation() const
{
    return mAttackerAnimation;
}

i32 Weapon::targetAnimation() const
{
    return mTargetAnimation;
}

i32 Weapon::attackPower() const
{
    return mAttackPower;
}

const std::string& Weapon::description() const
{
    return mDescription;
}

i32 Weapon::dexterityBonus() const
{
    return mDexterityBonus;
}

const std::vector<i32>& Weapon::elementSet() const
{
    return mElementSet;
}

const std::string& Weapon::iconName() const
{
    return mIconName;
}

i32 Weapon::ID() const
{
    return mID;
}

i32 Weapon::intelligenceBonus() const
{
    return mIntelligenceBonus;
}

i32 Weapon::magicDefense() const
{
    return mMagicDefense;
}

const std::vector<i32>& Weapon::minusStateSet() const
{
    return mMinusStateSet;
}

const std::string& Weapon::name() const
{
    return mName;
}

i32 Weapon::physicalDefense() const
{
    return mPhysicalDefense;
}

const std::vector<i32>& Weapon::plusStateSet() const
{
    return mPlusStateSet;
}

i32 Weapon::price() const
{
    return mPrice;
}

i32 Weapon::strengthBonus() const
{
    return mStrengthBonus;
}

bool Weapon::operator==(const Weapon& other) const
{
    return mID == other.mID;
}

bool Weapon::operator!=(const Weapon& other) const
{
    return !operator==(other);
}

bool Weapon::operator<(const Weapon& other) const
{
    return mID < other.mID;
}

void to_json(json& j, const Weapon& o)
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

void from_json(const json& j, Weapon& o)
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
