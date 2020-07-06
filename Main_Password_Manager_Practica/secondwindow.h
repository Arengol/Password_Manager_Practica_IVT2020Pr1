#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include "../DataBase/database.h"
namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr, Base::DataBase *maiDataPointer=nullptr);
    ~SecondWindow();

private slots:


    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

private:
    Base::DataBase *mainDataPointer;
    Ui::SecondWindow *ui;
    void showTable(unsigned int vectorSize);
};

#endif // SECONDWINDOW_H
