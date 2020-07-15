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

QString Base::DataBase::FileGetter()
{
    return file;
}

void Base::DataBase::FileSetter(QString fileOp)
{
    file=fileOp;
}

QString Base::DataBase::CryptoKeyGetter()
{
    return cryptoKey;
}

void Base::DataBase::CryptoKeySetter(QString cryptoKeyOp)
{
   cryptoKey=cryptoKeyOp;
}

void Base::DataBase::Edit(int pointer, QString userName, QString userPassword)
{
    Data[pointer].userName=userName;
    Data[pointer].userPassword=userPassword;
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

void Base::DataBase::SaveDatabase()
{
    Crypto crypter(cryptoKey);
    QFile outputfile (file);
    if(outputfile.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&outputfile);
        stream<<crypter.Crypt(cryptoKey)<<'\n';
        for(int i=0; i<Data.size();i++)
        {
            stream<<crypter.Crypt(Data[i].userName)<<'\n';
            stream<<crypter.Crypt(Data[i].userPassword)<<'\n';
        }
    }
    outputfile.close();
}

bool Base::DataBase::LoadDatabase()
{
    Crypto crypter(cryptoKey);
    QFile inputfile (file);
    if(inputfile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&inputfile);
        QString tempKey=crypter.Decrypt(stream.readLine());
        if(tempKey==cryptoKey)
        {
            while (!stream.atEnd())
            {
                ContainerUserData.userName=crypter.Decrypt(stream.readLine());
                ContainerUserData.userPassword=crypter.Decrypt(stream.readLine());
                Data.push_back(ContainerUserData);
            }
        }
        else {inputfile.close(); return true;}
    }
    else {inputfile.close(); return true;}
    inputfile.close();
    return false;
}


