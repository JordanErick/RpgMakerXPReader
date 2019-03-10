#include "types\armor.hpp"

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
        {"agility_bonus", o.mAgilityBonus},
        {"auto_state_id", o.mAutoStateID},
        {"description", o.mDescription},
        {"dexterity_bonus", o.mDexterityBonus},
        {"evasion_correction", o.mEvasionCorrection},
        {"guard_element_set", o.mGuardElementSet},
        {"guard_state_set", o.mGuardStateSet},
        {"icon_name", o.mIconName},
        {"id", o.mID},
        {"intelligence_bonus", o.mIntelligenceBonus},
        {"kind", o.mKind},
        {"magic_defense", o.mMagicDefense},
        {"name", o.mName},
        {"physical_defense", o.mPhysicalDefense},
        {"price", o.mPrice},
        {"strength_bonus", o.mStrengthBonus},
    };
}

void from_json(const json& j, Armor& o)
{
    j.at("agility_bonus").get_to(o.mAgilityBonus);
    j.at("auto_state_id").get_to(o.mAutoStateID);
    j.at("description").get_to(o.mDescription);
    j.at("dexterity_bonus").get_to(o.mDexterityBonus);
    j.at("evasion_correction").get_to(o.mEvasionCorrection);
    j.at("guard_element_set").get_to(o.mGuardElementSet);
    j.at("guard_state_set").get_to(o.mGuardStateSet);
    j.at("icon_name").get_to(o.mIconName);
    j.at("id").get_to(o.mID);
    j.at("intelligence_bonus").get_to(o.mIntelligenceBonus);
    j.at("kind").get_to(o.mKind);
    j.at("magic_defense").get_to(o.mMagicDefense);
    j.at("name").get_to(o.mName);
    j.at("physical_defense").get_to(o.mPhysicalDefense);
    j.at("price").get_to(o.mPrice);
    j.at("strength_bonus").get_to(o.mStrengthBonus);
}
