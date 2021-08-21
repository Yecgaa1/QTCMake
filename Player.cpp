//
// Created by xtx on 2021/8/17.
//

#include "Player.h"
using namespace std;

vector<Player*> playerList;//玩家对象表


void Player::getHandEvent(int num) {
    for(int i=0;i<num;i++)
    {

        playerHandHeap.push_back(HandHeap[nextHandHeap]);
        nextHandHeap++;
    }
}

void Player::bloodChangeEvent(int num, MainWindow::sourceOfDamage sourceOfDamage, Player* player) {
    this->bloodNow-=num;
    this->HandTop-=num;
}

void Player::giveUpHand(Player player, int num, bool type) {

}

Player::Player(int i) {
    switch(i)
    {
        case 47:
            bloodTop=bloodNow=HandTop=3;
    }
}
