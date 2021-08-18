#include "mainwindow.h"
#include "Player.h"

#include <QApplication>
#include "main.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    w.show();
    a.exec();
    w.chooseHero();
    w.update();
    while(true)//主状态机运作
    {
        switch(w.mainState)
        {

            case MainWindow::choosingHero:
                break;
            case MainWindow::playing:

                break;
            case MainWindow::finishing:
                break;
        }
    }


    return 0;
}

void run()
{
    //playerList.push_back(new Player(w.HeroId));

}




#pragma clang diagnostic pop