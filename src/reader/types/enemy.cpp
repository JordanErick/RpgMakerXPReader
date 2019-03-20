#include "reader\types\enemy.hpp"

rpg::Enemy::Action::Action()
: mBasic{}
, mConditionHP{}
, mConditionLevel{}
, mConditionSwitchID{}
, mConditionTurnA{}
, mConditionTurnB{}
, mKind{}
, mRating{}
, mSkillID{}
{
}

rpg::Enemy::Action::Action(const Object& object)
: mBasic{}
, mConditionHP{}
, mConditionLevel{}
, mConditionSwitchID{}
, mConditionTurnA{}
, mConditionTurnB{}
, mKind{}
, mRating{}
, mSkillID{}
{
    if (object.className() != "RPG::Enemy::Action")
        throw std::runtime_error(fmt::format("Invalid class name: {}", object.className()));

    mBasic = static_cast<Basic>(*object["@basic"].as<i32>());
    mConditionHP = *object["@condition_hp"].as<i32>();
    mConditionLevel = *object["@condition_level"].as<i32>();
    mConditionSwitchID = *object["@condition_switch_id"].as<i32>();
    mConditionTurnA = *object["@condition_turn_a"].as<i32>();
    mConditionTurnB = *object["@condition_turn_b"].as<i32>();
    mKind = static_cast<Kind>(*object["@kind"].as<i32>());
    mRating = *object["@rating"].as<i32>();
    mSkillID = *object["@skill_id"].as<i32>();
}

rpg::Enemy::Action::Basic rpg::Enemy::Action::basic() const
{
    return mBasic;
}

i32 rpg::Enemy::Action::conditionHP() const
{
    return mConditionHP;
}

i32 rpg::Enemy::Action::conditionLevel() const
{
    return mConditionLevel;
}

i32 rpg::Enemy::Action::conditionSwitchID() const
{
    return mConditionSwitchID;
}

i32 rpg::Enemy::Action::conditionTurnA() const
{
    return mConditionTurnA;
}

i32 rpg::Enemy::Action::conditionTurnB() const
{
    return mConditionTurnB;
}

rpg::Enemy::Action::Kind rpg::Enemy::Action::kind() const
{
    return mKind;
}

i32 rpg::Enemy::Action::rating() const
{
    return mRating;
}

i32 rpg::Enemy::Action::skillID() const
{
    return mSkillID;
}

bool rpg::Enemy::Action::operator==(const Action& other) const
{
    return mBasic == other.mBasic
        && mConditionHP == other.mConditionHP
        && mConditionLevel == other.mConditionLevel
        && mConditionSwitchID == other.mConditionSwitchID
        && mConditionTurnA == other.mConditionTurnA
        && mConditionTurnB == other.mConditionTurnB
        && mKind == other.mKind
        && mRating == other.mRating
        && mSkillID == other.mSkillID;
}

bool rpg::Enemy::Action::operator!=(const Action& other) const
{
    return !operator==(other);
}

bool rpg::Enemy::Action::operator<(const Action& other) const
{
    return mRating < other.mRating;
}

void rpg::to_json(json& j, const Enemy::Action& o)
{
    j = json{
        JSON_SET(Basic),
        JSON_SET(ConditionHP),
        JSON_SET(ConditionLevel),
        JSON_SET(ConditionSwitchID),
        JSON_SET(ConditionTurnA),
        JSON_SET(ConditionTurnB),
        JSON_SET(Kind),
        JSON_SET(Rating),
        JSON_SET(SkillID)
    };
}

void rpg::from_json(const json& j, Enemy::Action& o)
{
    JSON_GET(Basic);
    JSON_GET(ConditionHP);
    JSON_GET(ConditionLevel);
    JSON_GET(ConditionSwitchID);
    JSON_GET(ConditionTurnA);
    JSON_GET(ConditionTurnB);
    JSON_GET(Kind);
    JSON_GET(Rating);
    JSON_GET(SkillID);
}

