#include "types/item.hpp"

Item::Item()
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

Item::Item(const Object& object)
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

i32 Item::userAnimationID() const
{
    return mUserAnimationID;
}

i32 Item::targetAnimationID() const
{
    return mTargetAnimationID;
}

i32 Item::commonEventID() const
{
    return mCommonEventID;
}

bool Item::consumable() const
{
    return mConsumable;
}

const std::string& Item::description() const
{
    return mDescription;
}

i32 Item::hit() const
{
    return mHit;
}

const std::string& Item::iconName() const
{
    return mIconName;
}

i32 Item::ID() const
{
    return mID;
}

i32 Item::magicalDefense() const
{
    return mMagicalDefense;
}

const AudioFile& Item::menuSE() const
{
    return mMenuSE;
}

const std::string& Item::name() const
{
    return mName;
}

Item::Occasion Item::occasion() const
{
    return mOccasion;
}

i32 Item::parameterPoints() const
{
    return mParameterPoints;
}

Item::Parameter Item::parameterType() const
{
    return mParameterType;
}

i32 Item::physicalDefense() const
{
    return mPhysicalDefense;
}

i32 Item::price() const
{
    return mPrice;
}

i32 Item::recoverHP() const
{
    return mRecoverHP;
}

i32 Item::recoverHPRate() const
{
    return mRecoverHPRate;
}

i32 Item::recoverSP() const
{
    return mRecoverSP;
}

i32 Item::recoverSPRate() const
{
    return mRecoverSPRate;
}

Item::Scope Item::scope() const
{
    return mScope;
}

i32 Item::variance() const
{
    return mVariance;
}

bool Item::operator==(const Item& other) const
{
    return mID == other.mID;
}

bool Item::operator!=(const Item& other) const
{
    return !operator==(other);
}

bool Item::operator<(const Item& other) const
{
    return mID < other.mID;
}

void to_json(json& j, const Item& o)
{
    j = json{
        {"user_animation_id", o.mUserAnimationID},
        {"target_animation_id", o.mTargetAnimationID},
        {"common_event_id", o.mCommonEventID},
        {"consumable", o.mConsumable},
        {"description", o.mDescription},
        {"element_set", o.mElementSet},
        {"hit", o.mHit},
        {"icon_name", o.mIconName},
        {"id", o.mID},
        {"magical_defense", o.mMagicalDefense},
        {"menu_se", o.mMenuSE},
        {"minus_state_set", o.mMinusStateSet},
        {"name", o.mName},
        {"occasion", o.mOccasion},
        {"parameter_points", o.mParameterPoints},
        {"parameter_type", o.mParameterType},
        {"physical_defense", o.mPhysicalDefense},
        {"plus_state_set", o.mPlusStateSet},
        {"price", o.mPrice},
        {"recover_hp", o.mRecoverHP},
        {"recover_hp_rate", o.mRecoverHPRate},
        {"recover_sp", o.mRecoverSP},
        {"recover_sp_rate", o.mRecoverSPRate},
        {"scope", o.mScope},
        {"variance", o.mVariance},
    };
}

void from_json(const json& j, Item& o)
{
    j.at("user_animation_id").get_to(o.mUserAnimationID);
    j.at("target_animation_id").get_to(o.mTargetAnimationID);
    j.at("common_event_id").get_to(o.mCommonEventID);
    j.at("consumable").get_to(o.mConsumable);
    j.at("description").get_to(o.mDescription);
    j.at("element_set").get_to(o.mElementSet);
    j.at("hit").get_to(o.mHit);
    j.at("icon_name").get_to(o.mIconName);
    j.at("id").get_to(o.mID);
    j.at("magical_defense").get_to(o.mMagicalDefense);
    j.at("menu_se").get_to(o.mMenuSE);
    j.at("minus_state_set").get_to(o.mMinusStateSet);
    j.at("name").get_to(o.mName);
    j.at("occasion").get_to(o.mOccasion);
    j.at("parameter_points").get_to(o.mParameterPoints);
    j.at("parameter_type").get_to(o.mParameterType);
    j.at("physical_defense").get_to(o.mPhysicalDefense);
    j.at("plus_state_set").get_to(o.mPlusStateSet);
    j.at("price").get_to(o.mPrice);
    j.at("recover_hp").get_to(o.mRecoverHP);
    j.at("recover_hp_rate").get_to(o.mRecoverHPRate);
    j.at("recover_sp").get_to(o.mRecoverSP);
    j.at("recover_sp_rate").get_to(o.mRecoverSPRate);
    j.at("scope").get_to(o.mScope);
    j.at("variance").get_to(o.mVariance);
}
