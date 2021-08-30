//
// Created by xtx on 2021/8/23.
//

#ifndef QTCMAKE_VALUE_H
#define QTCMAKE_VALUE_H

using namespace std;

///玩家ID
enum PlayerID
{
    NoOne=-1,
    OneP=0,
    TwoP=1,
    //ThreeP,
};

///提示类型
enum tipsType
{
    giveUp,
    OutHand
};
///倒计时类型
enum timerType
{
    playingHandTimer,
    choosingHeroTimer,
};
///手牌类型
enum cardSpecies
{
    allKind=0,
    kill=101,
    flash=102,
    peach=103,
    //wine=104,

    impeccable=201,
    outOfNothing=202,
    demolitionOfTheBridgeAcrossTheRiver=203,
    goHandInHand=204,
    southernBarbarianInvasion=205,//南蛮入侵
    allArrows=206,//万箭齐发
    harvest=207,//五谷丰登
    taoyuanEnding=208,//桃园结义
    duel=209,//决斗
    murderWithAKnife=210,//借刀杀人

    reluctantToThinkOfIt=301,//乐不思蜀
    lightning=302,//闪电

    zhugeLiannu=401,//诸葛连弩
    frostArrow=402,//寒冰箭
    zhangBaSnakeSpear=403,//丈八蛇矛
    stoneAxe=404,//贯石斧
    fangTianPaintedHalberd=405,//方天画戟
    unicornBow=406,//麒麟弓

    gossipArray=501,//八卦阵
    niohShield=502,//仁王盾

    minusOneHorse=601,//减一马
    addAHorse=602,//加一马

};
///回合状态机类型
enum roundState
{
    startOfRound=1,//回合开始阶段
    judgmentStage=2,//判定阶段
    drawStage=3,//摸牌阶段
    playStage=4,//出牌阶段
    foldPhase=5,//弃牌阶段
    endOfRound=6,//回合结束阶段
};
///伤害来源类型
enum sourceOfDamage
{
    player,
    scourge,
    None,
};

///游戏中信息
struct info
{
    int playerNum=2;
    PlayerID nowPlayerID;
    roundState nowRoundState;
};

///外部主状态标志类型
enum mainStateEnum
{
    choosingHero,
    playing,
    finishing,
};

extern int nextHandHeap;
extern info gameInfo;
extern mainStateEnum mainState;
extern bool isInit;
#endif //QTCMAKE_VALUE_H
