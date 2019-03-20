#pragma once

#include "../object.hpp"
#include "table.hpp"

namespace rpg
{
    class Enemy
    {
    public:
        class Action
        {
        public:
            enum class Kind : i32
            {
                Basic,
                Skill,
            };

            enum class Basic : i32
            {
                Attack, 
                Defend, 
                Escape, 
                DoNothing,
            };

                        Action();
                        Action(const Object& object);

            Basic       basic() const;
            i32         conditionHP() const;
            i32         conditionLevel() const;
            i32         conditionSwitchID() const;
            i32         conditionTurnA() const;
            i32         conditionTurnB() const;
            Kind        kind() const;
            i32         rating() const;
            i32         skillID() const;

            bool        operator==(const Action& other) const;
            bool        operator!=(const Action& other) const;
            bool        operator<(const Action& other) const;
        private:
            Basic       mBasic;
            i32         mConditionHP;
            i32         mConditionLevel;
            i32         mConditionSwitchID;
            i32         mConditionTurnA;
            i32         mConditionTurnB;
            Kind        mKind;
            i32         mRating;
            i32         mSkillID;

            friend void to_json(json& j, const Action& o);
            friend void from_json(const json& j, Action& o);
        };

                                   Enemy();
                                   Enemy(const Object& object);

        const std::vector<Action>& actions() const;
        i32                        agility() const;
        i32                        attackerAnimation() const;
        i32                        targetAnimation() const;
        i32                        armorID() const;
        i32                        attackPower() const;
        i32                        battlerHue() const;
        const std::string&         battlerName() const;
        i32                        dexterity() const;
        Table                      elementRanks() const;
        i32                        evasion() const;
        i32                        experience() const;
        i32                        gold() const;
        i32                        ID() const;
        i32                        intelligence() const;
        i32                        itemID() const;
        i32                        maxHP() const;
        i32                        maxSP() const;
        i32                        magicDefense() const;
        const std::string&         name() const;
        i32                        physicalDefense() const;
        const Table&               stateRanks() const;
        i32                        strength() const;
        i32                        treasureProbability() const;
        i32                        weaponID() const;

        bool                       operator==(const Enemy& other) const;
        bool                       operator!=(const Enemy& other) const;
        bool                       operator<(const Enemy& other) const;
    private:
        std::vector<Action>        mActions;
        i32                        mAgility;
        i32                        mAttackerAnimation;
        i32                        mTargetAnimation;
        i32                        mArmorID;
        i32                        mAttackPower;
        i32                        mBattlerHue;
        std::string                mBattlerName;
        i32                        mDexterity;
        Table                      mElementRanks;
        i32                        mEvasion;
        i32                        mExperience;
        i32                        mGold;
        i32                        mID;
        i32                        mIntelligence;
        i32                        mItemID;
        i32                        mMaxHP;
        i32                        mMaxSP;
        i32                        mMagicDefense;
        std::string                mName;
        i32                        mPhysicalDefense;
        Table                      mStateRanks;
        i32                        mStrength;
        i32                        mTreasureProbability;
        i32                        mWeaponID;

        friend void                to_json(json& j, const Enemy& o);
        friend void                from_json(const json& j, Enemy& o);
    };

    void to_json(json& j, const Enemy::Action& o);
    void from_json(const json& j, Enemy::Action& o);

    void to_json(json& j, const Enemy& o);
    void from_json(const json& j, Enemy& o);
}