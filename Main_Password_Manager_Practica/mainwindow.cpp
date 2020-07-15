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
    if (ui->lineEdit->text() != "" && ui->lineEdit_2->text() != "")
    {
        mainDataPointer->FileSetter(ui->lineEdit->text());
        mainDataPointer->CryptoKeySetter(ui->lineEdit_2->text());
        if(mainDataPointer->LoadDatabase())
        {
            QMessageBox::critical(this,"Ошибка","Неверное имя файла или пароль");
        }
        else
        {
            hide();
            sWindow=new SecondWindow(this,mainDataPointer);
            sWindow->show();
        }
    }
    else
    {
        QMessageBox::critical(this,"Ошибка","Введите путь до файла и пароль");
    }
}

void MainWindow::on_pushButton_clicked()//создать новый файл
{
    if (ui->lineEdit->text() != "" && ui->lineEdit_2->text() != "")
    {
        mainDataPointer->FileSetter(ui->lineEdit->text());
        mainDataPointer->CryptoKeySetter(ui->lineEdit_2->text());
        hide();
        sWindow=new SecondWindow(this,mainDataPointer);
        sWindow->show();
    }
    else
    {
        QMessageBox::critical(this,"Ошибка","Введите путь до файла и пароль");
    }
}



void MainWindow::on_pushButton_3_clicked()
{
    CPassGen passGen;
    passGen.setLength((ui->lineEdit_3->text()).toInt());
    ui->lineEdit_2->insert(QString::fromStdString(passGen.getPassword(3)));
}



void MainWindow::on_pushButton_4_clicked()
{
    CPassGen passGen;
    passGen.setLength((ui->lineEdit_3->text()).toInt());
    ui->lineEdit_2->insert(QString::fromStdString(passGen.getPassword(1)));
}

void MainWindow::on_pushButton_5_clicked()
{
    CPassGen passGen;
    passGen.setLength((ui->lineEdit_3->text()).toInt());
    ui->lineEdit_2->insert(QString::fromStdString(passGen.getPassword(2)));
}

