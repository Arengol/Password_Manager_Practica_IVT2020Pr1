#ifndef CRYPT_H
#define CRYPT_H


#include <QString>
#include <vector>
class Crypto
{
    int table [2][94];

public:
    Crypto(QString startKey);
    QString Crypt(QString text);
    QString Decrypt(QString text);
    void mixer();
    ~Crypto();
};

#endif // CRYPT_H
