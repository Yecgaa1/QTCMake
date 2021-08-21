#include "mainwindow.h"


#include <QApplication>
#include "main.h"
//#include "Player.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    w.show();
    w.chooseHero();
    return a.exec();
}

void run()
{
    //playerList.push_back(new Player(w.HeroId));

}




#pragma clang diagnostic pop