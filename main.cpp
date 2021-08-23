#include "mainwindow.h"


#include <QApplication>
#include "main.h"
//#include "Player.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

using namespace std;

extern Player* playerList[2];

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    playerList[0]=new Player(47,MainWindow::OneP);//-1因为hero组只有从第二个按钮开始的三个
    playerList[1]=new Player(193,MainWindow::TwoP);

    MainWindow w;
    w.show();
    return a.exec();
}

void run()
{
    //playerList.push_back(new Player(w.HeroId));

}




#pragma clang diagnostic pop