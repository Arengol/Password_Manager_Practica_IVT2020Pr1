#include "crypto.h"

Crypto::Crypto(QString startKey)
{
    std::string temp=startKey.toStdString();
    int keySum=0;
    for (int i = 0; i<temp.size();i++)
    {
        keySum+=(int)temp[i]*i;
    }
    srand(keySum);
    for (int i = 0; i<94; i++)
    {
        table[0][i]=i;
    }
    for (int i = 0; i < rand() % 475 + 95; i++) //перемешиваем числовой ряд
    {
        int pos = rand() % 94 +0;
        int pos2 = rand() % 94 +0;
        int buf = table[0][pos];
        table[0][pos] = table[0][pos2];
        table[0][pos2] = buf;
    }
    for (int i = 0; i<94; i++) //соединяем ячейки 2 рядов. На пример table[0][0]=5 table[1][5]=0
    {
        table[1][(table[0][i])]=i;
    }
}

Crypto::~Crypto()
{

}

QString Crypto::Crypt(QString text)
{
    std::string result=text.toStdString();
    for(int i=0;i<result.size();i++)
    {
        result[i]=(char)((table[0][(int)(result[i])-33])+33);
    }
    return QString::fromStdString(result);
}

QString Crypto::Decrypt(QString text)
{
    std::string result=text.toStdString();
    for(int i=0;i<result.size();i++)
    {
        result[i]=(char)((table[1][(int)(result[i])-33])+33);
    }
    return QString::fromStdString(result);
}
