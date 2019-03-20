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
    private:
    };

    void to_json(json& j, const Enemy::Action& o);
    void from_json(const json& j, Enemy::Action& o);
}