#include "mainwindow.h"
#include <QApplication>
#include "../DataBase/database.h"
int main(int argc, char *argv[])
{
    Base::DataBase mainDatabase;
    mainDatabase.DatabaseSetter();
    QApplication a(argc, argv);
    MainWindow w(nullptr, &mainDatabase);
    w.show();
    return a.exec();
}
