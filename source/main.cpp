#include <QApplication>
#include "headers/PlayerWindow.h"
int main(int argc, char** argv){
    QApplication app(argc, argv);
    PlayerWindow *win = new PlayerWindow();
    return app.exec();
}
