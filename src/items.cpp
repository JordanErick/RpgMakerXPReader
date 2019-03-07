#include "items.hpp"

Item::Item(const Any* any)
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
    if (any->type() != Type::Object)
        throw std::runtime_error(fmt::format("Invalid any type: {}", any->type()));

    if (any->as<Object>()->className() != "RPG::Item")
        throw std::runtime_error(fmt::format("Invalid class name: {}", any->as<Object>()->className()));

    auto* object = any->as<Object>();

    mUserAnimationID = *(*object)["@animation1_id"].as<i32>();
    mTargetAnimationID = *(*object)["@animation2_id"].as<i32>();
    mCommonEventID = *(*object)["@common_event_id"].as<i32>();
    mConsumable = *(*object)["@consumable"].as<bool>();
    mDescription = *(*object)["@description"].as<std::string>();

    auto* elementSet = (*object)["@element_set"].as<Array>();
    for (const auto& e : *elementSet)
        mElementSet.push_back(*e.as<i32>());

    mHit = *(*object)["@hit"].as<i32>();
    mIconName = *(*object)["@icon_name"].as<std::string>();
    mID = *(*object)["@id"].as<i32>();
    mMagicalDefense = *(*object)["@mdef_f"].as<i32>();
    mMenuSE.fromAny(&(*object)["@menu_se"]);

    auto* minusStateSet = (*object)["@minus_state_set"].as<Array>();
    for (const auto& e : *minusStateSet)
        mMinusStateSet.push_back(*e.as<i32>());

    mName = *(*object)["@name"].as<std::string>();
    mOccasion = static_cast<Occasion>(*(*object)["@occasion"].as<i32>());
    mParameterPoints = *(*object)["@parameter_points"].as<i32>();
    mParameterType = static_cast<Parameter>(*(*object)["@parameter_type"].as<i32>());
    mPhysicalDefense = *(*object)["@pdef_f"].as<i32>();

    auto* plusStateSet = (*object)["@plus_state_set"].as<Array>();
    for (const auto& e : *plusStateSet)
        mPlusStateSet.push_back(*e.as<i32>());

    mPrice = *(*object)["@price"].as<i32>();
    mRecoverHP = *(*object)["@recover_hp"].as<i32>();
    mRecoverHPRate = *(*object)["@recover_hp_rate"].as<i32>();
    mRecoverSP = *(*object)["@recover_sp"].as<i32>();
    mRecoverSPRate = *(*object)["@recover_sp_rate"].as<i32>();
    mScope = static_cast<Scope>(*(*object)["@scope"].as<i32>());
    mVariance = *(*object)["@variance"].as<i32>();
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