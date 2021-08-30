//
// Created by xtx on 2021/8/30.
//

#ifndef QTCMAKE_GUOJIA_H
#define QTCMAKE_GUOJIA_H


#include "Player.h"

class GuoJia: public Player, public QMainWindow { ;
    void bloodChangeEvent(int num, sourceOfDamage sourceOfDamage, PlayerID PlayerID) override;

public:
    GuoJia(int i,PlayerID P,QLabel* blood[5]):Player(i,P,blood){}
};


#endif //QTCMAKE_GUOJIA_H
