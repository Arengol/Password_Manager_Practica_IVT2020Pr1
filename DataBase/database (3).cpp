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
        Crypto crypt(cryptoKey);
        QFile f(file);
        f.open(QIODevice::WriteOnly);
        f.write((cryptoKey + "\n").toStdString().c_str());
        for(userData el : Data) f.write((crypt.Crypt(el.userName) + " " + crypt.Crypt(el.userPassword) + "\n").toUtf8()); // Crypto - функция шифрования, принимает QString
        f.close();
}


bool Base::DataBase::LoadDatabase()
{
    Crypto crypt(cryptoKey);
    QFile f(file);
    QStringList lst;
    if(f.open(QIODevice::ReadOnly |QIODevice::Text))
        {
            while(!f.atEnd())
            {
                QString str = f.readLine();
                lst = str.split(" ");
            }

        }
    else return true;
    //this->cryptoKey = lst[0];
    for(int i=1;i<lst.size();i++)
    {
        int symbol;
        for(int j=0;j<lst[i].length();j++)
        {
            if(lst[i][j] == " ")
            {
                symbol = j;
                break;
            }
        }
        QString name = " ";
        QString pass = " ";
        for(int j=0;j<symbol;j++)
        {
            name += lst[i][j];
        }
        for(int j = symbol+1;j<lst[i].length();j++)
        {
            pass += lst[i][j];
        }
        userData d1;
        d1.userName = crypt.Decrypt(name);
        d1.userPassword = crypt.Decrypt(pass);
        Data.push_back(d1);
    }
    f.close();
    return false;
}

