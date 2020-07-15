#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include <vector>
#include <QFile>
#include <QTextStream>
#include "crypt.h"
namespace Base {
class DataBase
{
private:
    QString file;
    QString cryptoKey;
    struct userData
    {
        QString userName;
        QString userPassword;
    } ContainerUserData;

    std::vector <userData> Data;
public:
    bool LoadDatabase();
    void SaveDatabase();
    void Create (QString userName, QString userPassword);
    void Edit (int pointer, QString userName, QString userPassword);
    void Delete (int pointer);
    QString UserNameGetter(int i);
    QString PasswordGetter(int i);
    int DatabaseSizeGetter();
    QString FileGetter();
    void FileSetter(QString fileOp);
    QString CryptoKeyGetter();
    void CryptoKeySetter(QString cryptoKeyOp);
    void DatabaseSetter();//временный
};
}

#endif // DATABASE_H
