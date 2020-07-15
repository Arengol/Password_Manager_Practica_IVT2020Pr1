#ifndef CRYPTO_H
#define CRYPTO_H

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


#endif // CRYPTO_H