rpg::Enemy::Enemy()
: mActions{}
, mAgility{}
, mAttackerAnimation{}
, mTargetAnimation{}
, mArmorID{}
, mAttackPower{}
, mBattlerHue{}
, mBattlerName{}
, mDexterity{}
, mElementRanks{}
, mEvasion{}
, mExperience{}
, mGold{}
, mID{}
, mIntelligence{}
, mItemID{}
, mMaxHP{}
, mMaxSP{}
, mMagicDefense{}
, mName{}
, mPhysicalDefense{}
, mStateRanks{}
, mStrength{}
, mTreasureProbability{}
, mWeaponID{}
{
}

rpg::Enemy::Enemy(const Object& object)
: mActions{}
, mAgility{}
, mAttackerAnimation{}
, mTargetAnimation{}
, mArmorID{}
, mAttackPower{}
, mBattlerHue{}
, mBattlerName{}
, mDexterity{}
, mElementRanks{}
, mEvasion{}
, mExperience{}
, mGold{}
, mID{}
, mIntelligence{}
, mItemID{}
, mMaxHP{}
, mMaxSP{}
, mMagicDefense{}
, mName{}
, mPhysicalDefense{}
, mStateRanks{}
, mStrength{}
, mTreasureProbability{}
, mWeaponID{}
{
    if (object.className() != "RPG::Enemy")
        throw std::runtime_error(fmt::format("Invalid class name: {}", object.className()));

    auto* actions = object["@actions"].as<Array>();
    for (auto& element : *actions)
    {
        if (element.type() != Type::Object)
            throw std::runtime_error(fmt::format("Invalid any type: {}", element.type()));

        if (element.as<Object>()->className() != "RPG::Enemy::Action")
            throw std::runtime_error(fmt::format("Invalid class name: {}", element.as<Object>()->className()));

        mActions.push_back(Action{ *element.as<Object>() });
    }

    mAgility = *object["@agi"].as<i32>();
    mAttackerAnimation = *object["@animation1_id"].as<i32>();
    mTargetAnimation = *object["@animation2_id"].as<i32>();
    mArmorID = *object["@armor_id"].as<i32>();
    mAttackPower = *object["@atk"].as<i32>();
    mBattlerHue = *object["@battler_hue"].as<i32>();
    mBattlerName = *object["@battler_name"].as<std::string>();
    mDexterity = *object["@dex"].as<i32>();
    mElementRanks = *object["@element_ranks"].as<Table>();
    mEvasion = *object["@eva"].as<i32>();
    mExperience = *object["@exp"].as<i32>();
    mGold = *object["@gold"].as<i32>();
    mID = *object["@id"].as<i32>();
    mIntelligence = *object["@int"].as<i32>();
    mItemID = *object["@item_id"].as<i32>();
    mMaxHP = *object["@maxhp"].as<i32>();
    mMaxSP = *object["@maxsp"].as<i32>();
    mMagicDefense = *object["@mdef"].as<i32>();
    mName = *object["@name"].as<std::string>();
    mPhysicalDefense = *object["@pdef"].as<i32>();
    mStateRanks = *object["@state_ranks"].as<Table>();
    mStrength = *object["@str"].as<i32>();
    mTreasureProbability = *object["@treasure_prob"].as<i32>();
    mWeaponID = *object["@weapon_id"].as<i32>();
}

const std::vector<rpg::Enemy::Action>& rpg::Enemy::actions() const
{
    return mActions;
}

i32 rpg::Enemy::agility() const
{
    return mAgility;
}

i32 rpg::Enemy::attackerAnimation() const
{
    return mAttackerAnimation;
}

i32 rpg::Enemy::targetAnimation() const
{
    return mTargetAnimation;
}

i32 rpg::Enemy::armorID() const
{
    return mArmorID;
}

i32 rpg::Enemy::attackPower() const
{
    return mAttackPower;
}

