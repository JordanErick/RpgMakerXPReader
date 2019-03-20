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
{
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
