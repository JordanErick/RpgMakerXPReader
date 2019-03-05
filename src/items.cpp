#include "items.hpp"

Item::Item(const Any* any)
: mAnimation1ID{}
, mAnimation2ID{}
, mCommonEventID{}
, mConsumable{}
, mDescription{}
, mHit{}
, mIconName{}
, mID{}
, mMDef{}
, mMenuSE{}
, mName{}
, mOccasion{}
, mParameterPoints{}
, mParameterType{}
, mPDef{}
, mPrice{}
, mRecoverHP{}
, mRecoverHPRate{}
, mRecoverSP{}
, mRecoverSPRate{}
, mScope{}
, mVariance{}
{
    if (any->type() != Type::Object)
        throw std::runtime_error(fmt::format("Invalid any type: {}", any->type()));

    if (any->as<Object>()->className() != "RPG::Item")
        throw std::runtime_error(fmt::format("Invalid class name: {}", any->as<Object>()->className()));

    auto* object = any->as<Object>();

    mAnimation1ID = *(*object)["@animation1_id"].as<i32>();
    mAnimation2ID = *(*object)["@animation2_id"].as<i32>();
    mCommonEventID = *(*object)["@common_event_id"].as<i32>();
    mConsumable = *(*object)["@consumable"].as<bool>();
    mDescription = *(*object)["@description"].as<std::string>();
    mHit = *(*object)["@hit"].as<i32>();
    mIconName = *(*object)["@icon_name"].as<std::string>();
    mID = *(*object)["@id"].as<i32>();
    mMDef = *(*object)["@mdef_f"].as<i32>();
    mMenuSE.fromAny(&(*object)["@menu_se"]);
    mName = *(*object)["@name"].as<std::string>();
    mOccasion = *(*object)["@occasion"].as<i32>();
    mParameterPoints = *(*object)["@parameter_points"].as<i32>();
    mParameterType = *(*object)["@parameter_type"].as<i32>();
    mPDef = *(*object)["@pdef_f"].as<i32>();
    mPrice = *(*object)["@price"].as<i32>();
    mRecoverHP = *(*object)["@recover_hp"].as<i32>();
    mRecoverHPRate = *(*object)["@recover_hp_rate"].as<i32>();
    mRecoverSP = *(*object)["@recover_sp"].as<i32>();
    mRecoverSPRate = *(*object)["@recover_sp_rate"].as<i32>();
    mScope = *(*object)["@scope"].as<i32>();
    mVariance = *(*object)["@variance"].as<i32>();
}

i32 Item::animation1ID() const
{
    return mAnimation1ID;
}

i32 Item::animation2ID() const
{
    return mAnimation2ID;
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

i32 Item::mDef() const
{
    return mMDef;
}

const AudioFile& Item::menuSE() const
{
    return mMenuSE;
}

const std::string& Item::name() const
{
    return mName;
}

i32 Item::occasion() const
{
    return mOccasion;
}

i32 Item::parameterPoints() const
{
    return mParameterPoints;
}

i32 Item::parameterType() const
{
    return mParameterType;
}

i32 Item::pDef() const
{
    return mPDef;
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

i32 Item::scope() const
{
    return mScope;
}

i32 Item::variance() const
{
    return mVariance;
}

bool Item::operator==(const Item & other) const
{
    return mID == other.mID;
}

bool Item::operator!=(const Item & other) const
{
    return !operator==(other);
}

bool Item::operator<(const Item & other) const
{
    return mID < other.mID;
}

Items::Items(const Any* any)
: mItems{}
{
    if (any->type() != Type::Array)
        throw std::runtime_error(fmt::format("Invalid any type: {}", any->type()));

    auto* array = any->as<Array>();

    // Skip first element which seems to be equal to null all the time
    for (size_t i = 1; i < array->size(); i++)
    {
        const auto& element = array->at(i);

        if (element.type() != Type::Object)
            throw std::runtime_error(fmt::format("Invalid any type: {}", any->type()));

        if (element.as<Object>()->className() != "RPG::Item")
            throw std::runtime_error(fmt::format("Invalid class name: {}", any->as<Object>()->className()));

        mItems.push_back(Item{ &element });
    }
}

Item& Items::operator[](size_t index)
{
    return mItems[index];
}

std::vector<Item>::iterator Items::begin()
{
    return mItems.begin();
}

std::vector<Item>::const_iterator Items::begin() const
{
    return mItems.begin();
}

std::vector<Item>::iterator Items::end()
{
    return mItems.end();
}

std::vector<Item>::const_iterator Items::end() const
{
    return mItems.end();
}

bool Items::operator==(const Items& other) const
{
    return mItems == other.mItems;
}

bool Items::operator!=(const Items& other) const
{
    return !operator==(other);
}

bool Items::operator<(const Items & other) const
{
    return mItems < other.mItems;
}

size_t Items::size()
{
    return mItems.size();
}
