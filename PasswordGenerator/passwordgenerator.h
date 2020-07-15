#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <ctime>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class CPassGen
{
private:
    int length;

public:
    void setLength(int p_length);
    CPassGen();//конструктор по умолчанию
    string getPassword(int pointerPass);//возвращает пароль длинной length
};


#endif // PASSWORDGENERATOR_H
