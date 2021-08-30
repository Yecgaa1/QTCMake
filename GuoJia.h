//
// Created by xtx on 2021/8/30.
//

#ifndef QTCMAKE_GUOJIA_H
#define QTCMAKE_GUOJIA_H


#include "Player.h"

class GuoJia: Player, public QMainWindow {
    void bloodChangeEvent(int num, sourceOfDamage sourceOfDamage, PlayerID PlayerID) override;

};


#endif //QTCMAKE_GUOJIA_H
