#include "common.hpp"

class Item
{
public:
                       Item(const Any* any);

    i32                animation1ID() const;
    i32                animation2ID() const;
    i32                commonEventID() const;
    bool               consumable() const;
    const std::string& description() const;
    i32                hit() const;
    const std::string& iconName() const;
    i32                ID() const;
    i32                mDef() const;
    const AudioFile&   menuSE() const;
    const std::string& name() const;
    i32                occasion() const;
    i32                parameterPoints() const;
    i32                parameterType() const;
    i32                pDef() const;
    i32                price() const;
    i32                recoverHP() const;
    i32                recoverHPRate() const;
    i32                recoverSP() const;
    i32                recoverSPRate() const;
    i32                scope() const;
    i32                variance() const;

    bool               operator==(const Item& other) const;
    bool               operator!=(const Item& other) const;
    bool               operator<(const Item& other) const;

private:
    i32                mAnimation1ID;
    i32                mAnimation2ID;
    i32                mCommonEventID;
    bool               mConsumable;
    std::string        mDescription;
    i32                mHit;
    std::string        mIconName;
    i32                mID;
    i32                mMDef;
    AudioFile          mMenuSE;
    std::string        mName;
    i32                mOccasion;
    i32                mParameterPoints;
    i32                mParameterType;
    i32                mPDef;
    i32                mPrice;
    i32                mRecoverHP;
    i32                mRecoverHPRate;
    i32                mRecoverSP;
    i32                mRecoverSPRate;
    i32                mScope;
    i32                mVariance;
};

class Items
{
public:
                                      Items(const Any* any);

    Item&                             operator[](size_t index);

    std::vector<Item>::iterator       begin();
    std::vector<Item>::const_iterator begin() const;

    std::vector<Item>::iterator       end();
    std::vector<Item>::const_iterator end() const;

    bool                              operator==(const Items& other) const;
    bool                              operator!=(const Items& other) const;
    bool                              operator<(const Items& other) const;

    size_t                            size();

private:
    std::vector<Item>                 mItems;
};