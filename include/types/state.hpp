#include "common.hpp"

class State
{
public:
    enum class Restriction
    {
        None,
        CantUseMagic,
        AlwaysAttackEnemies,
        AlwaysAttackAllies,
        CantMove,
    };

                            State();
                            State(const Object& object);

    i32                     agilityPercentage() const;
    i32                     animationID() const;
    i32                     attackPercentage() const;
    i32                     autoReleaseProbability() const;
    bool                    battleOnly() const;
    bool                    cantEvade() const;
    bool                    cantGetExperience() const;
    i32                     dexterityPercentage() const;
    i32                     evasionCorrection() const;
    const std::vector<i32>& guardElementSet() const;
    i32                     hitPercentage() const;
    i32                     holdTurn() const;
    i32                     ID() const;
    i32                     intelligencePercentage() const;
    i32                     maxHPPercentage() const;
    i32                     maxSPPercentage() const;
    i32                     magicDefensePercentage() const;
    const std::vector<i32>& minusStateSet() const;
    const std::string&      name() const;
    bool                    nonresistance() const;
    i32                     physicalDefensePercentage() const;
    const std::vector<i32>& plusStateSet() const;
    i32                     rating() const;
    Restriction             restriction() const;
    i32                     shockReleaseProbability() const;
    bool                    slipDamage() const;
    i32                     strengthPercentage() const;
    bool                    zeroHP() const;

    bool                    operator==(const State& other) const;
    bool                    operator!=(const State& other) const;
    bool                    operator<(const State& other) const;
private:
    i32                     mAgilityPercentage;
    i32                     mAnimationID;
    i32                     mAttackPercentage;
    i32                     mAutoReleaseProbability;
    bool                    mBattleOnly;
    bool                    mCantEvade;
    bool                    mCantGetExperience;
    i32                     mDexterityPercentage;
    i32                     mEvasionCorrection;
    std::vector<i32>        mGuardElementSet;
    i32                     mHitPercentage;
    i32                     mHoldTurn;
    i32                     mID;
    i32                     mIntelligencePercentage;
    i32                     mMaxHPPercentage;
    i32                     mMaxSPPercentage;
    i32                     mMagicDefensePercentage;
    std::vector<i32>        mMinusStateSet;
    std::string             mName;
    bool                    mNonresistance;
    i32                     mPhysicalDefensePercentage;
    std::vector<i32>        mPlusStateSet;
    i32                     mRating;
    Restriction             mRestriction;
    i32                     mShockReleaseProbability;
    bool                    mSlipDamage;
    i32                     mStrengthPercentage;
    bool                    mZeroHP;

    friend void             to_json(json& j, const State& o);
    friend void             from_json(const json& j, State& o);
};

void to_json(json& j, const State& o);
void from_json(const json& j, State& o);