i32 rpg::Enemy::battlerHue() const
{
    return mBattlerHue;
}

const std::string& rpg::Enemy::battlerName() const
{
    return mBattlerName;
}

i32 rpg::Enemy::dexterity() const
{
    return mDexterity;
}

rpg::Table rpg::Enemy::elementRanks() const
{
    return mElementRanks;
}

i32 rpg::Enemy::evasion() const
{
    return mEvasion;
}

i32 rpg::Enemy::experience() const
{
    return mExperience;
}

i32 rpg::Enemy::gold() const
{
    return mGold;
}

i32 rpg::Enemy::ID() const
{
    return mID;
}

i32 rpg::Enemy::intelligence() const
{
    return mIntelligence;
}

i32 rpg::Enemy::itemID() const
{
    return mItemID;
}

i32 rpg::Enemy::maxHP() const
{
    return mMaxHP;
}

i32 rpg::Enemy::maxSP() const
{
    return mMaxSP;
}

i32 rpg::Enemy::magicDefense() const
{
    return mMagicDefense;
}

const std::string& rpg::Enemy::name() const
{
    return mName;
}

i32 rpg::Enemy::physicalDefense() const
{
    return mPhysicalDefense;
}

const rpg::Table& rpg::Enemy::stateRanks() const
{
    return mStateRanks;
}

i32 rpg::Enemy::strength() const
{
    return mStrength;
}

i32 rpg::Enemy::treasureProbability() const
{
    return mTreasureProbability;
}

i32 rpg::Enemy::weaponID() const
{
    return mWeaponID;
}

bool rpg::Enemy::operator==(const Enemy& other) const
{
    return mID == other.mID;
}

bool rpg::Enemy::operator!=(const Enemy& other) const
{
    return !operator==(other);
}

bool rpg::Enemy::operator<(const Enemy & other) const
{
    return mID < other.mID;
}

void rpg::to_json(json& j, const Enemy& o)
{
    j = json{
        JSON_SET(Actions),
        JSON_SET(Agility),
        JSON_SET(AttackerAnimation),
        JSON_SET(TargetAnimation),
        JSON_SET(ArmorID),
        JSON_SET(AttackPower),
        JSON_SET(BattlerHue),
        JSON_SET(BattlerName),
        JSON_SET(Dexterity),
        JSON_SET(ElementRanks),
        JSON_SET(Evasion),
        JSON_SET(Experience),
        JSON_SET(Gold),
        JSON_SET(ID),
        JSON_SET(Intelligence),
        JSON_SET(ItemID),
        JSON_SET(MaxHP),
        JSON_SET(MaxSP),
        JSON_SET(MagicDefense),
        JSON_SET(Name),
        JSON_SET(PhysicalDefense),
        JSON_SET(StateRanks),
        JSON_SET(Strength),
        JSON_SET(TreasureProbability),
        JSON_SET(WeaponID)
    };
}

void rpg::from_json(const json& j, Enemy& o)
{
    JSON_GET(Actions);
    JSON_GET(Agility);
    JSON_GET(AttackerAnimation);
    JSON_GET(TargetAnimation);
    JSON_GET(ArmorID);
    JSON_GET(AttackPower);
    JSON_GET(BattlerHue);
    JSON_GET(BattlerName);
    JSON_GET(Dexterity);
    JSON_GET(ElementRanks);
    JSON_GET(Evasion);
    JSON_GET(Experience);
    JSON_GET(Gold);
    JSON_GET(ID);
    JSON_GET(Intelligence);
    JSON_GET(ItemID);
    JSON_GET(MaxHP);
    JSON_GET(MaxSP);
    JSON_GET(MagicDefense);
    JSON_GET(Name);
    JSON_GET(PhysicalDefense);
    JSON_GET(StateRanks);
    JSON_GET(Strength);
    JSON_GET(TreasureProbability);
    JSON_GET(WeaponID);
}
