//
// Created by xtx on 2021/8/17.
//

#include <iostream>
#include "Player.h"
using namespace std;

Player* playerList[2];//玩家对象表


void Player::getHandEvent(int num) {
    for(int i=0;i<num;i++)
    {
        //Hands tmp={HandHeap[nextHandHeap].Species,HandHeap[nextHandHeap].name,HandHeap[nextHandHeap].id};
        Hands t;
        t.Species=HandHeap[nextHandHeap].Species;
        t.name=HandHeap[nextHandHeap].name;
        t.id=HandHeap[nextHandHeap].id;
        this->playerHandHeap.push_back(t);
        nextHandHeap++;
    }
    if(this->P==OneP)
    {
        repaintHands();
    }
}

void Player::bloodChangeEvent(int num, MainWindow::sourceOfDamage sourceOfDamage, Player* player) {
    this->bloodNow-=num;
    this->HandTop-=num;
}

void Player::giveUpHand(Player player, int num, bool type) {

}

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
