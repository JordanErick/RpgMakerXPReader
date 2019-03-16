#include "reader/types/item.hpp"

rpg::Item::Item()
: mUserAnimationID{}
, mTargetAnimationID{}
, mCommonEventID{}
, mConsumable{}
, mDescription{}
, mHit{}
, mIconName{}
, mID{}
, mMagicalDefense{}
, mMenuSE{}
, mName{}
, mOccasion{}
, mParameterPoints{}
, mParameterType{}
, mPhysicalDefense{}
, mPrice{}
, mRecoverHP{}
, mRecoverHPRate{}
, mRecoverSP{}
, mRecoverSPRate{}
, mScope{}
, mVariance{}
{
}

rpg::Item::Item(const Object& object)
: mUserAnimationID{}
, mTargetAnimationID{}
, mCommonEventID{}
, mConsumable{}
, mDescription{}
, mHit{}
, mIconName{}
, mID{}
, mMagicalDefense{}
, mMenuSE{}
, mName{}
, mOccasion{}
, mParameterPoints{}
, mParameterType{}
, mPhysicalDefense{}
, mPrice{}
, mRecoverHP{}
, mRecoverHPRate{}
, mRecoverSP{}
, mRecoverSPRate{}
, mScope{}
, mVariance{}
{
    if (object.className() != "RPG::Item")
        throw std::runtime_error(fmt::format("Invalid class name: {}", object.className()));

    mUserAnimationID = *object["@animation1_id"].as<i32>();
    mTargetAnimationID = *object["@animation2_id"].as<i32>();
    mCommonEventID = *object["@common_event_id"].as<i32>();
    mConsumable = *object["@consumable"].as<bool>();
    mDescription = *object["@description"].as<std::string>();

    auto* elementSet = object["@element_set"].as<Array>();
    for (const auto& e : *elementSet)
        mElementSet.push_back(*e.as<i32>());

    mHit = *object["@hit"].as<i32>();
    mIconName = *object["@icon_name"].as<std::string>();
    mID = *object["@id"].as<i32>();
    mMagicalDefense = *object["@mdef_f"].as<i32>();
    mMenuSE.load(*object["@menu_se"].as<Object>());

    auto* minusStateSet = object["@minus_state_set"].as<Array>();
    for (const auto& e : *minusStateSet)
        mMinusStateSet.push_back(*e.as<i32>());

    mName = *object["@name"].as<std::string>();
    mOccasion = static_cast<Occasion>(*object["@occasion"].as<i32>());
    mParameterPoints = *object["@parameter_points"].as<i32>();
    mParameterType = static_cast<Parameter>(*object["@parameter_type"].as<i32>());
    mPhysicalDefense = *object["@pdef_f"].as<i32>();

    auto* plusStateSet = object["@plus_state_set"].as<Array>();
    for (const auto& e : *plusStateSet)
        mPlusStateSet.push_back(*e.as<i32>());

    mPrice = *object["@price"].as<i32>();
    mRecoverHP = *object["@recover_hp"].as<i32>();
    mRecoverHPRate = *object["@recover_hp_rate"].as<i32>();
    mRecoverSP = *object["@recover_sp"].as<i32>();
    mRecoverSPRate = *object["@recover_sp_rate"].as<i32>();
    mScope = static_cast<Scope>(*object["@scope"].as<i32>());
    mVariance = *object["@variance"].as<i32>();
}

i32 rpg::Item::userAnimationID() const
{
    return mUserAnimationID;
}

i32 rpg::Item::targetAnimationID() const
{
    return mTargetAnimationID;
}

i32 rpg::Item::commonEventID() const
{
    return mCommonEventID;
}

bool rpg::Item::consumable() const
{
    return mConsumable;
}

const std::string& rpg::Item::description() const
{
    return mDescription;
}

i32 rpg::Item::hit() const
{
    return mHit;
}

const std::string& rpg::Item::iconName() const
{
    return mIconName;
}

i32 rpg::Item::ID() const
{
    return mID;
}

i32 rpg::Item::magicalDefense() const
{
    return mMagicalDefense;
}

const rpg::AudioFile& rpg::Item::menuSE() const
{
    return mMenuSE;
}

const std::string& rpg::Item::name() const
{
    return mName;
}

rpg::Item::Occasion rpg::Item::occasion() const
{
    return mOccasion;
}

i32 rpg::Item::parameterPoints() const
{
    return mParameterPoints;
}

rpg::Item::Parameter rpg::Item::parameterType() const
{
    return mParameterType;
}

i32 rpg::Item::physicalDefense() const
{
    return mPhysicalDefense;
}

i32 rpg::Item::price() const
{
    return mPrice;
}

i32 rpg::Item::recoverHP() const
{
    return mRecoverHP;
}

i32 rpg::Item::recoverHPRate() const
{
    return mRecoverHPRate;
}

i32 rpg::Item::recoverSP() const
{
    return mRecoverSP;
}

i32 rpg::Item::recoverSPRate() const
{
    return mRecoverSPRate;
}

rpg::Item::Scope rpg::Item::scope() const
{
    return mScope;
}

i32 rpg::Item::variance() const
{
    return mVariance;
}

bool rpg::Item::operator==(const Item& other) const
{
    return mID == other.mID;
}

bool rpg::Item::operator!=(const Item& other) const
{
    return !operator==(other);
}

bool rpg::Item::operator<(const Item& other) const
{
    return mID < other.mID;
}

void rpg::to_json(json& j, const Item& o)
{
    j = json{
        JSON_SET(UserAnimationID),
        JSON_SET(TargetAnimationID),
        JSON_SET(CommonEventID),
        JSON_SET(Consumable),
        JSON_SET(Description),
        JSON_SET(ElementSet),
        JSON_SET(Hit),
        JSON_SET(IconName),
        JSON_SET(ID),
        JSON_SET(MagicalDefense),
        JSON_SET(MenuSE),
        JSON_SET(MinusStateSet),
        JSON_SET(Name),
        JSON_SET(Occasion),
        JSON_SET(ParameterPoints),
        JSON_SET(ParameterType),
        JSON_SET(PhysicalDefense),
        JSON_SET(PlusStateSet),
        JSON_SET(Price),
        JSON_SET(RecoverHP),
        JSON_SET(RecoverHPRate),
        JSON_SET(RecoverSP),
        JSON_SET(RecoverSPRate),
        JSON_SET(Scope),
        JSON_SET(Variance),
    };
}

void rpg::from_json(const json& j, Item& o)
{
    JSON_GET(UserAnimationID);
    JSON_GET(TargetAnimationID);
    JSON_GET(CommonEventID);
    JSON_GET(Consumable);
    JSON_GET(Description);
    JSON_GET(ElementSet);
    JSON_GET(Hit);
    JSON_GET(IconName);
    JSON_GET(ID);
    JSON_GET(MagicalDefense),
    JSON_GET(MenuSE);
    JSON_GET(MinusStateSet);
    JSON_GET(Name);
    JSON_GET(Occasion);
    JSON_GET(ParameterPoints);
    JSON_GET(ParameterType);
    JSON_GET(PhysicalDefense);
    JSON_GET(PlusStateSet);
    JSON_GET(Price);
    JSON_GET(RecoverHP);
    JSON_GET(RecoverHPRate);
    JSON_GET(RecoverSP);
    JSON_GET(RecoverSPRate);
    JSON_GET(Scope);
    JSON_GET(Variance);
}
