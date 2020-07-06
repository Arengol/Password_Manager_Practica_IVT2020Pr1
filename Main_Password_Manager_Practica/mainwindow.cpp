#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent, Base::DataBase *maiDataPointer)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    mainDataPointer=maiDataPointer;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()//открыть
{
    if (ui->lineEdit->text()!=""&&ui->lineEdit_2->text()!="")
    {
        hide();
        sWindow=new SecondWindow(this,mainDataPointer);
        sWindow->show();
    }
    else
    {
        QMessageBox::critical(this,"Ошибка","Введите путь до файла и пароль");
    }
}

void MainWindow::on_pushButton_clicked()//создать новый файл
{
    if (ui->lineEdit->text()!=""&&ui->lineEdit_2->text()!="")
    {
        QMessageBox::about(this,"","Файл создан");
    }
    else
    {
        QMessageBox::critical(this,"Ошибка","Введите путь до файла и пароль");
    }
}
