#include "..\include\system.hpp"

AudioFile::AudioFile()
: mName{""}
, mPitch{100.f}
, mVolume{100.f}
{
}

AudioFile::AudioFile(const Any* any)
: mName{""}
, mPitch{100.f}
, mVolume{100.f}
{
    fromAny(any);
}

void AudioFile::fromAny(const Any* any)
{
    if (any->type() != Type::Object)
        throw std::runtime_error(fmt::format("Invalid any type: {}", any->type()));

    if (any->as<Object>()->className() != "RPG::AudioFile")
        throw std::runtime_error(fmt::format("Invalid class name: {}", any->as<Object>()->className()));

    auto* object = any->as<Object>();

    mName = *(*object)["@name"].as<std::string>();
    mPitch = static_cast<float>(*(*object)["@pitch"].as<i32>());
    mVolume = static_cast<float>(*(*object)["@volume"].as<i32>());
}

const std::string & AudioFile::name() const
{
    return mName;
}

float AudioFile::pitch() const
{
    return mPitch;
}

float AudioFile::volume() const
{
    return mVolume;
}

System::System(const Any * any)
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

AudioFile System::actorCollapseSE()
{
    return mActorCollapseSE;
}

AudioFile System::battleBGM()
{
    return mBattleBGM;
}

AudioFile System::battleEndME()
{
    return mBattleEndME;
}

AudioFile System::battleStartSE()
{
    return mBattleStartSE;
}

std::string System::battleTransition()
{
    return mBattleTransition;
}

std::string System::battlebackName()
{
    return mBattlebackName;
}

i32 System::battlerHue()
{
    return mBattlerHue;
}

std::string System::battlerName()
{
    return mBattlerName;
}

AudioFile System::buzzerSE()
{
    return mBuzzerSE;
}

AudioFile System::cancelSE()
{
    return mCancelSE;
}

AudioFile System::cursorSE()
{
    return mCursorSE;
}

AudioFile System::decisionSE()
{
    return mDecisionSE;
}

i32 System::editMapID()
{
    return mEditMapID;
}

std::vector<std::string> System::elements()
{
    return mElements;
}

AudioFile System::enemyCollapseSE()
{
    return mEnemyCollapseSE;
}

AudioFile System::equipSE()
{
    return mEquipSE;
}

AudioFile System::escapeSE()
{
    return mEscapeSE;
}

AudioFile System::gameoverME()
{
    return mGameoverME;
}

std::string System::gameoverName()
{
    return mGameoverName;
}

AudioFile System::loadSE()
{
    return mLoadSE;
}

i32 System::magicNumber()
{
    return mMagicNumber;
}

std::vector<i32> System::partyMembers()
{
    return mPartyMembers;
}

AudioFile System::saveSE()
{
    return mSaveSE;
}

AudioFile System::shopSE()
{
    return mShopSE;
}

i32 System::startMapID()
{
    return mStartMapID;
}

i32 System::startX()
{
    return mStartX;
}

i32 System::startY()
{
    return mStartY;
}

std::vector<std::string> System::switches()
{
    return mSwitches;
}

i32 System::testTroopID()
{
    return mTestTroopID;
}

AudioFile System::titleBGM()
{
    return mTitleBGM;
}

std::string System::titleName()
{
    return mTitleName;
}

std::vector<std::string> System::variables()
{
    return mVariables;
}

std::string System::windowskinName()
{
    return mWindowskinName;
}
