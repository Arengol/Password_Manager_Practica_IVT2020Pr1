#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H
#include <QMessageBox>
#include <QDialog>
#include <../DataBase/database.h>
#include <../PasswordGenerator/passwordgenerator.h>
#include <../UsernameGenerator/usernamegenerator.h>
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

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Base::DataBase *mainDataPointer;
    Ui::SecondWindow *ui;
    void showTable(unsigned int vectorSize);
};

#endif // SECONDWINDOW_H
