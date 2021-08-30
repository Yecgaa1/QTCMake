#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define PLAYERNUM 2
#include <QMainWindow>
#include <QParallelAnimationGroup>
#include <QPushButton>
#include <utility>
#include "./ui_mainwindow.h"
#include "value.h"
#include <QTimer>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT





//void changeOpacity();等待重写为模板函数

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;

    int HeroId=0;//用户最终选定的英雄
    void chooseHero();
    void repaintHands();//手牌重绘,仅可用于对手牌而不是武将牌
    void askChoose(PlayerID PlayerID,int num,tipsType tipsType,cardSpecies cardSpecies=allKind);
    void chooseFinish(vector<int> a={});
    void exitGame();




private slots:

    //计时器槽
    void timerWork();

    void timeout();

    void PrepareRoundOfGame();
    void MainStateMachine();//主状态机





private:
    QParallelAnimationGroup *animeGroup;
    QTimer *qtimer=new QTimer();
    int timerTemp=100;//计时器用,代表进度百分比

    //主状态机用
    QTimer *MainStateTimer=new QTimer();

    //手牌大小(为了迎合手牌和英雄牌大小区别的问题)
    int width=250,height=292;

    struct cardLib
    {
        cardSpecies Species;
        string name;
        int num;
        int last;//洗牌前需要校验数量
    };
    cardLib allCardLib[100]={
            {kill,"杀",20,20},
            {flash,"闪",20,20},
            {peach,"桃",20,20},
            {goHandInHand,"顺手牵羊",20,20},
             {outOfNothing,"无中生有",20,20},
            {demolitionOfTheBridgeAcrossTheRiver,"过河拆桥",8,8}
                           };

    timerType timerNowType;
    int HeroNum=0;

    struct HandTmpListNode
    {
        cardSpecies Species;
        string name;
        int id;//对全部顺序手牌来说的id
        HandTmpListNode *next;
        HandTmpListNode() : next(nullptr) {};
        HandTmpListNode(cardSpecies Species, string name,int id) : Species(Species), name(std::move(name)),id(id),next(nullptr){}
    };

    vector<QPushButton*> HandCardGroup;



    void washCard();

    void paintEvent(QPaintEvent *event);

    //动画
    int timeRound=0;//一个周期事件
    void cardAllDown(int hasAnimeHands[15]);
    void cardChooseAnime(int topNum,QPushButton* a);//手牌移动动画组,不可加入多个组目前
    void cardUpDown(int hasAnimeHands[15], int upHandNum);
    void setHandLevel();
    void disconnectHands();
    void askChooseAnime(PlayerID PlayerID,void (MainWindow::*Function)(int i),bool isDistanceCheck=false);
    void handsToCenter();

    void timerRun(timerType type,int sec=10);//不得大于20s



    //更新tips槽
    void clear();//清空
    void showSkill(int i,QPushButton* a);//技能显示
    void finishHeroChoose();

    void callHandFunction(PlayerID PlayerID,int HandsID,void (MainWindow::*handFunction)());//回调牌功能
    //各手牌功能回调函数
    void function_kill();

    void getDistance(PlayerID PlayerFrom,PlayerID PlayerTo);


};

typedef void (MainWindow::*handFunction)();

struct Hands
{
    cardSpecies Species;
    string name;
    int id;
    //下面为可选数据点
    handFunction handFunction;
    bool isUseInPlayingRound=false;
    //Hands(cardSpecies Species, string name,int id) : Species(Species), name(std::move(name)),id(id){}
};

#endif // MAINWINDOW_H
