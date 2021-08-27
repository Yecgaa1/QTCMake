//
// Created by xtx on 2021/8/17.
//

#ifndef QTCMAKE_PLAYER_H
#define QTCMAKE_PLAYER_H


#include "main.h"
#include "value.h"
#include "ui_mainwindow.h"
using namespace std;

extern MainWindow w;
extern Hands HandHeap[108];

class Player {

public:


    // 回合事件
    Player(int i, PlayerID P);//主构造函数

    void startOfRoundEvent(PlayerID PlayerID) {
        gameInfo.nowRoundState = judgmentStage;
        isInit = true;
    };//回合开始阶段
    void judgmentStageEvent(PlayerID PlayerID) {
        doJudgmentStage(PlayerID);
        gameInfo.nowRoundState = drawStage;
        isInit = true;
    };//判定阶段
    void drawStageEvent(PlayerID PlayerID) {
        doDrawStage(PlayerID);
        gameInfo.nowRoundState = playStage;
        isInit = true;
    };//摸牌阶段
    void playStageEvent(PlayerID PlayerID) {
        doPlayStage(PlayerID);
        //gameInfo.nowRoundState = foldPhase;
        //isInit = true;
    };//出牌阶段
    void foldPhaseEvent(PlayerID PlayerID) {
        doFoldPhase(PlayerID);
        //gameInfo.nowRoundState = endOfRound;
    };//弃牌阶段
    void endOfRoundEvent(PlayerID PlayerID) {
        gameInfo.nowRoundState = startOfRound;
        if (gameInfo.nowPlayerID == OneP)gameInfo.nowPlayerID = TwoP;
        else gameInfo.nowPlayerID = OneP;
        isInit = true;
    };//回合结束阶段


    //回合中事件
    void getHandEvent(int num);

    void bloodChangeEvent(int num, sourceOfDamage sourceOfDamage = None, Player *player = nullptr);

    void getPlayerHandEvent(Player *player, int num, bool type = false);

    void giveUpHand(Player player, int num, bool type = false);

    //初始化用函数
    //void bloodSetAnime(Player player, PlayerID P);

    //人物参数
    int bloodTop;
    int bloodNow = bloodTop;
    int HandTop = bloodNow;
    vector<Hands> playerHandHeap;
    vector<Hands> judgmentHand;
    QPushButton* headBox;
    PlayerID P;
    int useKillNum = 1;
private:

    void doJudgmentStage(PlayerID PlayerID);

    void doDrawStage(PlayerID PlayerID);

    void doPlayStage(PlayerID PlayerID);

    void doFoldPhase(PlayerID PlayerID);

};


#endif //QTCMAKE_PLAYER_H
