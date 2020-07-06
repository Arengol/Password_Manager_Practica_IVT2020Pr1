#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent, Base::DataBase *maiDataPointer) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    mainDataPointer=maiDataPointer;
    showTable(mainDataPointer->DatabaseSizeGetter());
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::showTable(unsigned int i) //функция обновления
{
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(i);
    for(int counter1=0; counter1< ui->tableWidget->rowCount(); counter1++)
        {
            QTableWidgetItem *itmUsername= new QTableWidgetItem(mainDataPointer->UserNameGetter(counter1));
            QTableWidgetItem *itmPassword= new QTableWidgetItem(mainDataPointer->PasswordGetter(counter1));
            ui->tableWidget->setItem(counter1,ui->tableWidget->columnCount()-2,itmUsername);
            ui->tableWidget->setItem(counter1,ui->tableWidget->columnCount()-1,itmPassword);
        }
}

void SecondWindow::on_pushButton_5_clicked()//обновление таблицы
{
    showTable(mainDataPointer->DatabaseSizeGetter());
}

void SecondWindow::on_pushButton_4_clicked()//удаление
{
    mainDataPointer->Delete(ui->tableWidget->currentRow());
}

void SecondWindow::on_pushButton_7_clicked()//редактирование
{
    ui->label_9->setText((QString)(ui->tableWidget->currentRow()+'0'+1));// место для подключения библиотеки
}

void SecondWindow::on_pushButton_clicked() //добавление записей
{
    mainDataPointer->Create("ff","jj");// место для подключения библиотеки
}
