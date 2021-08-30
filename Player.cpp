// player主函数
// Created by xtx on 2021/8/17.
//

#include <iostream>
#include "Player.h"
#include "value.h"
using namespace std;



extern MainWindow w;
/// player构造函数
/// \param i 英雄id
/// \param P 玩家id
/// \param blood 前端对应的玩家血量的血量条的控件指针(测试)
Player::Player(int i,PlayerID P,QLabel* blood[5]) {
    //由于确认是两人游戏了
    //就不写2P以上的背景渲染了
    memcpy(this->blood,blood,20);
    this->P=P;
    switch(i)
    {
        case 47:
            bloodTop=bloodNow=HandTop=3;
            break;
        case 193:
            bloodTop=bloodNow=HandTop=4;
            break;
    }
    switch(P)
    {

        case OneP:
            break;
        case TwoP:
            break;
    }
}
/// 获得牌
/// \param num 数量
void Player::getHandEvent(int num) {
    for(int i=0;i<num;i++)
    {
        //Hands tmp={HandHeap[nextHandHeap].Species,HandHeap[nextHandHeap].name,HandHeap[nextHandHeap].id};
//        Hands t;
//        t.Species=HandHeap[nextHandHeap].Species;
//        t.name=HandHeap[nextHandHeap].name;
//        t.id=HandHeap[nextHandHeap].id;
        this->playerHandHeap.push_back(HandHeap[nextHandHeap]);
        nextHandHeap++;
    }
    if(this->P==OneP)
    {
        w.repaintHands();
    }
}
/// 血量改变函数
/// \param num 数量(默认为减)
/// \param sourceOfDamage 伤害来源(默认为无)
/// \param PlayerID 如果来源于玩家,来源玩家(默认为无)
void Player::bloodChangeEvent(int num, sourceOfDamage sourceOfDamage,PlayerID PlayerID) {
    this->bloodNow-=num;
    this->HandTop-=num;
    if(bloodNow>=5)blood[4]->show();
    else blood[4]->hide();
    if(bloodNow>=4)blood[3]->show();
    else blood[3]->hide();
    if(bloodNow>=3)blood[2]->show();
    else blood[2]->hide();
    if(bloodNow>=2)blood[1]->show();
    else blood[1]->hide();
    if(bloodNow>=1)blood[0]->show();
    else blood[0]->hide();
}
/// 要求弃牌事件
/// \param player 弃牌事件来源
/// \param num 数量
/// \param cardSpecies 手牌类型
void Player::giveUpHand(Player player, int num, cardSpecies type) {

}
/// 判定阶段默认操作
/// \param PlayerID 玩家ID

void Player::doJudgmentStage(PlayerID PlayerID)//判定阶段
{
    for(int i=0;i<judgmentHand.size();i++)
    {
        //判定牌逻辑
    }
    judgmentHand.clear();
}
/// 摸牌阶段默认操作
/// \param PlayerID 玩家ID
void Player::doDrawStage(PlayerID PlayerID)//摸牌阶段
{
    getHandEvent(2);
}
/// 出牌阶段默认操作
/// \param PlayerID 玩家ID
void Player::doPlayStage(PlayerID PlayerID) {

    w.askChoose(PlayerID,1,OutHand);
}
/// 弃牌阶段默认操作
/// \param PlayerID 玩家ID
void Player::doFoldPhase(PlayerID PlayerID) {
    int i=playerHandHeap.size()-bloodNow;
    if(i<=0)
    {
        //不用弃牌
        isInit = true;
        gameInfo.nowRoundState = endOfRound;
    }
    w.askChoose(PlayerID,i,giveUp);
}
