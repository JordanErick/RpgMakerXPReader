#include "reader/types/state.hpp"

State::State()
: mAgilityPercentage{}
, mAnimationID{}
, mAttackPercentage{}
, mAutoReleaseProbability{}
, mBattleOnly{}
, mCantEvade{}
, mCantGetExperience{}
, mDexterityPercentage{}
, mEvasionCorrection{}
, mGuardElementSet{}
, mHitPercentage{}
, mHoldTurn{}
, mID{}
, mIntelligencePercentage{}
, mMaxHPPercentage{}
, mMaxSPPercentage{}
, mMagicDefensePercentage{}
, mMinusStateSet{}
, mName{}
, mNonresistance{}
, mPhysicalDefensePercentage{}
, mPlusStateSet{}
, mRating{}
, mRestriction{}
, mShockReleaseProbability{}
, mSlipDamage{}
, mStrengthPercentage{}
, mZeroHP{}
{
}

State::State(const Object& object)
: mAgilityPercentage{}
, mAnimationID{}
, mAttackPercentage{}
, mAutoReleaseProbability{}
, mBattleOnly{}
, mCantEvade{}
, mCantGetExperience{}
, mDexterityPercentage{}
, mEvasionCorrection{}
, mGuardElementSet{}
, mHitPercentage{}
, mHoldTurn{}
, mID{}
, mIntelligencePercentage{}
, mMaxHPPercentage{}
, mMaxSPPercentage{}
, mMagicDefensePercentage{}
, mMinusStateSet{}
, mName{}
, mNonresistance{}
, mPhysicalDefensePercentage{}
, mPlusStateSet{}
, mRating{}
, mRestriction{}
, mShockReleaseProbability{}
, mSlipDamage{}
, mStrengthPercentage{}
, mZeroHP{}
{
    if (object.className() != "RPG::State")
        throw std::runtime_error(fmt::format("Invalid class name: {}", object.className()));

    mAgilityPercentage = *object["@agi_rate"].as<i32>();
    mAnimationID = *object["@animation_id"].as<i32>();
    mAttackPercentage = *object["@atk_rate"].as<i32>();
    mAutoReleaseProbability = *object["@auto_release_prob"].as<i32>();
    mBattleOnly = *object["@battle_only"].as<bool>();
    mCantEvade = *object["@cant_evade"].as<bool>();
    mCantGetExperience = *object["@cant_get_exp"].as<bool>();
    mDexterityPercentage = *object["@dex_rate"].as<i32>();
    mEvasionCorrection = *object["@eva"].as<i32>();

    auto* guardElementSet = object["@guard_element_set"].as<Array>();
    for (const auto& e : *guardElementSet)
        mGuardElementSet.push_back(*e.as<i32>());

    mHitPercentage = *object["@hit_rate"].as<i32>();
    mHoldTurn = *object["@hold_turn"].as<i32>();
    mID = *object["@id"].as<i32>();
    mIntelligencePercentage = *object["@int_rate"].as<i32>();
    mMaxHPPercentage = *object["@maxhp_rate"].as<i32>();
    mMaxSPPercentage = *object["@maxsp_rate"].as<i32>();
    mMagicDefensePercentage = *object["@mdef_rate"].as<i32>();

    auto* minusStateSet = object["@minus_state_set"].as<Array>();
    for (const auto& e : *minusStateSet)
        mMinusStateSet.push_back(*e.as<i32>());

    mName = *object["@name"].as<std::string>();
    mNonresistance = *object["@nonresistance"].as<bool>();
    mPhysicalDefensePercentage = *object["@pdef_rate"].as<i32>();

    auto* plusStateSet = object["@plus_state_set"].as<Array>();
    for (const auto& e : *plusStateSet)
        mPlusStateSet.push_back(*e.as<i32>());

    mRating = *object["@rating"].as<i32>();
    mRestriction = static_cast<Restriction>(*object["@restriction"].as<i32>());
    mShockReleaseProbability = *object["@shock_release_prob"].as<i32>();
    mSlipDamage = *object["@slip_damage"].as<bool>();
    mStrengthPercentage = *object["@str_rate"].as<i32>();
    mZeroHP = *object["@zero_hp"].as<bool>();
}

i32 State::agilityPercentage() const
{
    return mAgilityPercentage;
}

i32 State::animationID() const
{
    return mAnimationID;
}

i32 State::attackPercentage() const
{
    return mAttackPercentage;
}

i32 State::autoReleaseProbability() const
{
    return mAutoReleaseProbability;
}

