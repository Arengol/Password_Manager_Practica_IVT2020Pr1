#include "usernamegenerator.h"

Account::Account(QString surname_p, QString name_p, QString patronymic_p,QString birth_p,QString num_p)
{
    surname = surname_p.toStdString();
    name = name_p.toStdString();
    patronymic = patronymic_p.toStdString();
    birth = birth_p.toStdString();
    num = num_p.toStdString();
}
Account::~Account()
{

}

QString Account::Translit()
{
    QString str = QString::fromStdString(name + surname + patronymic);
    QString out = "";
    QString rus[74]={"А", "а", "Б", "б",    "В", "в", "Г", "г", "Ґ", "ґ", "Д", "д", "Е", "е", "Є", "є", "Ж", "ж", "З", "з", "И", "и", "І", "і", "Ї", "ї", "Й", "й", "К", "к",
    "Л", "л", "М", "м", "Н", "н", "О", "о", "П", "п", "Р", "р", "С", "с", "Т", "т", "У", "у", "Ф", "ф", "Х", "х", "Ц", "ц", "Ч", "ч", "Ш", "ш",
    "Щ", "щ", "Ь", "ь", "Ю", "ю", "Я", "я", "Ы", "ы", "Ъ", "ъ", "Ё", "ё", "Э", "э"};

    QString eng[74]={"A", "a", "B", "b",    "V", "v", "G", "g", "G", "g", "D", "d", "E", "e", "E", "E", "Zh", "zh", "Z", "z", "I", "i", "I", "I", "Yi", "yi", "J", "j", "K", "k",
    "L", "l", "M", "m", "N", "n", "O", "o", "P", "p",   "R", "r", "S", "s", "T", "t", "U", "u", "F", "f",   "H", "h", "Ts", "ts", "ch", "ch", "Sh", "sh",
    "Shh", "shh", "'", "'", "Yu", "yu","Ya", "ya", "Y", "y", "", "", "Yo", "yo", "E", "e"};

    for(int i=0;i<str.length();i++)
    {
        QString temp="";
        temp.push_back(str[i]);
        for(int j=0;j<74;j++)
        {
            if(temp == rus[j])
            {
                out+=eng[j];
                break;
            }
        }
        temp.clear();
    }
    return out;
}
QString Account::Translit(int number)
{
    switch (number)
    {
    case 1:
    {
        return Translit();
        break;
    }
    case 2:
    {
        return Translit() + QString::fromStdString(birth);
    }
    case 3:
    {
        return Translit() + QString::fromStdString(num);
    }
    }
}

QString Account::Getsurname()
{
    return QString::fromStdString(surname);
}

QString Account::Getname()
{
    return QString::fromStdString(name);
}

QString Account::Getpatronymic()
{
    return QString::fromStdString(patronymic);
}

QString Account::Getbirth()
{
    return QString::fromStdString(birth);
}

QString Account::Getnum()
{
    return QString::fromStdString(num);
}

void Account::Setsurname(QString value)
{
    surname = value.toStdString();
}

void Account::Setname(QString value)
{
    name = value.toStdString();
}

void Account::Setpatronymic(QString value)
{
    patronymic = value.toStdString();
}

void Account::Setbirth(QString value)
{
    birth = value.toStdString();
}

void Account::SetNum(QString value)
{
    num = value.toStdString();
}

bool Account::Valid_birth()
{
    if(birth.size()==8)
    {
        for(int i=0; i<birth.size(); i++)
        {
            if((birth[i]-'0')>9 && (birth[i]-'0')<0) return true;
        }
        return false;
    }
    else return true;
}

bool Account::Valid_code()
{
    for(int i=0; i<num.size(); i++)
    {
        if((num[i]-'0')>9 && (num[i]-'0')<0) return true;
    }
    return false;
}
