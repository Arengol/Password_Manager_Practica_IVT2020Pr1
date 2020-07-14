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
    string pass;
    int length;

public:
    void setLength(int p_length);
    void setNumber(int p_number);
    CPassGen();//конструктор по умолчанию
    string getPassword(int pointerPass);//возвращает пароль длинной length
};


#endif // PASSWORDGENERATOR_H