bool State::battleOnly() const
{
    return mBattleOnly;
}

bool State::cantEvade() const
{
    return mCantEvade;
}

bool State::cantGetExperience() const
{
    return mCantGetExperience;
}

i32 State::dexterityPercentage() const
{
    return mDexterityPercentage;
}

i32 State::evasionCorrection() const
{
    return mEvasionCorrection;
}

const std::vector<i32>& State::guardElementSet() const
{
    return mGuardElementSet;
}

i32 State::hitPercentage() const
{
    return mHitPercentage;
}

i32 State::holdTurn() const
{
    return mHoldTurn;
}

i32 State::ID() const
{
    return mID;
}

i32 State::intelligencePercentage() const
{
    return mIntelligencePercentage;
}

i32 State::maxHPPercentage() const
{
    return mMaxHPPercentage;
}

i32 State::maxSPPercentage() const
{
    return mMaxSPPercentage;
}

i32 State::magicDefensePercentage() const
{
    return mMagicDefensePercentage;
}

const std::vector<i32>& State::minusStateSet() const
{
    return mMinusStateSet;
}

const std::string& State::name() const
{
    return mName;
}

bool State::nonresistance() const
{
    return mNonresistance;
}

i32 State::physicalDefensePercentage() const
{
    return mPhysicalDefensePercentage;
}

const std::vector<i32>& State::plusStateSet() const
{
    return mPlusStateSet;
}

i32 State::rating() const
{
    return mRating;
}

State::Restriction State::restriction() const
{
    return mRestriction;
}

i32 State::shockReleaseProbability() const
{
    return mShockReleaseProbability;
}

bool State::slipDamage() const
{
    return mSlipDamage;
}

i32 State::strengthPercentage() const
{
    return mStrengthPercentage;
}

bool State::zeroHP() const
{
    return mZeroHP;
}

bool State::operator==(const State& other) const
{
    return mID == other.mID;
}

bool State::operator!=(const State& other) const
{
    return !operator==(other);
}

bool State::operator<(const State& other) const
{
    return mID < other.mID;
}

void to_json(json& j, const State& o)
{
    j = json{
        JSON_SET(AgilityPercentage),
        JSON_SET(AttackPercentage),
        JSON_SET(AutoReleaseProbability),
        JSON_SET(BattleOnly),
        JSON_SET(CantEvade),
        JSON_SET(CantGetExperience),
        JSON_SET(DexterityPercentage),
        JSON_SET(EvasionCorrection),
        JSON_SET(GuardElementSet),
        JSON_SET(HitPercentage),
        JSON_SET(HoldTurn),
        JSON_SET(ID),
        JSON_SET(IntelligencePercentage),
        JSON_SET(MaxHPPercentage),
        JSON_SET(MaxSPPercentage),
        JSON_SET(MagicDefensePercentage),
        JSON_SET(MinusStateSet),
        JSON_SET(Name),
        JSON_SET(Nonresistance),
        JSON_SET(PhysicalDefensePercentage),
        JSON_SET(PlusStateSet),
        JSON_SET(Rating),
        JSON_SET(Restriction),
        JSON_SET(ShockReleaseProbability),
        JSON_SET(SlipDamage),
        JSON_SET(StrengthPercentage),
        JSON_SET(ZeroHP)
    };
}

void from_json(const json& j, State& o)
{
    JSON_GET(AgilityPercentage);
    JSON_GET(AttackPercentage);
    JSON_GET(AutoReleaseProbability);
    JSON_GET(BattleOnly);
    JSON_GET(CantEvade);
    JSON_GET(CantGetExperience);
    JSON_GET(DexterityPercentage);
    JSON_GET(EvasionCorrection);
    JSON_GET(GuardElementSet);
    JSON_GET(HitPercentage);
    JSON_GET(HoldTurn);
    JSON_GET(ID);
    JSON_GET(IntelligencePercentage);
    JSON_GET(MaxHPPercentage);
    JSON_GET(MaxSPPercentage);
    JSON_GET(MagicDefensePercentage);
    JSON_GET(MinusStateSet);
    JSON_GET(Name);
    JSON_GET(Nonresistance);
    JSON_GET(PhysicalDefensePercentage);
    JSON_GET(PlusStateSet);
    JSON_GET(Rating);
    JSON_GET(Restriction);
    JSON_GET(ShockReleaseProbability);
    JSON_GET(SlipDamage);
    JSON_GET(StrengthPercentage);
    JSON_GET(ZeroHP);
}
