#include "common.hpp"

class Item
{
public:
    enum class Occasion : i32
    {
        Always,
        OnlyInBattle,
        OnlyFromMenu,
        Never,
    };

    enum class Parameter : i32
    {
        None,
        MaxHP,
        MaxSP,
        Str,
        Dex,
        Agi,
        Int,
    };

    enum class Scope : i32
    {
        None,
        OneEnemy,
        AllEnemies,
        OneAlly,
        AllAllies,
        OneDeadAlly,
        AllDeadAllies,
        User,
    };
                       Item();
                       Item(const Object& object);

    i32                userAnimationID() const;
    i32                targetAnimationID() const;
    i32                commonEventID() const;
    bool               consumable() const;
    const std::string& description() const;
    i32                hit() const;
    const std::string& iconName() const;
    i32                ID() const;
    i32                magicalDefense() const;
    const AudioFile&   menuSE() const;
    const std::string& name() const;
    Occasion           occasion() const;
    i32                parameterPoints() const;
    Parameter          parameterType() const;
    i32                physicalDefense() const;
    i32                price() const;
    i32                recoverHP() const;
    i32                recoverHPRate() const;
    i32                recoverSP() const;
    i32                recoverSPRate() const;
    Scope              scope() const;
    i32                variance() const;

    bool               operator==(const Item& other) const;
    bool               operator!=(const Item& other) const;
    bool               operator<(const Item& other) const;

private:
    i32                mUserAnimationID;
    i32                mTargetAnimationID;
    i32                mCommonEventID;
    bool               mConsumable;
    std::string        mDescription;
    std::vector<i32>   mElementSet;
    i32                mHit;
    std::string        mIconName;
    i32                mID;
    i32                mMagicalDefense;
    AudioFile          mMenuSE;
    std::vector<i32>   mMinusStateSet;
    std::string        mName;
    Occasion           mOccasion;
    i32                mParameterPoints;
    Parameter          mParameterType;
    i32                mPhysicalDefense;
    std::vector<i32>   mPlusStateSet;
    i32                mPrice;
    i32                mRecoverHP;
    i32                mRecoverHPRate;
    i32                mRecoverSP;
    i32                mRecoverSPRate;
    Scope              mScope;
    i32                mVariance;
};