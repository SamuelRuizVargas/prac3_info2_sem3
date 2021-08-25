#ifndef USUARIOS_H
#define USUARIOS_H
#include <iostream>

using namespace std;

class usuarios
{
private:
    string cc;
    string clave;
    float saldo;

public:
    usuarios(string, string, float);
    string getCC();
    string getClave();
    float getSaldo();
    ~usuarios();
};

#endif // USUARIOS_H
