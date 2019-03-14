#include "reader/types/armor.hpp"

Armor::Armor()
: mAgilityBonus{}
, mAutoStateID{}
, mDescription{}
, mDexterityBonus{}
, mEvasionCorrection{}
, mGuardElementSet{}
, mGuardStateSet{}
, mIconName{}
, mID{}
, mIntelligenceBonus{}
, mKind{}
, mMagicDefense{}
, mName{}
, mPhysicalDefense{}
, mPrice{}
, mStrengthBonus{}
{
}

Armor::Armor(const Object& object)
: mAgilityBonus{}
, mAutoStateID{}
, mDescription{}
, mDexterityBonus{}
, mEvasionCorrection{}
, mGuardElementSet{}
, mGuardStateSet{}
, mIconName{}
, mID{}
, mIntelligenceBonus{}
, mKind{}
, mMagicDefense{}
, mName{}
, mPhysicalDefense{}
, mPrice{}
, mStrengthBonus{}
{
    if (object.className() != "RPG::Armor")
        throw std::runtime_error(fmt::format("Invalid class name: {}", object.className()));

    mAgilityBonus = *object["@agi_plus"].as<i32>();
    mAutoStateID = *object["@auto_state_id"].as<i32>();
    mDescription = *object["@description"].as<std::string>();
    mDexterityBonus = *object["@dex_plus"].as<i32>();
    mEvasionCorrection = *object["@eva"].as<i32>();

    auto* guardElementSet = object["@guard_element_set"].as<Array>();
    for (const auto& e : *guardElementSet)
        mGuardElementSet.push_back(*e.as<i32>());

    auto* guardStateSet = object["@guard_state_set"].as<Array>();
    for (const auto& e : *guardStateSet)
        mGuardStateSet.push_back(*e.as<i32>());

    mIconName = *object["@icon_name"].as<std::string>();
    mID = *object["@id"].as<i32>();
    mIntelligenceBonus = *object["@int_plus"].as<i32>();
    mKind = static_cast<Kind>(*object["@kind"].as<i32>());
    mMagicDefense = *object["@mdef"].as<i32>();
    mName = *object["@name"].as<std::string>();
    mPhysicalDefense = *object["@pdef"].as<i32>();
    mPrice = *object["@price"].as<i32>();
    mStrengthBonus = *object["@str_plus"].as<i32>();
}

i32 Armor::agilityBonus() const
{
    return mAgilityBonus;
}

i32 Armor::autoStateID() const
{
    return mAutoStateID;
}

const std::string& Armor::description() const
{
    return mDescription;
}

i32 Armor::dexterityBonus() const
{
    return mDexterityBonus;
}

i32 Armor::evasionCorrection() const
{
    return mEvasionCorrection;
}

const std::vector<i32>& Armor::guardElementSet() const
{
    return mGuardElementSet;
}

const std::vector<i32>& Armor::guardStateSet() const
{
    return mGuardStateSet;
}

const std::string & Armor::iconName() const
{
    return mIconName;
}

i32 Armor::ID() const
{
    return mID;
}

i32 Armor::intelligenceBonus() const
{
    return mIntelligenceBonus;
}

Armor::Kind Armor::kind() const
{
    return mKind;
}

i32 Armor::magicDefense() const
{
    return mMagicDefense;
}

const std::string& Armor::name() const
{
    return mName;
}

i32 Armor::physicalDefense() const
{
    return mPhysicalDefense;
}

i32 Armor::price() const
{
    return mPrice;
}

i32 Armor::strengthBonus() const
{
    return mStrengthBonus;
}

bool Armor::operator==(const Armor& other) const
{
    return mID == other.mID;
}

bool Armor::operator!=(const Armor& other) const
{
    return !operator==(other);
}

bool Armor::operator<(const Armor& other) const
{
    return mID < other.mID;
}

void to_json(json& j, const Armor& o)
{
    j = json{
        JSON_SET(AgilityBonus),
        JSON_SET(AutoStateID),
        JSON_SET(Description),
        JSON_SET(DexterityBonus),
        JSON_SET(EvasionCorrection),
        JSON_SET(GuardElementSet),
        JSON_SET(GuardStateSet),
        JSON_SET(IconName),
        JSON_SET(ID),
        JSON_SET(IntelligenceBonus),
        JSON_SET(Kind),
        JSON_SET(MagicDefense),
        JSON_SET(Name),
        JSON_SET(PhysicalDefense),
        JSON_SET(Price),
        JSON_SET(StrengthBonus)
    };
}

void from_json(const json& j, Armor& o)
{
    JSON_GET(AgilityBonus);
    JSON_GET(AutoStateID);
    JSON_GET(Description);
    JSON_GET(DexterityBonus);
    JSON_GET(EvasionCorrection);
    JSON_GET(GuardElementSet);
    JSON_GET(GuardStateSet);
    JSON_GET(IconName);
    JSON_GET(ID);
    JSON_GET(IntelligenceBonus);
    JSON_GET(Kind);
    JSON_GET(MagicDefense);
    JSON_GET(Name);
    JSON_GET(PhysicalDefense);
    JSON_GET(Price);
    JSON_GET(StrengthBonus);
}
