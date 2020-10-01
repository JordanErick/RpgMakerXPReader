#include "reader/types/actor.hpp"

rpg::Actor::Actor()
: mParameters{2, 6, 100, 1, 600}
{
    for (size_t i = 1; i <= 99; i++)
    {
        mParameters[6 * i + 0] = static_cast<i16>(500 + i * 50); // MaxHP
        mParameters[6 * i + 1] = static_cast<i16>(500 + i * 50); // MaxSP
        mParameters[6 * i + 2] = static_cast<i16>(50 + i * 5); // Strength
        mParameters[6 * i + 3] = static_cast<i16>(50 + i * 5); // Dexterity
        mParameters[6 * i + 4] = static_cast<i16>(50 + i * 5); // Agility
        mParameters[6 * i + 5] = static_cast<i16>(50 + i * 5); // Intelligence
    }
}

rpg::Actor::Actor(const Object& object)
{
    if (object.className() != "RPG::Actor")
        throw std::runtime_error(fmt::format("Invalid class name: {}", object.className()));

    mShieldFix = *object["@armor1_fix"].as<bool>();
    mShieldID = *object["@armor1_id"].as<i32>();
    mHelmetFix = *object["@armor2_fix"].as<bool>();
    mHelmetID = *object["@armor2_id"].as<i32>();
    mBodyArmorFix = *object["@armor3_fix"].as<bool>();
    mBodyArmorID = *object["@armor3_id"].as<i32>();
    mAccessoryFix = *object["@armor4_fix"].as<bool>();
    mAccessoryID = *object["@armor4_id"].as<i32>();
    mBattlerHue = *object["@battler_hue"].as<i32>();
    mBattlerName = *object["@battler_name"].as<std::string>();
    mCharacterHue = *object["@character_hue"].as<i32>();
    mCharacterName = *object["@character_name"].as<std::string>();
    mClassID = *object["@class_id"].as<i32>();
    mExperienceBasis = *object["@exp_basis"].as<i32>();
    mExperienceInflation = *object["@exp_inflation"].as<i32>();
    mFinalLevel = *object["@final_level"].as<i32>();
    mID = *object["@id"].as<i32>();
    mInitialLevel = *object["@initial_level"].as<i32>();
    mName = *object["@name"].as<std::string>();
    mParameters = *object["@parameters"].as<Table>();
    mWeaponFix = *object["@weapon_fix"].as<bool>();
    mWeaponID = *object["@weapon_id"].as<i32>();
}

bool rpg::Actor::operator==(const Actor& other) const
{
    return mID == other.mID;
}

bool rpg::Actor::operator!=(const Actor& other) const
{
    return !operator==(other);
}

bool rpg::Actor::operator<(const Actor& other) const
{
    return mID < other.mID;
}

void rpg::to_json(json& j, const Actor& o)
{
    j = json{
        JSON_SET(ShieldFix),
        JSON_SET(ShieldID),
        JSON_SET(HelmetFix),
        JSON_SET(HelmetID),
        JSON_SET(BodyArmorFix),
        JSON_SET(BodyArmorID),
        JSON_SET(AccessoryFix),
        JSON_SET(AccessoryID),
        JSON_SET(BattlerHue),
        JSON_SET(BattlerName),
        JSON_SET(CharacterHue),
        JSON_SET(CharacterName),
        JSON_SET(ClassID),
        JSON_SET(ExperienceBasis),
        JSON_SET(ExperienceInflation),
        JSON_SET(FinalLevel),
        JSON_SET(ID),
        JSON_SET(InitialLevel),
        JSON_SET(Name),
        JSON_SET(Parameters),
        JSON_SET(WeaponFix),
        JSON_SET(WeaponID)
    };
}

void rpg::from_json(const json& j, Actor& o)
{
    JSON_GET(ShieldFix);
    JSON_GET(ShieldID);
    JSON_GET(HelmetFix);
    JSON_GET(HelmetID);
    JSON_GET(BodyArmorFix);
    JSON_GET(BodyArmorID);
    JSON_GET(AccessoryFix);
    JSON_GET(AccessoryID);
    JSON_GET(BattlerHue);
    JSON_GET(BattlerName);
    JSON_GET(CharacterHue);
    JSON_GET(CharacterName);
    JSON_GET(ClassID);
    JSON_GET(ExperienceBasis);
    JSON_GET(ExperienceInflation);
    JSON_GET(FinalLevel);
    JSON_GET(ID);
    JSON_GET(InitialLevel);
    JSON_GET(Name);
    JSON_GET(Parameters);
    JSON_GET(WeaponFix);
    JSON_GET(WeaponID);
}
