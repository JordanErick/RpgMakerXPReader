#pragma once

#include "audio_file.hpp"

class System
{
public:
                                       System();
                                       System(const Object& object);

    const AudioFile&                   actorCollapseSE() const;
    const AudioFile&                   battleBGM() const;
    const AudioFile&                   battleEndME() const;
    const AudioFile&                   battleStartSE() const;
    const std::string&                 battleTransition() const;
    const std::string&                 battlebackName() const;
    i32                                battlerHue() const;
    const std::string&                 battlerName() const;
    const AudioFile&                   buzzerSE() const;
    const AudioFile&                   cancelSE() const;
    const AudioFile&                   cursorSE() const;
    const AudioFile&                   decisionSE() const;
    i32                                editMapID() const;
    const std::vector<std::string>&    elements() const;
    const AudioFile&                   enemyCollapseSE() const;
    const AudioFile&                   equipSE() const;
    const AudioFile&                   escapeSE() const;
    const AudioFile&                   gameoverME() const;
    const std::string&                 gameoverName() const;
    const AudioFile&                   loadSE() const;
    i32                                magicNumber() const;
    const std::vector<i32>&            partyMembers() const;
    const AudioFile&                   saveSE() const;
    const AudioFile&                   shopSE() const;
    i32                                startMapID() const;
    i32                                startX() const;
    i32                                startY() const;
    const std::vector<std::string>&    switches() const;
    i32                                testTroopID() const;
    const AudioFile&                   titleBGM() const;
    const std::string&                 titleName() const;
    const std::vector<std::string>&    variables() const;
    const std::string&                 windowskinName() const;
private:
    AudioFile                          mActorCollapseSE;
    AudioFile                          mBattleBGM;
    AudioFile                          mBattleEndME;
    AudioFile                          mBattleStartSE;
    std::string                        mBattleTransition;
    std::string                        mBattlebackName;
    i32                                mBattlerHue;
    std::string                        mBattlerName;
    AudioFile                          mBuzzerSE;
    AudioFile                          mCancelSE;
    AudioFile                          mCursorSE;
    AudioFile                          mDecisionSE;
    i32                                mEditMapID;
    std::vector<std::string>           mElements;
    AudioFile                          mEnemyCollapseSE;
    AudioFile                          mEquipSE;
    AudioFile                          mEscapeSE;
    AudioFile                          mGameoverME;
    std::string                        mGameoverName;
    AudioFile                          mLoadSE;
    i32                                mMagicNumber;
    std::vector<i32>                   mPartyMembers;
    AudioFile                          mSaveSE;
    AudioFile                          mShopSE;
    i32                                mStartMapID;
    i32                                mStartX;
    i32                                mStartY;
    std::vector<std::string>           mSwitches;
    i32                                mTestTroopID;
    AudioFile                          mTitleBGM;
    std::string                        mTitleName;
    std::vector<std::string>           mVariables;
    std::string                        mWindowskinName;
    std::map<std::string, std::string> mWords;

    friend void                        to_json(json& j, const System& o);
    friend void                        from_json(const json& j, System& o);
};

void to_json(json& j, const System& o);
void from_json(const json& j, System& o);