#include "mainwindow.h"
#include <QApplication>
#include <../DataBase/database.h>
#include "windows.h"
int main(int argc, char *argv[])
{
    SetConsoleCP(1251);
    SetConsoleCP(1251);
        SetConsoleOutputCP(1251);SetConsoleOutputCP(1251);
    Base::DataBase mainDatabase;
    QApplication a(argc, argv);
    MainWindow w(nullptr, &mainDatabase);
    w.show();
    return a.exec();
}
