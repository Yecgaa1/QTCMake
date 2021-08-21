#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QParallelAnimationGroup>
#include <QPushButton>
#include <utility>
#include "./ui_mainwindow.h"
#include <QTimer>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    enum mainStateEnum//主状态机
    {
        choosingHero,
        playing,
        finishing,
    }mainState;
    int HeroId=0;//用户最终选定的英雄
    int chooseHero();




private slots:

    //计时器槽
    void timerWork();
    void timeout();
    void chooseFinish();





private:
    Ui::MainWindow *ui;
    QParallelAnimationGroup *animeGroup;
    QTimer *qtimer=new QTimer();
    int timerTemp=100;//计时器用,代表进度百分比



    enum cardSpecies
    {
        allKind=0,
        kill=101,
        flash=102,
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
            {impeccable,"无懈可击",20,20},
             {outOfNothing,"无中生有",20,20},
            {demolitionOfTheBridgeAcrossTheRiver,"过河拆桥",8,8}
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

    enum tipsType
    {
        giveUp
    };
    enum timerType
    {
        choosingHandTimer,
        choosingHeroTimer,
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

    QPushButton* HandCardGroup[5];

    //英雄选择


    void washCard();

    void paintEvent(QPaintEvent *event);

    //动画
    void cardAllDown();
    void cardChooseAnime(bool single,QPushButton* a,...);//手牌移动动画组,不可加入多个组目前
    void cardUpDown(bool single,QPushButton* a);
    void askChoose(int num,tipsType tipsType,cardSpecies cardSpecies=allKind);
    void timerRun(timerType type,int sec=10);//不得大于20s
    int timeRound=0;//一个周期事件

    //更新tips槽
    void clear();//清空
    void showSkill(int i,QPushButton* a);//技能显示
    void PrepareRoundOfGame();



protected:



    enum sourceOfDamage
    {
        player,
        scourge,
        None,
    };
    struct Hands
    {
        cardSpecies Species;
        string name;
        int id;
    }HandHeap[108];
//摸牌堆
int nextHandHeap=0;


};
#endif // MAINWINDOW_H
