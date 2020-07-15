#ifndef USERNAMEGENERATOR_H
#define USERNAMEGENERATOR_H
#include <QString>
#include <string>
class Account
{
private:
    std::string surname;
    std::string name;
    std::string patronymic;
    std::string birth;
    std::string num;
    QString Translit();
public:
    bool Valid_code();
    bool Valid_birth();
    QString Translit(int);
    Account (QString surname_p, QString name_p, QString patronymic_p,QString birth_p,QString num_p);
    ~Account();
    QString Getsurname();
    QString Getname();
    QString Getpatronymic();
    QString Getbirth();
    QString Getnum();
    void Setsurname(QString value);
    void Setname(QString value);
    void Setpatronymic(QString value);
    void Setbirth(QString value);
    void SetNum(QString value);
};

#endif // USERNAMEGENERATOR_H
