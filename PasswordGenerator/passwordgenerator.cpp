#include "passwordgenerator.h"

CPassGen::CPassGen()
{
    srand(time(0));//установка начального значения генератора случайных чисел
}

void CPassGen::setLength(int p_length)
{
    length = p_length;
}

string CPassGen::getPassword(int pointerPass)
{
    string password = "";
    switch (pointerPass)
    {
        case 1:
        for (int i = 0; i < length; i++)
            password += char('0' + rand() % ('9' - '0'));
        break;
        case 2:
        for (int i = 0; i < length; i++)
            password += char('a' + rand() % ('z' - 'a'));
        break;
        case 3:
        for (int i = 0; i < length; i++)
            password += char('0' + rand() %('z' - '0'));
        break;

    }
    return password;
}

