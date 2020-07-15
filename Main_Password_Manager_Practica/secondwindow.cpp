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
    int tablePointer=ui->tableWidget->currentRow();
    Account usernameGenerator
    (
        ui->lineEdit->text(),
        ui->lineEdit_2->text(),
        ui->lineEdit_3->text(),
        ui->lineEdit_4->text(),
        ui->lineEdit_5->text()
     );
    if(usernameGenerator.Valid_code())
    {
        QMessageBox::critical(this,"Ошибка","Неверный формат кода отдела");
        return;
    }
    if(usernameGenerator.Valid_birth())
    {
        QMessageBox::critical(this,"Ошибка","Неверный формат даты рождения");
        return;
    }
    if(ui->radioButton->isChecked())
    {
        QTableWidgetItem *itmUsername= new QTableWidgetItem(usernameGenerator.Translit(1));
        QTableWidgetItem *itmPassword= new QTableWidgetItem(ui->lineEdit_6->text());
        ui->tableWidget->setItem(tablePointer,ui->tableWidget->columnCount()-2,itmUsername);
        ui->tableWidget->setItem(tablePointer,ui->tableWidget->columnCount()-1,itmPassword);
        mainDataPointer->Edit(tablePointer, usernameGenerator.Translit(1), ui->lineEdit_6->text());
    }
    if(ui->radioButton_3->isChecked())
    {
        QTableWidgetItem *itmUsername= new QTableWidgetItem(usernameGenerator.Translit(2));
        QTableWidgetItem *itmPassword= new QTableWidgetItem(ui->lineEdit_6->text());
        ui->tableWidget->setItem(tablePointer,ui->tableWidget->columnCount()-2,itmUsername);
        ui->tableWidget->setItem(tablePointer,ui->tableWidget->columnCount()-1,itmPassword);
        mainDataPointer->Edit(tablePointer, usernameGenerator.Translit(2), ui->lineEdit_6->text());
    }
    if(ui->radioButton_2->isChecked())
    {
        QTableWidgetItem *itmUsername= new QTableWidgetItem(usernameGenerator.Translit(3));
        QTableWidgetItem *itmPassword= new QTableWidgetItem(ui->lineEdit_6->text());
        ui->tableWidget->setItem(tablePointer,ui->tableWidget->columnCount()-2,itmUsername);
        ui->tableWidget->setItem(tablePointer,ui->tableWidget->columnCount()-1,itmPassword);
        mainDataPointer->Edit(tablePointer, usernameGenerator.Translit(3), ui->lineEdit_6->text());
    }
    if(
            !(ui->radioButton->isChecked())
            &&
            !(ui->radioButton_2->isChecked())
            &&
            !(ui->radioButton_3->isChecked())
      )
      QMessageBox::critical(this,"Ошибка","Выберете вариант генерации учетного имени");
}

void SecondWindow::on_pushButton_clicked() //добавление записей
{
    Account usernameGenerator
    (
        ui->lineEdit->text(),
        ui->lineEdit_2->text(),
        ui->lineEdit_3->text(),
        ui->lineEdit_4->text(),
        ui->lineEdit_5->text()
     );
    if(usernameGenerator.Valid_code())
    {
        QMessageBox::critical(this,"Ошибка","Неверный формат кода отдела");
        return;
    }
    if(usernameGenerator.Valid_birth())
    {
        QMessageBox::critical(this,"Ошибка","Неверный формат даты рождения");
        return;
    }
    if(ui->radioButton->isChecked()) mainDataPointer->Create(usernameGenerator.Translit(1),ui->lineEdit_6->text());
    if(ui->radioButton_3->isChecked()) mainDataPointer->Create(usernameGenerator.Translit(2),ui->lineEdit_6->text());
    if(ui->radioButton_2->isChecked()) mainDataPointer->Create(usernameGenerator.Translit(3),ui->lineEdit_6->text());
    if(
            !(ui->radioButton->isChecked())
            &&
            !(ui->radioButton_2->isChecked())
            &&
            !(ui->radioButton_3->isChecked())
      )
      QMessageBox::critical(this,"Ошибка","Выберете вариант генерации учетного имени");
}

void SecondWindow::on_pushButton_6_clicked() //сохранение
{   
    mainDataPointer->SaveDatabase();
}

void SecondWindow::on_pushButton_2_clicked()
{
    CPassGen passGen;
    passGen.setLength((ui->lineEdit_11->text()).toInt());
    ui->lineEdit_6->insert(QString::fromStdString(passGen.getPassword(1)));
}

void SecondWindow::on_pushButton_8_clicked()
{
    CPassGen passGen;
    passGen.setLength((ui->lineEdit_11->text()).toInt());
    ui->lineEdit_6->insert(QString::fromStdString(passGen.getPassword(2)));
}

void SecondWindow::on_pushButton_9_clicked()
{
    CPassGen passGen;
    passGen.setLength((ui->lineEdit_11->text()).toInt());
    ui->lineEdit_6->insert(QString::fromStdString(passGen.getPassword(3)));
}
