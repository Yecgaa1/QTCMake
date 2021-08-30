//
// Created by xtx on 2021/8/30.
//


#include "GuoJia.h"

void GuoJia::bloodChangeEvent(int num, sourceOfDamage sourceOfDamage, PlayerID PlayerID) {
    Player::bloodChangeEvent(num, sourceOfDamage, PlayerID);
    MainWindow::connect(w.ui->Yes, &QPushButton::clicked, this, [=] {
        w.ui->tips->setText("是否发动技能 遗计 ?");
        getHandEvent(2);
    });

}
