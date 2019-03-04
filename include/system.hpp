#include "any.hpp"

class AudioFile
{
public:
    AudioFile();
    AudioFile(const Any* any);
    
    void               fromAny(const Any* any);
    const std::string& name() const;
    float              pitch() const;
    float              volume() const;
private:
    std::string        mName;
    float              mPitch;
    float              mVolume;
};

class System
{
public:
    System(const Any* any);

    AudioFile                          actorCollapseSE();
    AudioFile                          battleBGM();
    AudioFile                          battleEndME();
    AudioFile                          battleStartSE();
    std::string                        battleTransition();
    std::string                        battlebackName();
    i32                                battlerHue();
    std::string                        battlerName();
    AudioFile                          buzzerSE();
    AudioFile                          cancelSE();
    AudioFile                          cursorSE();
    AudioFile                          decisionSE();
    i32                                editMapID();
    std::vector<std::string>           elements();
    AudioFile                          enemyCollapseSE();
    AudioFile                          equipSE();
    AudioFile                          escapeSE();
    AudioFile                          gameoverME();
    std::string                        gameoverName();
    AudioFile                          loadSE();
    i32                                magicNumber();
    std::vector<i32>                   partyMembers();
    AudioFile                          saveSE();
    AudioFile                          shopSE();
    i32                                startMapID();
    i32                                startX();
    i32                                startY();
    std::vector<std::string>           switches();
    i32                                testTroopID();
    AudioFile                          titleBGM();
    std::string                        titleName();
    std::vector<std::string>           variables();
    std::string                        windowskinName();

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
};