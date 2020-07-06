#include "database.h"
void Base::DataBase::DatabaseSetter() // метод для тэстов(будет вырезан, когда появится метод для чтения из файла)
{
    for (int i =0; i<5; i++)
    {
        ContainerUserData.userName="kk";
        ContainerUserData.userPassword="ll";
        Data.push_back(ContainerUserData);
    }
}

void Base::DataBase::Delete(int pointer)
{
 Data.erase(Data.begin()+pointer);
}

QString Base::DataBase::UserNameGetter(int i)
{
    return Data[i].userName;
}

QString Base::DataBase::PasswordGetter(int i)
{
    return Data[i].userPassword;
}

int Base::DataBase::DatabaseSizeGetter()
{
    return Data.size();
}

void Base::DataBase::Create(QString userName, QString userPassword)
{
    ContainerUserData.userName=userName;
    ContainerUserData.userPassword=userPassword;
    Data.push_back(ContainerUserData);
}
