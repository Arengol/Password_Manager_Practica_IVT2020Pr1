#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include <QString>
#include <vector>
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
    void SaveDatabase(QString file, QString cryptoKey);
    void LoadDatabase(QString file, QString cryptoKey);
    void Create (QString userName, QString userPassword);
    void Edit ();
    void Delete (int pointer);
    QString UserNameGetter(int i);
    QString PasswordGetter(int i);
    int DatabaseSizeGetter();
    void DatabaseSetter();

};
}

#endif // DATABASE_H
