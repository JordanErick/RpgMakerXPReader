#include "types/system.hpp"

System::System()
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
}

System::System(const Object& object)
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
    if (object.className() != "RPG::System")
        throw std::runtime_error(fmt::format("Invalid class name: {}", object.className()));

    mActorCollapseSE.load(*object["@actor_collapse_se"].as<Object>());
    mBattleBGM.load(*object["@battle_bgm"].as<Object>());
    mBattleEndME.load(*object["@battle_end_me"].as<Object>());
    mBattleStartSE.load(*object["@battle_start_se"].as<Object>());
    mBattleTransition = *object["@battle_transition"].as<std::string>();
    mBattlebackName = *object["@battleback_name"].as<std::string>();
    mBattlerHue = *object["@battler_hue"].as<i32>();
    mBattlerName = *object["@battler_name"].as<std::string>();
    mBuzzerSE.load(*object["@buzzer_se"].as<Object>());
    mCancelSE.load(*object["@cancel_se"].as<Object>());
    mCursorSE.load(*object["@cursor_se"].as<Object>());
    mDecisionSE.load(*object["@decision_se"].as<Object>());
    mEditMapID = *object["@edit_map_id"].as<i32>();

    auto* elements = object["@elements"].as<Array>();
    for (const auto& e : *elements)
        mElements.push_back(*e.as<std::string>());

    mEnemyCollapseSE.load(*object["@enemy_collapse_se"].as<Object>());
    mEquipSE.load(*object["@equip_se"].as<Object>());
    mEscapeSE.load(*object["@escape_se"].as<Object>());
    mGameoverME.load(*object["@gameover_me"].as<Object>());
    mGameoverName = *object["@gameover_name"].as<std::string>();
    mLoadSE.load(*object["@load_se"].as<Object>());
    mMagicNumber = *object["@magic_number"].as<i32>();

    auto* partyMembers = object["@party_members"].as<Array>();
    for (const auto& e : *partyMembers)
        mPartyMembers.push_back(*e.as<i32>());

    mSaveSE.load(*object["@save_se"].as<Object>());
    mShopSE.load(*object["@shop_se"].as<Object>());
    mStartMapID = *object["@start_map_id"].as<i32>();
    mStartX = *object["@start_x"].as<i32>();
    mStartY = *object["@start_y"].as<i32>();

    auto* switches = object["@switches"].as<Array>();
    // Avoid first element which is always a nil
    for(size_t i = 1; i < switches->size(); i++)
        mSwitches.push_back(*(*switches)[i].as<std::string>());

    mTestTroopID = *object["@test_troop_id"].as<i32>();
    mTitleBGM.load(*object["@title_bgm"].as<Object>());
    mTitleName = *object["@title_name"].as<std::string>();

    auto* variables = object["@variables"].as<Array>();
    // Avoid first element which is always a nil
    for (size_t i = 1; i < variables->size(); i++)
        mVariables.push_back(*(*variables)[i].as<std::string>());

    mWindowskinName = *object["@windowskin_name"].as<std::string>();

    auto* words = object["@words"].as<Object>();
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

void to_json(json& j, const System& o)
{
    j = json{
        JSON_SET(ActorCollapseSE),
        JSON_SET(BattleBGM),
        JSON_SET(BattleEndME),
        JSON_SET(BattleStartSE),
        JSON_SET(BattleTransition),
        JSON_SET(BattlebackName),
        JSON_SET(BattlerHue),
        JSON_SET(BattlerName),
        JSON_SET(BuzzerSE),
        JSON_SET(CancelSE),
        JSON_SET(CursorSE),
        JSON_SET(DecisionSE),
        JSON_SET(EditMapID),
        JSON_SET(Elements),
        JSON_SET(EnemyCollapseSE),
        JSON_SET(EquipSE),
        JSON_SET(EscapeSE),
        JSON_SET(GameoverME),
        JSON_SET(GameoverName),
        JSON_SET(LoadSE),
        JSON_SET(MagicNumber),
        JSON_SET(PartyMembers),
        JSON_SET(SaveSE),
        JSON_SET(ShopSE),
        JSON_SET(StartMapID),
        JSON_SET(StartX),
        JSON_SET(StartY),
        JSON_SET(Switches),
        JSON_SET(TestTroopID),
        JSON_SET(TitleBGM),
        JSON_SET(TitleName),
        JSON_SET(Variables),
        JSON_SET(WindowskinName),
        JSON_SET(Words)
    };
}

void from_json(const json& j, System& o)
{
    JSON_GET(ActorCollapseSE);
    JSON_GET(BattleBGM);
    JSON_GET(BattleEndME);
    JSON_GET(BattleStartSE);
    JSON_GET(BattleTransition);
    JSON_GET(BattlebackName);
    JSON_GET(BattlerHue);
    JSON_GET(BattlerName);
    JSON_GET(BuzzerSE);
    JSON_GET(CancelSE);
    JSON_GET(CursorSE);
    JSON_GET(DecisionSE);
    JSON_GET(EditMapID);
    JSON_GET(Elements);
    JSON_GET(EnemyCollapseSE);
    JSON_GET(EquipSE);
    JSON_GET(EscapeSE);
    JSON_GET(GameoverME);
    JSON_GET(GameoverName);
    JSON_GET(LoadSE);
    JSON_GET(MagicNumber);
    JSON_GET(PartyMembers);
    JSON_GET(SaveSE);
    JSON_GET(ShopSE);
    JSON_GET(StartMapID);
    JSON_GET(StartX);
    JSON_GET(StartY);
    JSON_GET(Switches);
    JSON_GET(TestTroopID);
    JSON_GET(TitleBGM);
    JSON_GET(TitleName);
    JSON_GET(Variables);
    JSON_GET(WindowskinName);
    JSON_GET(Words);
}