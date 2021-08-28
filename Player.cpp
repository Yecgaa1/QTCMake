//
// Created by xtx on 2021/8/17.
//

#include <iostream>
#include "Player.h"
#include "value.h"
using namespace std;



extern MainWindow w;

Player::Player(int i,PlayerID P) {
    //由于确认是两人游戏了
    //就不写2P以上的背景渲染了

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

void Player::bloodChangeEvent(int num, sourceOfDamage sourceOfDamage,PlayerID PlayerID) {
    this->bloodNow-=num;
    this->HandTop-=num;
    if(bloodNow>=5)
}

void Player::giveUpHand(Player player, int num, bool type) {

}



//void Player::bloodSetAnime(Player player,PlayerID P) {
//    switch (P) {
//        case OneP:
//
//            break;
//        case TwoP:
//            break;
//
//    }
//}
void Player::doJudgmentStage(PlayerID PlayerID)//判定阶段
{
    for(int i=0;i<judgmentHand.size();i++)
    {
        //判定牌逻辑
    }
    judgmentHand.clear();
}

void Player::doDrawStage(PlayerID PlayerID)//摸牌阶段
{
    getHandEvent(2);
}

void Player::doPlayStage(PlayerID PlayerID) {
    w.askChoose(PlayerID,1,OutHand);
}

void Player::doFoldPhase(PlayerID PlayerID) {

}
