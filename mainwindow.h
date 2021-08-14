#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QParallelAnimationGroup>
#include <QPushButton>
#include "./ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void run();//主程序



private slots:

    //计时器槽
    void start();
    void timeout();

    //更新tips槽
    void clear();//清空
    void ShowSkill(int i);//技能显示



private:
    Ui::MainWindow *ui;
    QParallelAnimationGroup *animeGroup;
    QTimer *qtimer;
    int temp=100;

    enum cardSpecies
    {
        Kill=101,
        Flash=102,
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
    enum roundState
    {
        startOfRound=1,//回合开始阶段
        judgmentStage=2,//判定阶段
        drawStage=3,//摸牌阶段
        playStage=4,//出牌阶段
        foldPhase=5,//弃牌阶段
        endOfRound=6,//回合结束阶段
    };
    enum hero
    {
        guojia=101,
        liubei=102,
    };
    int HeroNum=0;
    QPushButton* HandCardGroup[5]={ui->card1,ui->card2,ui->card3,ui->card4,ui->card5};
    int chooseHero();//英雄选择

    void paintEvent(QPaintEvent *event);

    void cardChooseAnime(bool single,QPushButton* a,...);//手牌移动动画组,不可加入多个组目前
};
#endif // MAINWINDOW_H
