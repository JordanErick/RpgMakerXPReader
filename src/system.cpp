#include "system.hpp"

System::System(const Any* any)
: mActorCollapseSE{}
, mBattleBGM{}
, mBattleEndME{}
, mBattleStartSE{}
, mBattleTransition{}
, mBattlebackName{}
, mBattlerHue{}
, mBattlerName{}
, mBuzzerSE{}
, mCancelSE{}
, mCursorSE{}
, mDecisionSE{}
, mEditMapID{}
, mElements{}
, mEnemyCollapseSE{}
, mEquipSE{}
, mEscapeSE{}
, mGameoverME{}
, mGameoverName{}
, mLoadSE{}
, mMagicNumber{}
, mPartyMembers{}
, mSaveSE{}
, mShopSE{}
, mStartMapID{}
, mStartX{}
, mStartY{}
, mSwitches{}
, mTestTroopID{}
, mTitleBGM{}
, mTitleName{}
, mVariables{}
, mWindowskinName{}
, mWords{}
{
    if (any->type() != Type::Object)
        throw std::runtime_error(fmt::format("Invalid any type: {}", any->type()));

    if (any->as<Object>()->className() != "RPG::System")
        throw std::runtime_error(fmt::format("Invalid class name: {}", any->as<Object>()->className()));

    auto* object = any->as<Object>();
    mActorCollapseSE.fromAny(&(*object)["@actor_collapse_se"]);
    mBattleBGM.fromAny(&(*object)["@battle_bgm"]);
    mBattleEndME.fromAny(&(*object)["@battle_end_me"]);
    mBattleStartSE.fromAny(&(*object)["@battle_start_se"]);
    mBattleTransition = *(*object)["@battle_transition"].as<std::string>();
    mBattlebackName = *(*object)["@battleback_name"].as<std::string>();
    mBattlerHue = *(*object)["@battler_hue"].as<i32>();
    mBattlerName = *(*object)["@battler_name"].as<std::string>();
    mBuzzerSE.fromAny(&(*object)["@buzzer_se"]);
    mCancelSE.fromAny(&(*object)["@cancel_se"]);
    mCursorSE.fromAny(&(*object)["@cursor_se"]);
    mDecisionSE.fromAny(&(*object)["@decision_se"]);
    mEditMapID = *(*object)["@edit_map_id"].as<i32>();

    auto* elements = (*object)["@elements"].as<Array>();
    for (const auto& e : *elements)
        mElements.push_back(*e.as<std::string>());

    mEnemyCollapseSE.fromAny(&(*object)["@enemy_collapse_se"]);
    mEquipSE.fromAny(&(*object)["@equip_se"]);
    mEscapeSE.fromAny(&(*object)["@escape_se"]);
    mGameoverME.fromAny(&(*object)["@gameover_me"]);
    mGameoverName = *(*object)["@gameover_name"].as<std::string>();
    mLoadSE.fromAny(&(*object)["@load_se"]);
    mMagicNumber = *(*object)["@magic_number"].as<i32>();

    auto* partyMembers = (*object)["@party_members"].as<Array>();
    for (const auto& e : *partyMembers)
        mPartyMembers.push_back(*e.as<i32>());

    mSaveSE.fromAny(&(*object)["@save_se"]);
    mShopSE.fromAny(&(*object)["@shop_se"]);
    mStartMapID = *(*object)["@start_map_id"].as<i32>();
    mStartX = *(*object)["@start_x"].as<i32>();
    mStartY = *(*object)["@start_y"].as<i32>();

    auto* switches = (*object)["@switches"].as<Array>();
    // Avoid first element which is always a nil
    for(size_t i = 1; i < switches->size(); i++)
        mSwitches.push_back(*(*switches)[i].as<std::string>());

    mTestTroopID = *(*object)["@test_troop_id"].as<i32>();
    mTitleBGM.fromAny(&(*object)["@title_bgm"]);
    mTitleName = *(*object)["@title_name"].as<std::string>();

    auto* variables = (*object)["@variables"].as<Array>();
    // Avoid first element which is always a nil
    for (size_t i = 1; i < variables->size(); i++)
        mVariables.push_back(*(*variables)[i].as<std::string>());

    mWindowskinName = *(*object)["@windowskin_name"].as<std::string>();

    auto* words = (*object)["@words"].as<Object>();
    for (const auto& e : *words)
        mWords[e.first.substr(1)] = *e.second.as<std::string>();
}

const AudioFile& System::actorCollapseSE() const
{
    return mActorCollapseSE;
}

const AudioFile& System::battleBGM() const
{
    return mBattleBGM;
}

const AudioFile& System::battleEndME() const
{
    return mBattleEndME;
}

const AudioFile& System::battleStartSE() const
{
    return mBattleStartSE;
}

const std::string& System::battleTransition() const
{
    return mBattleTransition;
}

const std::string& System::battlebackName() const
{
    return mBattlebackName;
}

i32 System::battlerHue() const
{
    return mBattlerHue;
}

const std::string& System::battlerName() const
{
    return mBattlerName;
}

const AudioFile& System::buzzerSE() const
{
    return mBuzzerSE;
}

const AudioFile& System::cancelSE() const
{
    return mCancelSE;
}

const AudioFile& System::cursorSE() const
{
    return mCursorSE;
}

const AudioFile& System::decisionSE() const
{
    return mDecisionSE;
}

i32 System::editMapID() const
{
    return mEditMapID;
}

const std::vector<std::string>& System::elements() const
{
    return mElements;
}

const AudioFile& System::enemyCollapseSE() const
{
    return mEnemyCollapseSE;
}

const AudioFile& System::equipSE() const
{
    return mEquipSE;
}

const AudioFile& System::escapeSE() const
{
    return mEscapeSE;
}

const AudioFile& System::gameoverME() const
{
    return mGameoverME;
}

const std::string& System::gameoverName() const
{
    return mGameoverName;
}

const AudioFile& System::loadSE() const
{
    return mLoadSE;
}

i32 System::magicNumber() const
{
    return mMagicNumber;
}

const std::vector<i32>& System::partyMembers() const
{
    return mPartyMembers;
}

const AudioFile& System::saveSE() const
{
    return mSaveSE;
}

const AudioFile& System::shopSE() const
{
    return mShopSE;
}

i32 System::startMapID() const
{
    return mStartMapID;
}

i32 System::startX() const
{
    return mStartX;
}

i32 System::startY() const
{
    return mStartY;
}

const std::vector<std::string>& System::switches() const
{
    return mSwitches;
}

i32 System::testTroopID() const
{
    return mTestTroopID;
}

const AudioFile& System::titleBGM() const
{
    return mTitleBGM;
}

const std::string& System::titleName() const
{
    return mTitleName;
}

const std::vector<std::string>& System::variables() const
{
    return mVariables;
}

const std::string& System::windowskinName() const
{
    return mWindowskinName;
}
