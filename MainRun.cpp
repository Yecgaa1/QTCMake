//
// Created by xtx on 2021/8/11.
//
#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace std;


void MainWindow::run() {

}

int MainWindow::chooseHero()//武将选择
{
    ui->card1->hide();
    ui->card5->hide();

    int heronum[3]={};
    heronum[1]=47;
    QPixmap icon2(tr("resource/hero/47.png"));
    ui->card3->setIcon(icon2);


    heronum[0] = (rand() % (403));
    if (heronum[0] == 47)heronum[0] = (rand() % (403));
    auto path = "resource/hero/" + to_string(heronum[0]) + ".png";
    QPixmap icon1(tr(path.data()));
    ui->card2->setIcon(icon1);

    heronum[2] = (rand() % (403));
    if (heronum[2] == 47 || heronum[0] == heronum[2])heronum[2] = (rand() % (403));
    path = "resource/hero/" + to_string(heronum[2]) + ".png";
    QPixmap icon3(tr(path.data()));
    ui->card4->setIcon(icon3);

    connect(ui->card2,&QPushButton::clicked,this,[=]{
        ui->card2->setEnabled(false);
        cardChooseAnime(true,ui->card2);
        ShowSkill(heronum[0]);
        ui->card2->setEnabled(true);
    });
    connect(ui->card3,&QPushButton::clicked,this,[=]{
        ui->card3->setEnabled(false);
        cardChooseAnime(true,ui->card3);
        ShowSkill(heronum[1]);
        ui->card3->setEnabled(true);
    });
    connect(ui->card4,&QPushButton::clicked,this,[=]{
        ui->card4->setEnabled(false);
        cardChooseAnime(true,ui->card4);
        ShowSkill(heronum[2]);
        ui->card4->setEnabled(true);
    });

    //connect(ui->Yes, SIGNAL(clicked()), this,HeroNum=1);
}
